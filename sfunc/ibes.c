/*  ibes.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
double ibes(double v,double x)
{ double y,s,t,tp,gaml(double w); int p,m;
  y=x-9.; if(y>0.) y*=y; tp=v*v*.2+25.;
  if(y<tp){ x/=2.; m=x;
    if(x>0.) s=t=exp(v*log(x)-gaml(v+1.));
    else{ if(v>0.) return 0.; else if(v==0.) return 1.;}
    for(p=1,x*=x;;++p){ t*=x/(p*(v+=1.)); s+=t;
      if(p>m && t<1.e-13*s) break;
     }
   }
  else{ double u,a0=1.57079632679490;
    s=t=1./sqrt(x*a0); x*=2.; u=0.;
    for(p=1,y=.5; (tp=fabs(t))>1.e-14 ;++p,y+=1.){
      t*=(v+y)*(v-y)/(p*x); if(y>v && fabs(t)>=tp) break;
      if(!(p&1)) s+=t; else u-=t;
     }
    x/=2.; s=cosh(x)*s+sinh(x)*u;
   }
  return s;
}
