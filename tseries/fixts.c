/*  fixts.c    CCMATH mathematics library source code.
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
double fixts(double *x,int n,double *var,double *cr)
{ double *cp,*p,*q,*r,*s,*pmax;
  struct mcof *pp; double e,ssq,drmod(double,double *);
  int j,k,psinv(double *,int);
  cp=(double *)calloc(np,sizeof(double));
  for(p=var,pmax=p+np*np; p<pmax ;) *p++ =0.;
  setdr(1); pmax=cr+np;
  for(j=0,ssq=0.; j<n ;){
    e=drmod(x[j++],cr); ssq+=e*e;
    for(k=0,r=cp,s=cr,q=var; s<pmax ;++s,q+= ++k){
      *r++ +=e* *s;
      for(p=s; p<pmax ;) *q++ += *s * *p++;
     }
   }
  for(k=1,p=var,r=p+np*np; k<np ;p+= ++k)
    for(q=p+np; q<r ;q+=np) *q= *++p;
  if(!psinv(var,np)){ q=cp+np;
    for(p=var,s=cr,pp=par; s<pmax ;){
      for(*s=0.,r=cp; r<q ;) *s+= *p++ * *r++;
      (pp++)->cf += *s++;
     }
   }
  else ssq= -1.;
  free(cp); setdr(0); return ssq;
}
