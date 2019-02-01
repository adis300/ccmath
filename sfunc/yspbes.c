/*  yspbes.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
double yspbes(int n,double x)
{ double v,y,s,t,u,a0=1.57079632679490; int p;
  v=n+.5; if(x==0.) return HUGE_VAL;
  s=t=1./x; x*=2.; u=0.;
  for(p=1,y=.5; y<v ;++p,y+=1.){
    t*=(v+y)*(v-y)/(p*x);
    if(!(p&1)){ t= -t; s+=t;} else u+=t;
   }
  y=x/2.-(v+.5)*a0; s=sin(y)*s+cos(y)*u;
  return s;
}
