/*  pctb.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
static double te=1.e-9;
double pctb(double pc,double a,double b)
{ double x,y,t,s;
  double qbeta(double,double,double),gaml(double),pctn(double);
  int nf,k;
  if(pc<te || pc>1.-te) return -1.;
  if(a>b){ nf= -1; t=a; a=b; b=t; pc=1.-pc;} else nf=1.;
  if(a==.5 && b==.5){ y=sin(pc*asin(1.)); return y*y;}
  else if(a<1.5){
     if(pc>b/(a+b)){ nf= -nf; t=a; a=b; b=t; pc=1.-pc;}
     x=exp((gaml(a+1.)+gaml(b)-gaml(a+b)+log(pc))/a);
     if(x==0.) return -1.;
   }
  else{
     x=pctn(pc); y=1./(a+a-1.); t=1./(b+b-1.);
     s=2./(y+t); t-=y; y=(x*x-3.)/6.; x*=sqrt(s+y)/s;
     x-=t*(y+(5.-4./s)/6.); x=a/(a+b*exp(2.*x));
   }
  y=gaml(a)+gaml(b)-gaml(a+b); k=0;
  do{ s=(a-1.)*log(x)+(b-1.)*log(1.-x)-y;
      t=pc-qbeta(x,a,b); x+=t/exp(s); ++k;
    }
  while(fabs(t)>te && k<200);
  if(k>=200) return -1.;
  if(nf==1.) return x; else return 1.-x;
}
