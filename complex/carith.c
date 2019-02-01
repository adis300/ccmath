/*  carith.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "complex.h"
struct complex cmul(Cpx s,Cpx t)
{ double u;
  u=s.re*t.re-s.im*t.im;
  s.im=s.im*t.re+s.re*t.im; s.re=u;
  return s;
}
struct complex cdiv(Cpx s,Cpx t)
{ double u,r;
  r=t.re*t.re+t.im*t.im;
  u=(s.re*t.re+s.im*t.im)/r;
  s.im=(s.im*t.re-s.re*t.im)/r; s.re=u;
  return s;
}
struct complex cadd(Cpx s,Cpx t)
{ s.re+=t.re; s.im+=t.im;
  return s;
}
struct complex csub(Cpx s,Cpx t)
{ s.re-=t.re; s.im-=t.im;
  return s;
}
struct complex crmu(double a,Cpx z)
{ z.re*=a; z.im*=a; return z;
}
struct complex cimu(double b,Cpx z)
{ double u;
  u=z.re*b; z.re= -z.im*b; z.im=u;
  return z;
}
struct complex ccng(Cpx z)
{ z.im= -z.im; return z;
}
struct complex cdef(double r,double i)
{ struct complex s;
  s.re=r; s.im=i; return s;
}
double cabs(Cpx c)
{ return sqrt(c.re*c.re+c.im*c.im);
}
double cnrm(Cpx z)
{ return z.re*z.re+z.im*z.im;
}
