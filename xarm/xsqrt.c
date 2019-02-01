/*  xsqrt.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "xpre.h"
#include <math.h>
struct xpr xsqrt(struct xpr z)
{ struct xpr s,h; short m,e; unsigned short *pc;
  if(neg(&z)){ printf("xsqrt range error\n"); return zero;}
  pc=(unsigned short *)&z;
  if(*pc==0) return zero;
  e= *pc-bias; *pc=bias+(e%2); e/=2;
  s=dubtox(sqrt(xtodub(z)));
  for(m=0; m<itt_div ;++m){
    h=xdiv(xadd(z,xmul(s,s),1),xpr2(s,1));
    s=xadd(s,h,0); }
  pc=(unsigned short *)&s; *pc+=e;
  return s;
}
