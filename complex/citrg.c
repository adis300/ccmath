/*  citrg.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "complex.h"
struct complex casin(Cpx z)
{ struct complex u;
  u.re=1.; u.im=0.;
  u=csqrt(csub(u,cmul(z,z)));
  u.re-=z.im; u.im+=z.re; z=clog(u);
  u.re=z.im; u.im= -z.re;
  return u;
}
struct complex cacos(Cpx z)
{ struct complex u;
  u.re=1.; u.im=0.;
  u=csqrt(csub(u,cmul(z,z)));
  z.re-=u.im; z.im+=u.re; z=clog(z);
  u.re=z.im; u.im= -z.re;
  return u;
}
struct complex catan(Cpx z)
{ struct complex u;
/*
  int kf;
  if(z.re==0. && z.im<0.) kf=1; else kf=0;
*/
  u.re= -z.im; u.im=z.re; z.re=1.; z.im=0.;
  u=cdiv(cadd(z,u),csub(z,u));
  u=cimu(-.5,clog(u));
/*
  if(kf) u.re= -u.re;
*/
  return u;
}
