/*  gnlsq.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <stdlib.h>
double gnlsq(double *x,double *y,int n,double *par,double *var,int m,
		double de,double (*func)())
{ double *cp,*dp,*p,*q,*r,*s,*t;
  double err,f,z,ssq; int j,k,psinv();
  cp=(double *)calloc(2*m,sizeof(double)); dp=cp+m;
  for(p=var,q=var+m*m; p<q ;) *p++ =0.;
  for(j=0,ssq=0.; j<n ;++j){ z=x[j];
    f=(*func)(z,par); err=y[j]-f; ssq+=err*err;
    for(k=0,p=par,r=cp; k<m ;++k){ *p+=de;
      *r++ =((*func)(z,par)-f)/de; *p++ -=de;
     }
    for(r=dp,s=cp,q=var; s<dp ;++s,q+=m+1){
      *r++ +=err* *s;
      for(t=s,p=q; t<dp ;) *p++ += *s* *t++;
     }
   }
  for(j=0,p=var; j<m ;++j,p+=m+1)
    for(k=j+1,q=p,r=p; k<m ;++k) *(q+=m)= *++r;
  if(psinv(var,m)==0){
    for(k=0,p=var,s=par; k<m ;++k,++s)
      for(j=0,t=dp; j<m ;++j) *s+= *p++ * *t++;
    free(cp); return ssq;
   }
  free(cp); return -1.;
}
