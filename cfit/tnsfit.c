/*  tnsfit.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
double tnsfit(double w,double *x,double *y,double *z,int m,double tn)
{ double s,t,u,a=sinh(tn); int j,k;
  if(w<x[0] || w>x[m]) return 0.;
  for(j=1; w>x[j] ;++j); k=j-1;
  t=(w-x[k])/(s=x[j]-x[k]); s*=s/(a-tn); u=1.-t;
  return t*y[j]+u*y[k]+s*(z[j]*(sinh(tn*t)-t*a)+z[k]*(sinh(tn*u)-u*a));
}
