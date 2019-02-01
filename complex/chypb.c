/*  chypb.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "complex.h"
struct complex csinh(Cpx z)
{ double c,s,u,v;
/*  s=sincos(z.im,&c); */
  s=sin(z.im); c=cos(z.im);
  u=exp(z.re); v=1./u;
  u=ldexp(u+v,-1); v=u-v;
  z.re=v*c; z.im=u*s;
  return z;
}
struct complex ccosh(Cpx z)
{ double c,s,u,v;
/*  s=sincos(z.im,&c); */
  s=sin(z.im); c=cos(z.im);
  u=exp(z.re); v=1./u;
  u=ldexp(u+v,-1); v=u-v;
  z.re=c*u; z.im=v*s;
  return z;
}
struct complex ctanh(Cpx z)
{ double c,s,u,v,d;
/*  s=sincos(z.im,&c); */
  s=sin(z.im); c=cos(z.im);
  u=exp(z.re); v=1./u;
  u=ldexp(u+v,-1); v=u-v;
  d=c*c+v*v; z.re=u*v/d; z.im=s*c/d;
  return z;
}
