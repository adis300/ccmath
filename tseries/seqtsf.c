/*  seqtsf.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "armaf.h"
#include <math.h>
#include <stdlib.h>
void setdrf(int k);
extern struct mcof *pfc;
extern int nfc,np,ndif;
double seqtsf(struct fmod *x,int n,double *var,int kf)
{ double *pd,*pg,*pmax,*p,*q,*h,*f; int i,j;
  struct mcof *pp;
  double e,ssq,sig,drfmod(struct fmod,double *);
  pd=(double *)calloc(2*np,sizeof(double)); pg=pd+np;
  if(kf==0){ e=1./nfc;
      for(p=var,i=0; i<np ;++i){
         for(j=0; j<np ;++j,++p){
            if(i==j) *p=1.; else *p=0.;
            if(ndif && (i<nfc && j<nfc)) *p-=e;} }
    }
  setdrf(1); pmax=pg+np;
  for(j=0,ssq=0.; j<n ;++j){
    e=drfmod(x[j],pd); ssq+=e*e;
    for(p=pg,q=pd,f=var,sig=1.; p<pmax ;){ *p=0.;
       for(h=pd; h<pg ;) *p+= *f++ * *h++;
       sig+= *p++ * *q++;
      }
    sig=sqrt(sig); e/=sig;
    for(p=pg,pp=pfc; p<pmax ;) (pp++)->cf+=e*(*p++/=sig);
    for(p=pg,h=var,kf=0; p<pmax ;++p,h+= ++kf)
      for(q=p,f=h; q<pmax ;f+=np) *f=(*h++ -= *p* *q++);
   }
  free(pd); setdrf(0); return ssq;
}
