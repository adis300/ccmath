/*  ftch.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
double ftch(double x,double *a,int m,double *b,int n)
{ double *p,y,t,tf,nu,de;
  y=2.*x; t=tf=0.;
  for(p=a+m; p>a ;){ nu= *p-- +y*t-tf; tf=t; t=nu;}
  nu= *p+x*t-tf; t=tf=0.;
  for(p=b+n; p>b ;){ de= *p-- +y*t-tf; tf=t; t=de;}
  de= *p+x*t-tf;
  return nu/de;
}
