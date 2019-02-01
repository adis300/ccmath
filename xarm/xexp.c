/*  xexp.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "xpre.h"
struct xpr xexp(struct xpr z)
{ struct xpr s,d,f; int m,k;
  if(neg(&z)) m=1; else m=0;
  z=sfmod(z,&k); if(m) k= -k;
  if(xex(&z)> -bias){
    z=xpr2(z,-1); s=xmul(z,z); f=zero;
    for(d=inttox(m=ms_exp); m>1 ;){
      f=xdiv(s,xadd(d,f,0)); d=inttox(m-=2); }
    f=xdiv(z,xadd(d,f,0));
    f=xdiv(xadd(d,f,0),xadd(d,f,1));
   }
  else f=one;
  if(k) return xmul(f,xpwr(ee,k)); else return f;
}
