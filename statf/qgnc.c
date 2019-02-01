/*  qgnc.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
double qgnc(double x,double a,double d)
{ double r,s,t,f,sp,qgama(double,double),gaml(double); int k;
  r=exp(-d); t=exp(a*log(x)-x-gaml(a))/a;
  f=s=qgama(x,a);
  for(k=1,sp=0.; s*r>1.e-12 || s>sp ;++k){
    sp=s; s=d*(t+s)/k; f+=s; t*=d*x/(k*(a+k)); }
  return r*f;
}
