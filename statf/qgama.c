/*  qgama.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
double qgama(double x,double a)
{ double ap,ro,f,t,gaml(double); int k;
  ro=a*log(x)-x-gaml(a);
  ap=6.25; if(a>ap) ap=a; t=(x-ap)/(f=sqrt(2.*ap));
  if(x<4.5 || t< -1. || (t< -.5 && a<10.)){
    for(f=t=1.,ap=a; t>1.e-14 ;){ t*=x/(ap+=1.); f+=t;}
    return 1.-exp(ro)*f/a;
   }
  else{
    if(t<0. && a<10.) k=18;
    else if(t>3.){ k=ceil(19.-3.*t); if(k<4) k=4;}
    else k=6+ceil(f*(2.05-.8*t+.091*t*t));
    for(f=x; k>0 ;){ t=k--; f=x+(t-a)/(1.+t/f);}
    return exp(ro)/f;
   }
}
