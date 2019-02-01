/*  jspbes.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
double jspbes(int n,double x)
{ double y,s,t,v,u,a0=1.57079632679490;
  double gaml(double a); int p,m;
  if(x==0.){ if(n==0) return 1.; else return 0.;}
  v=n+.5; y=1.+.68*n;
  if(x<y){ x/=2.; m=x;
    s=t=exp(n*log(x)-gaml(v+1.))*sqrt(a0/2.);
    for(p=1,x*=x;;++p){
      t*= -x/(p*(v+=1.)); s+=t;
      if(p>m && fabs(t)<1.e-13*fabs(s)) break; }
   }
  else{ s=t=1./x; x*=2.; u=0.;
    for(p=1,y=.5; y<v ;++p,y+=1.){
      t*=(v+y)*(v-y)/(p*x);
      if(!(p&1)){ t= -t; s+=t;} else u-=t; }
    y=x/2.-(v+.5)*a0; s=cos(y)*s+sin(y)*u;
   }
  return s;
}
