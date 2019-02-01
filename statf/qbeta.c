/*  qbeta.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
double qbeta(double x,double a,double b)
{ double ro,t,ts,f,gaml(double); int nf;
  ro=gaml(a)+gaml(b)-gaml(a+b);
  if(x<.5) nf=1; else{ x=1.-x; t=a; a=b; b=t; nf=0;}
  f=t=exp(a*log(x)+b*log(1.-x)-ro)/a;
  for(ts=0.,b+=a-1.; t>1.e-12 || t>ts ;){
    b+=1.; a+=1.; ts=t; t*=x*b/a; f+=t; }
  if(nf) return f; else return 1.-f;
}
