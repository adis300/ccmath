/*  nbes.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
double nbes(double v,double x)
{ double y,s,t,tp,u,f,a0=3.14159265358979;
  double gaml(double r),psi(double r),modf(double r,double *a);
  int p,k,m;
  y=x-8.5; if(y>0.) y*=y; tp=v*v/4.+13.69;
  if(y<tp){ if(x==0.) return HUGE_VAL;
    x/=2.; m=x; u=t=exp(v*log(x)-gaml(v+1.));
    if(modf(v,&y)==0.){ k=y; u*=v;
      f=2.*log(x)-psi(1)-psi(k+1);
      t/=a0; x*= -x; s=f*t;
      for(p=1;;++p){ f-=1./p+1./(v+=1.);
        t*=x/(p*v); s+=(y=t*f); if(p>m && fabs(y)<1.e-13) break; }
      if(k>0){ x= -x; s-=(t=1./(u*a0));
        for(p=1,--k; k>0 ;++p,--k) s-=(t*=x/(p*k)); }
     }
    else{ f=1./(t*v*a0); t/=tan(a0*v); s=t-f;
      for(p=1,x*=x,u=v;;++p){
        t*= -x/(p*(v+=1.)); f*=x/(p*(u-=1.));
        s+=(y=t-f); if(p>m && fabs(y)<1.e-13) break; }
     }
   }
  else{ x*=2.; s=t=2./sqrt(x*a0); u=0.;
    for(p=1,y=.5; (tp=fabs(t))>1.e-14 ;++p,y+=1.){
      t*=(v+y)*(v-y)/(p*x); if(y>v && fabs(t)>tp) break;
      if(!(p&1)){ t= -t; s+=t;} else u+=t;
     }
    y=(x-(v+.5)*a0)/2.; s=sin(y)*s+cos(y)*u;
   }
  return s;
}
