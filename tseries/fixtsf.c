/*  fixtsf.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "armaf.h"
#include <stdlib.h>
void setdrf(int k);
extern struct mcof *pfc;
extern int nfc,np,ndif;
static void oprj(double *v,int i,int j);
double fixtsf(struct fmod *x,int n,double *var,double *cr)
{ double *cp,*p,*q,*r,*s,*pmax;
  struct mcof *pp; double e,ssq,drfmod(struct fmod,double *);
  int j,k,psinv(double *,int);
  cp=(double *)calloc(np,sizeof(double));
  for(p=var,pmax=p+np*np; p<pmax ;) *p++ =0.;
  setdrf(1); pmax=cr+np;
  for(j=0,ssq=0.; j<n ;++j){
     e=drfmod(x[j],cr); ssq+=e*e;
     for(r=cp,s=cr,q=var,k=0; s<pmax ;++s,q+= ++k){
        *r++ +=e* *s;
        for(p=s; p<pmax ;) *q++ += *s * *p++; }
   }
  for(p=var,r=p+np*np,k=1; k<np ;p+= ++k)
     for(q=p+np; q<r ;q+=np) *q= *++p;
  if(!psinv(var,np)){ q=cp+np;
     if(ndif) oprj(var,np,nfc);
     for(p=var,s=cr,pp=pfc; s<pmax ;){ *s=0.;
        for(r=cp; r<q ;) *s+= *p++ * *r++;
        (pp++)->cf += *s++; } }
  else ssq= -1.;
  free(cp); setdrf(0); return ssq;
}
static void oprj(double *var,int n,int m)
{ double s,*pd,*p; int i,j;
  pd=(double *)calloc(n,sizeof(double));
  for(i=0,p=pd,s=0.; i<n ;++i){ *p=0.;
     for(j=0; j<m ;++j) *p+=var[i+n*j];
     if(i<m) s+= *p++; else ++p; }
  for(i=0,p=var; i<n ;++i)
     for(j=0; j<n ;++j) *p++ -= *(pd+i)* *(pd+j)/s;
  free(pd);
}
