/*  gsng2.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
static double ze=1.e-15;
double gsng2(double *pa,double *pb,double *pc,double b,
		double an,double bn)
{ double r,s,t,ta,tb,u;
  r= *pa- *pb; u=b* *pc; s=1.-u; t=b*b-u;
  *pc= *pa; *pa= *pb+r/s; *pb= *pc+r*u/t;
  *pc=(t/=s)/b; t=sqrt(-u*t); r*=(-u/(2.*s*t));
  u=1.-b*b;
  s=sin(bn); tb=t*tan(bn)/sqrt(1.-u*s*s);
  s=sin(an); ta=t*tan(an)/sqrt(1.-u*s*s);
  if(fabs(1.-ta)<ze || fabs(1.-tb)<ze) return HUGE_VAL;
  return r*log(fabs((1.+tb)*(1.-ta)/((1.-tb)*(1.+ta))));
}
