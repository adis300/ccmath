/*  xhypb.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "xpre.h"
struct xpr xtanh(struct xpr z)
{ struct xpr s,d,f; int m,k;
  if((k=xex(&z))>k_tanh){
     if(neg(&z)) return xneg(one); else return one;}
  if(k<k_lin) return z; ++k;
  if(k>0) z=xpr2(z,-k); s=xmul(z,z); f=zero;
  for(d=inttox(m=ms_hyp); m>1 ;){
    f=xdiv(s,xadd(d,f,0)); d=inttox(m-=2); }
  f=xdiv(z,xadd(d,f,0));
  for(; k>0 ;--k) f=xdiv(xpr2(f,1),xadd(d,xmul(f,f),0));
  return f;
}
struct xpr xsinh(struct xpr z)
{ int k;
  if((k=xex(&z))<k_lin) return z;
  else if(k<0){ z=xtanh(xpr2(z,-1));
     return xdiv(xpr2(z,1),xadd(one,xmul(z,z),1)); }
  else{ z=xexp(z); return xpr2(xadd(z,xdiv(one,z),1),-1);}
}
struct xpr xcosh(struct xpr z)
{ if(xex(&z)<k_lin) return one;
  z=xexp(z); return xpr2(xadd(z,xdiv(one,z),0),-1);
} 
