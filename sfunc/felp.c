/*  felp.c    CCMATH mathematics library source code.
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
double felp(double an,double k,double *pk,double *pz,double *ph)
{ double a,b,c,s,h; int m=1;
  double pi=3.14159265358979;
  a=1.; b=sqrt(1.-k*k); s=h=0.;
  while((c=(a-b)/2.)>.5e-15){ m*=2;
    if((k=atan(b*tan(an)/a))<0.) k+=pi;
    if((k-=fmod(an,pi))>2.) k-=pi;
    an+=an+k; k=a+b; b=sqrt(a*b); a=k/2.;
    h+=c*a*m; s+=c*sin(an);
   }
  *pk=pi/(2.*a); an/=m*a;
  if(pz!=NULL){
    *pz=s+(h=1.-h)*an; *ph=h* *pk;}
  return an;
}
