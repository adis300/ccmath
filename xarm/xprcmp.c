/*  xprcmp.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "xpre.h"
int xprcmp(struct xpr *pa,struct xpr *pb)
{ unsigned short e,k,*p,*q; int m;
  p=(unsigned short *)pa; e= *p&m_sgn;
  q=(unsigned short *)pb; k= *q&m_sgn;
  if(e && !k) return -1; if(!e && k) return 1;
  if(e) m= -1; else m=1;
  e= *p&m_exp; k= *q&m_exp;
  if(e>k) return m; if(e<k) return -m;
  for(e=0; *++p== *++q && e<XDIM ;++e);
  if(e<XDIM){ if(*p> *q) return m; else return -m;}
  return 0;
}
