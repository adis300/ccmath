/*  pctgn.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
static double te=1.e-9,tb=1.e-32;
double pctgn(double pc,double a,double d)
{ double x,y,t,df,dx; int k;
  double qgnc(double,double,double),pctg(double,double);
  if(pc<te || pc>1.-te) return -1.;
  dx=df=a+d; df*=(dx/=a+2.*d);
  y=pctg(pc,df); x=y/dx; dx=sqrt(a+2.*d)/4.;
  if((y=x-dx)<=0.) y=te;
  t=qgnc(y,a,d); dx=x-y; k=0;
  do{ df=qgnc(x,a,d)-t; t+=df; y=pc-t; ++k;
    dx*=y/df; x+=dx; if(x<=0.) x=tb;
   }while(fabs(y)>te && k<200);
  if(k>=200) return -1.; else return x;
}
