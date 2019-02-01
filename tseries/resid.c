/*  resid.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
int resid(double *x,int n,int lag,double **pau,int nbin,
       double xa,double xb,int **phs,int *cks)
{ int j,m,*hist(double *,int,double,double,int,double *);
  double y,f,s,d,*autcor(double *,int,int),bin; 
  *pau=autcor(x,n,lag);
  *phs=hist(x,n,xa,xb,nbin,&bin);
  n=pwspec(x,n,0);
  m=n/2; f=2./n; s=m-1; s=sqrt(s);
  xa=1.02/s; xb=1.36/s; cks[0]=cks[1]=0;
  for(s=y=0.,j=0; j<m ;++j){
    s+=x[j]+x[j+1];
    if((d=fabs(s-(y+=f)))>xa){
      ++cks[0]; if(d>xb) ++cks[1];
     }
   }
  return n;
}
