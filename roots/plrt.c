/*  plrt.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <stdlib.h>
#include "complex.h"
int plrt(double *cof,int n,Cpx *root,double ra,double rb)
{ double a,b,s,t,w; int itr,pat; struct complex *pr;
  double *cs,*cf,*hf,*p,*q,*ul,test=1.e-28;
  cs=cf=(double *)calloc(2*n,sizeof(double)); hf=cf+n;
  pr=root+n-1; ul=hf+n-1;
  if(rb<0.) rb=ra*ra-rb*rb; else rb=ra*ra+rb*rb; ra*= -2.;
  q=cof+n; s= *q--;
  for(p=cf; p<hf ;) *p++ = *q-- /s;
  for(itr=pat=0;;){
    if(itr==0){
      if(n>2){ a=ra; b=rb;}
      else if(n==2){ a= *cf++; b= *cf;}
      else if(n==1){ pr->re= -(*cf); pr->im=0.; free(cs); return 0;}
     }
    s= -a/2.; t=s*s-b;
    if(t>=0.){ t=sqrt(t); pr->re=s+t; (pr--)->im=0.;
               pr->re=s-t; (pr++)->im=0.; }
    else{ t=sqrt(-t); pr->re=s; (pr--)->im=t;
          pr->re=s; (pr++)->im= -t; }
    if(n==2){ free(cs); return 0;}
    for(p=hf,q=cf; q<hf ;) *p++ = *q++;
    for(p=hf,w=1.; p<ul ;){
      *p++ -=a*w; *p-=b*w; w=*(p-1); }
    t= -(*p--); t+=pr->re* *p; s=pr->im* *p;
    if(t*t+s*s<test){ pr-=2; ul-=2; n-=2; itr=pat=0;
      for(p=cf,q=hf; p<ul ;) *p++ = *q++;
     }
    else if(++itr<30){
           for(p=hf,w=1.; p<ul-2 ;){
             *p++ -=w*a; *p-=w*b; w= *(p-1); }
      t= *p++; q=p+1; s=t*t+w*(b*w-a*t);
      b+=(w*(*p*b- *q*a)+ *q*t)/s; a+=(*p*t- *q*w)/s;
     }
    else{ if(pat==3){ free(cs); return n;}
          itr=0; if(pat++ %2) ra= -ra; else rb= -rb;}
   }
}
