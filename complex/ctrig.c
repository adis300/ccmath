/*  ctrig.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "complex.h"
struct complex csin(Cpx z)
{ double c,s,u,v;
/* s=sincos(z.re,&c); */
  s=sin(z.re); c=cos(z.re);
  u=exp(z.im); v=1./u;
  u=ldexp(u+v,-1); v=u-v;
  z.re=u*s; z.im=c*v;
  return z;
}
struct complex ccos(Cpx z)
{ double c,s,u,v;
/* s=sincos(z.re,&c); */
  s=sin(z.re); c=cos(z.re);
  u=exp(z.im); v=1./u;
  u=ldexp(u+v,-1); v=u-v;
  z.re=c*u; z.im= -s*v;
  return z;
}
struct complex ctan(Cpx z)
{ double c,s,u,v,d;
/* s=sincos(z.re,&c); */
  s=sin(z.re); c=cos(z.re);
  u=exp(z.im); v=1./u;
  u=ldexp(u+v,-1); v=u-v;
  d=c*c+v*v; z.re=s*c/d; z.im=u*v/d;
  return z;
}
