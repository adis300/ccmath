/*  pctbn.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
static double te=1.e-9,tb=1.e-12;
double pctbn(double pc,double a,double b,double d)
{ double x,y,t,df,dx; int k;
  double qbnc(double,double,double,double),pctb(double,double,double);
  if(pc<te || pc>1.-te) return -1.;
  dx=df=b+d; df*=(dx/=b+2.*d);
  y=pctb(pc,a,df); x=y/(y+(1.-y)/dx);
  if((y=x+1.e-4)>1.) y=1.-te;
  t=qbnc(y,a,b,d); dx=x-y; k=0;
  do{ df=qbnc(x,a,b,d)-t; t+=df;
    y=pc-t; dx*=y/df; x+=dx; ++k;
    if(x<=0.) x=tb; else if(x>=1.) x=1.-tb;
   }while(fabs(y)>te && k<200);
  if(k>=200) return -1.; else return x;
}
