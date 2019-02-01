/*  biry.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
double biry(double x,int df)
{ double f,y,a,b,s; int p;
  double u=.258819403792807,v=.355028053887817;
  if(x<=7.6 && x>= -6.9){ y=x*x*x/9.;
    if(df){ b= -(a=2./3.); u*=(f=sqrt(3.)); v*=f*x*x/2.;}
    else{ a= -(b=1./3.); v*=(f=sqrt(3.)); u*=f*x;}
    for(p=1,f=u+v;;++p){
      v*=y/(p*(a+=1.)); u*=y/(p*(b+=1.)); f+=(s=u+v);
      if(fabs(s)<1.e-14*(1.+fabs(f))) break; }
   }
  else{ s=1./sqrt(v=3.14159265358979); y=fabs(x);
    if(df) s*=pow(y,.25); else s/=pow(y,.25);
    y*=2.*sqrt(y)/3.; b=.5;
    if(df) a=2./3.; else a=1./3.;
    if(x>0.){ s*=exp(y); f=s; y*= -2.;
      for(p=1; (u=fabs(s))>1.e-14 ;++p,b+=1.){
        s*=(a+b)*(a-b)/(p*y); if(fabs(s)>=u) break; f+=s; }
     }
    else{ x=y-v/4.; y*=2.; f=s; v=0.;
      for(p=1; (u=fabs(s))>1.e-14 ;++p,b+=1.){
        s*=(a+b)*(a-b)/(p*y); if(fabs(s)>=u) break;
        if(!(p&1)){ s= -s; f+=s;} else v+=s; }
      if(df) f=f*cos(x)-v*sin(x); else f= -(f*sin(x)+v*cos(x));
     }
   }
  return f;
}
