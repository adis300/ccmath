/*  qbnc.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
double qbnc(double x,double a,double b,double d)
{ double r,s,t,f,sp; int k;
  double qbeta(double,double,double),gaml(double);
  r=exp(-d); t=gaml(a)+gaml(b)-gaml(a+b);
  t=exp(a*log(x)+b*log(1.-x)-t)/b;
  f=s=qbeta(1.-x,b,a); a-=1.;
  for(k=1,sp=0.; s*r>1.e-12 || s>sp ;++k){
    sp=s; s=d*(s-t)/k; f+=s; t*=d*(1.-x)*(1.+a/(b+k))/k; }
  return 1.-r*f;
}
