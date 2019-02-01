/*  cexp.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "complex.h"
struct complex cexp(Cpx z)
{ double s,c,u;
/* s=sincos(z.im,&c); */ 
  s=sin(z.im); c=cos(z.im);
  u=exp(z.re);
  z.re=u*c; z.im=u*s;
  return z;
}
struct complex clog(Cpx z)
{ double r;
  r=z.re*z.re+z.im*z.im;
  z.im=atan2(z.im,z.re);
  z.re=ldexp(log(r),-1);
  return z;
}
