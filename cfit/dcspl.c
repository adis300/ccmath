/*  dcspl.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
double dcspl(double x,double *u,double *v,double *z,int m)
{ int i,k; double h,d;
  if(x>u[m] || x<u[0]) return 0.;
  for(i=1; x>u[i] ;++i);
  k=i-1; h=u[i]-u[k];
  x-=u[k]; x/=h;
  d=(v[i]-v[k])/h;
  return d-h*((z[i]-z[k])*(1.-3.*x*x)+z[k]*(3.-6.*x));
}
