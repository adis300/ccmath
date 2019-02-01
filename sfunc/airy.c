/*  airy.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
double airy(double x,int df)
{ double f,y,a,b,s; int p;
  double u=.258819403792807,v=.355028053887817;
  if(x<=1.7 && x>= -6.9){ y=x*x*x/9.;
    if(df){ b= -(a=2./3.); v*=x*x/2.; u= -u;}
    else{ a= -(b=1./3.); u*= -x;}
    for(p=1,f=u+v;;++p){
      v*=y/(p*(a+=1.)); u*=y/(p*(b+=1.));
      f+=(s=u+v); if(fabs(s)<1.e-14) break; }
   }
  else{ s=1./sqrt(v=3.14159265358979); y=fabs(x);
    if(df) s*=pow(y,.25); else s/=pow(y,.25);
    y*=2.*sqrt(y)/3.;
    if(x>0.){ a=12./pow(y,.333); p=a*a;
      if(df) a= -7./36.; else a=5./36.;
      b=2.*(p+y); f=1.; u=x=0.; s*=exp(-y)/2.;
      for(; p>0 ;--p,b-=2.){
        y=(b*f-(p+1)*x)/(p-1+a/p); x=f; u+=(f=y); }    
      if(df) f*= -s/u; else f*=s/u;
     }
    else{ x=y-v/4.; y*=2.; b=.5; f=s; v=0.;
      if(df) a=2./3.; else a=1./3.;
      for(p=1; (u=fabs(s))>1.e-14 ;++p,b+=1.){
        s*=(a+b)*(a-b)/(p*y); if(fabs(s)>=u) break;
        if(!(p&1)){ s= -s; f+=s;} else v+=s; }
      if(df) f=f*sin(x)+v*cos(x); else f=f*cos(x)-v*sin(x);
     }
   }
  return f;
}
