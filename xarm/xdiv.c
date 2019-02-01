/*  xdiv.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "xpre.h"
struct xpr xdiv(struct xpr s,struct xpr t)
{ struct xpr a;
  unsigned short *pc,e,i;
  pc=(unsigned short *)&t; e= *pc; *pc=bias;
  a=dubtox(1/xtodub(t)); *pc=e;
  pc=(unsigned short *)&a; *pc+=bias-(e&m_exp); *pc|=e&m_sgn;
  for(i=0; i<itt_div ;++i) a=xmul(a,xadd(two,xmul(a,t),1));
  return xmul(s,a);
}
