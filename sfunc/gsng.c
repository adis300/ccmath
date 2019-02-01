/*  gsng.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
double gsng(double *pa,double *pb,double *pc,double b,double an)
{ double r,s,t,u;
  r= *pa- *pb; u=b* *pc; s=1.-u; t=b*b-u;
  *pc= *pa; *pa= *pb+r/s; *pb= *pc+r*u/t;
  *pc=(t/=s)/b; t=sqrt(-u*t); r*=(-u/(2.*s*t));
  s=sin(an); u=(1.-b*b)*s*s; t*=tan(an)/sqrt(1.-u);
  if(fabs(1.-t)<1.e-15) return HUGE_VAL;
  return r*log(fabs((1.+t)/(1.-t)));
}
