/*  fchb.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
double fchb(double x,double *a,int m)
{ double *p,y,t,tf,de;
  y=2.*x; t=tf=0.;
  for(p=a+m; p>a ;){ de= *p-- +y*t-tf; tf=t; t=de;}
  return (*p+x*t-tf);
}
