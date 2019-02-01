/*  kbes.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
double kbes(double v,double x)
{ double y,s,t,tp,f,a0=1.57079632679490;
  double gaml(double u),psi(double u),modf(double u,double *v);
  int p,k,m;
  if(x==0.) return HUGE_VAL;
  y=x-10.5; if(y>0.) y*=y; tp=25.+.185*v*v;
  if(y<tp && modf(v+.5,&t)!=0.){ y=1.5+.5*v;
    if(x<y){ x/=2.; m=x; tp=t=exp(v*log(x)-gaml(v+1.));
      if(modf(v,&y)==0.){ k=y; tp*=v;
        f=2.*log(x)-psi(1)-psi(k+1);
        t/=2.; if(!(k&1)) t= -t; s=f*t;
        for(p=1,x*=x;;++p){ f-=1./p+1./(v+=1.);
          t*=x/(p*v); s+=(y=t*f);
          if(p>m && fabs(y)<1.e-14) break; }
        if(k>0){ x= -x; s+=(t=1./(tp*2.));
          for(p=1,--k; k>0 ;++p,--k) s+=(t*=x/(p*k)); }
       }
      else{ f=1./(t*v*2.); t*=a0/sin(2.*a0*v); s=f-t;
        for(p=1,x*=x,tp=v;;++p){
          t*=x/(p*(v+=1.)); f*= -x/(p*(tp-=1.));
          s+=(y=f-t); if(p>m && fabs(y)<1.e-14) break; }
       }
     }
    else{ double tq,h,w,z,r;
      t=12./pow(x,.333); k=t*t; y=2.*(x+k);
      m=v; v-=m; tp=v*v-.25; v+=1.; tq=v*v-.25;
      for(s=h=1.,r=f=z=w=0.; k>0 ;--k,y-=2.){
        t=(y*h-(k+1)*z)/(k-1-tp/k); z=h; f+=(h=t);
        t=(y*s-(k+1)*w)/(k-1-tq/k); w=s; r+=(s=t);  }
      t=sqrt(a0/x)*exp(-x); s*=t/r; h*=t/f; x/=2.; if(m==0) s=h;
      for(k=1; k<m ;++k){ t=v*s/x+h; h=s; s=t; v+=1.;}
     }
   }
  else{ s=t=sqrt(a0/x); x*=2.;
    for(p=1,y=.5; (tp=fabs(t))>1.e-14 ;++p,y+=1.){
      t*=(v+y)*(v-y)/(p*x); if(y>v && fabs(t)>=tp) break; s+=t; }
    s*=exp(-x/2.);
   }
  return s;
}
