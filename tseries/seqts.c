/*  seqts.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "arma.h"
#include <stdlib.h>
void setdr(int k);
extern int np; extern struct mcof *par;
double seqts(double *x,int n,double *var,int kf)
{ double *pd,*pg,*pmax,*p,*q,*h,*f; int j;
  struct mcof *pp;
  double e,ssq,sig,sqrt(double),drmod(double,double *);
  pd=(double *)calloc(2*np,sizeof(double)); pg=pd+np;
  if(!kf){ for(p=var,pmax=p+np*np; p<pmax ;) *p++ =0.;
    for(p=var; p<pmax ;p+=np+1) *p=1.;
   }
  setdr(1); pmax=pg+np;
  for(j=0,ssq=0.; j<n ;){
    e=drmod(x[j++],pd); ssq+=e*e;
    for(p=pg,q=pd,f=var,sig=1.; p<pmax ;){
      for(*p=0.,h=pd; h<pg ;) *p+= *f++ * *h++;
      sig+= *p++ * *q++;
     }
    e/=(sig=sqrt(sig));
    for(p=pg,pp=par; p<pmax ;) (pp++)->cf +=e*(*p++/=sig);
    for(kf=0,p=pg,h=var; p<pmax ;++p,h+= ++kf)
      for(q=p,f=h; q<pmax ;f+=np) *f=(*h++ -= *p * *q++);
   }
  free(pd); setdr(0); return ssq;
}
