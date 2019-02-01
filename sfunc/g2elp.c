/*  g2elp.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
double g2elp(double an,double bn,double k,double as,double bs,double ds)
{ double a,b,d,s,r,f,h; int m=1,q=0;
  double pi=3.14159265358979;
  double gsng2(double *pa,double *pb,double *pc,double b,double an,
		  double bn);
  a=1.; b=sqrt(1.-k*k); r=s=0.;
  if(ds<0.)
    if((r=gsng2(&as,&bs,&ds,b,an,bn))==HUGE_VAL) return r;
  if(an<0.){ an= -an; q=1;}
  while(a-b>1.e-15){ m*=2;
    if((k=atan(b*tan(an)/a))<0.) k+=pi;
    if((k-=fmod(an,pi))>2.) k-=pi; an+=an+k;
    if((k=atan(b*tan(bn)/a))<0.) k+=pi;
    if((k-=fmod(bn,pi))>2.) k-=pi; bn+=bn+k;
    k=a+b; b=sqrt(a*b); a=k/2.;
    d=(as-bs)/(2.*a*m);
    k=as+bs; bs=as+ds*bs; as=k/2.;
    bs/=(k=1.+ds); ds=b*k*k/(4.*a*ds);
    if((f=1.-b*ds/a)>1.e-9){
      d/=2.*(f=sqrt(f)); h=f*sin(bn); f*=sin(an);
      s+=d*log((1.+f)/(1.-f)); r+=d*log((1.+h)/(1.-h)); }
    else if(f< -1.e-9){
      d/=(f=sqrt(-f)); h=f*sin(bn); f*=sin(an);
      s+=d*atan(f); r+=d*atan(h); }
    else{ s+=d*sin(an); r+=d*sin(bn);}
   }
  if(q) return as*(bn+an)/(m*a)+r+s;
  return as*(bn-an)/(m*a)+r-s;
}
