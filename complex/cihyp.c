/*  cihyp.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "complex.h"
struct complex casinh(Cpx z)
{ struct complex u;
  u.re=1.; u.im=0.;
  u=csqrt(cadd(u,cmul(z,z)));
  u.re+=z.re; u.im+=z.im;
  return clog(u);
}
struct complex cacosh(Cpx z)
{ struct complex u; int kf;
  if(z.im==0. && z.re< -1.) kf=1; else kf=0;
  u.re=1.; u.im=0.;
  u=csqrt(csub(cmul(z,z),u));
  z.re+=u.re; z.im+=u.im; z=clog(z);
  if(z.re<0.){ z.re= -z.re; z.im= -z.im;}
  if(kf) z.im= -z.im;
  return z;
}
struct complex catanh(Cpx z)
{ struct complex u;
/*
  int kf;
  if(z.im==0. && z.re>1.) kf=1; else kf=0;
*/
  u.re=1.; u.im=0.;
  u=cdiv(cadd(u,z),csub(u,z));
  u=crmu(.5,clog(u));
/*
  if(kf) u.im= -u.im;
*/
  return u;
}
