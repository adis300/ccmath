/*  sfmod.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "xpre.h"
struct xpr sfmod(struct xpr s,int *p)
{ unsigned short *pa,*pb; short e,k;
  pa=(unsigned short *)&s; pb=pa+1;
  e=(*pa&m_exp)-bias;
  if(e>15){ *p= -1; return s;} else if(e<0){ *p=0; return s;}
  *p= *pb>>(15-e); lshift(++e,pb,XDIM); *pa-=e;
  for(e=0; *pb==0 && e<max_p ;++pb,e+=16);
  if(e==max_p) return zero;
  for(k=0; !((*pb<<k)&m_sgn) ;++k);
  if((k+=e)){ lshift(k,pa+1,XDIM); *pa-=k;}
  return s;
}
