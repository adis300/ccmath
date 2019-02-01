/*  csfit.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
double csfit(double w,double *x,double *y,double *z,int m)
{ double s,t; int j,k;
  if(w<x[0] || w>x[m]) return 0.;
  for(j=1; w>x[j] ;++j); k=j-1;
  s=(t=w-x[k])*(x[j]-w); t/=(x[j]-x[k]);
  return (t*y[j]+(1.-t)*y[k]-s*(z[j]*(1.+t)+z[k]*(2.-t)));
}
