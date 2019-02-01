/*  fintg.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
double fintg(double a,double b,int n,double te,double (*func)())
{ int j,k,m; double s,t,x,h,ap[10],*p;
  s=((*func)(b)+(*func)(a))/2.;
  h=(b-a)/n; x=a;
  for(j=1; j<n ;++j) s+=(*func)(x+=h);
  ap[0]=s*h;
  for(m=1;;){ ++m; x=a-h/2.;
    for(j=0; j<n ;++j) s+=(*func)(x+=h);
    t=s*h/2.;
    for(j=k=1,p=ap; j<m ;++j){
      k*=4; x=(t- *p)/(k-1); *p++ =t; t+=x; }
    *p=t;
    if(fabs(x)<te*fabs(t)) return t;
    if(m==10) return pow(2.,126.);
    h/=2.; n*=2;
   }
}
