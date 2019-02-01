/*  pctg.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
static double te=1.e-9;
double pctg(double pc,double a)
{ double x,y,s,t; int k;
  double qgama(double,double),gaml(double),pctn(double);
  if(pc<te || pc>1.-te) return -1.;
  if(a<.5){
    x=exp((gaml(a+1.)+log(1.-pc))/a);
    if(x==0.) return -1.;
   }
  else{
    y=pctn(pc); s=1./(9.*a);
    s=pow(1.-s+y*sqrt(s),3.); x=a*s;
    if(x<te) x=te;
   }
  s=gaml(a); k=0;
  do{ y=exp((a-1.)*log(x)-x-s); t=pc-qgama(x,a);
    x-=t/y; ++k;
   }while(fabs(t)>te && k<200);
  if(k>=200) return -1.; else return x;
}
