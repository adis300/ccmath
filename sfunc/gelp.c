/*  gelp.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
#ifndef NULL
#define NULL ((void *)0)
#endif
double gelp(double an,double k,double as,double bs,double ds,
		 double *pg,double *pf,double *pk)
{ double a,b,d,s,f; int m=1;
  double pi=3.14159265358979;
  double gsng(double *pa,double *pb,double *pc,double b,double an);
  a=1.; b=sqrt(1.-k*k); s=0.;
  if(ds<0.)
    if((s=gsng(&as,&bs,&ds,b,an))==HUGE_VAL) return s;
  while(a-b>1.e-15){ m*=2;
    if((k=atan(b*tan(an)/a))<0.) k+=pi;
    if((k-=fmod(an,pi))>2.) k-=pi;
    an+=an+k; k=a+b; b=sqrt(a*b);
    a=k/2.; d=(as-bs)/(2.*a*m);
    k=as+bs; bs=as+ds*bs; as=k/2.;
    bs/=(k=1.+ds); ds=b*k*k/(4.*a*ds);
    if((f=1.-b*ds/a)>1.e-9){
      d/=2.*(f=sqrt(f)); f*=sin(an);
      s+=d*log((1.+f)/(1.-f));  }
    else if(f< -1.e-9){
      d/=(f=sqrt(-f)); f*=sin(an); s+=d*atan(f); }
    else s+=d*sin(an);
   }
  f=an/(m*a);
  if(pg!=NULL){ k=pi/(2.*a); *pg=as*k;
    if(pf!=NULL){ *pf=f; *pk=k;}
   }
  return as*f+s;
}
