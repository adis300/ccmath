/*  amelp.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
double amelp(double u,double k)
{ double a,b,cs[10]; int m,n=1;
  a=1.; b=sqrt(1.-k*k);
  for(m=0; (k=a-b)>4.e-15 ;++m){
    cs[m]=k/2.; k=a+b; b=sqrt(a*b);
    a=k/2.; cs[m]/=a; n*=2;
   }
  for(u*=n*a,--m; m>=0 ;--m)
    u=(u+asin(cs[m]*sin(u)))/2.;
  return u;
}
