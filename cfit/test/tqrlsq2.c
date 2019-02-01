/*  tqrlsq2.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  qrlsq  qrvar

    Uses:  mattr  mmul

    Input file:  tqr2.dat
*/
#include "ccmath.h"
void main(int na,char **av)
{ double x,dx,f,t;
  double *b,*c,*ad,*r,*rt,*v1,*p;
  int n,m,i,j,k;
  FILE *fp;
  if(na!=2){ printf("para: in_file\n"); exit(-1);}
  fp=fopen(*++av,"r");
  fscanf(fp,"%d %d %lf",&n,&m,&dx);
  c=(double *)calloc(n,sizeof(double));
  b=(double *)calloc(m,sizeof(double));
  ad=(double *)calloc(m*n,sizeof(double));
  r=(double *)calloc(n*n,sizeof(double));
  rt=(double *)calloc(n*n,sizeof(double));
  v1=(double *)calloc(n*n,sizeof(double));
  for(i=0; i<n ;++i) fscanf(fp,"%lf",c+i);
  printf(" %d meas. %d param.\n",m,n);
  printf(" cf-in:\n"); matprt(c,1,n," %9.4f");
  for(i=0,x=0.,p=ad; i<m ;++i){
    x+=dx;
    for(j=0,f=0.,t=1.; j<n ;++j){
      f+=c[j]*(*p++ =t); t*=x;
     }
    b[i]=f;
   }

/* Linear least squares via a QR transform */  
  t=qrlsq(ad,b,m,n,&j);
  
  mcopy(r,ad,n*n);
  for(i=0,p=r; i<n ;++i){
    for(k=0; k<n ;++k,++p) if(k<i) *p=0.;
   }
  printf(" ssq= %.3e\n",t);
  if(j== -1) printf(" singular reduced matrix\n");
  else{
    printf(" cf-out:\n"); matprt(b,1,n," %10.6f");

/* Parameter variance computation for QR least squares */
    t=qrvar(ad,m,n,t);
    
    printf(" sig*sig= %e\n",t);
    printf(" var-mat:\n"); matprt(ad,n,n," %10.6f");
    mattr(rt,r,n,n); mmul(v1,rt,r,n);
    for(i=0,k=n*n,t=1./t,p=ad; i<k ;++i) *p++ *=t;
    mmul(rt,v1,ad,n);
    printf(" r'*r*var/(sig*sig):\n");
    matprt(rt,n,n," %10.6f");
   }
}
/* Test output

 50 meas. 5 param.
 cf-in:
   -1.0000    2.5000    1.5000   -2.0000    0.5000
 ssq= 9.297e-28
 cf-out:
  -1.000000   2.500000   1.500000  -2.000000   0.500000
 sig*sig= 2.066068e-29
 var-mat:
   0.000000  -0.000000   0.000000  -0.000000   0.000000
  -0.000000   0.000000  -0.000000   0.000000  -0.000000
   0.000000  -0.000000   0.000000  -0.000000   0.000000
  -0.000000   0.000000  -0.000000   0.000000  -0.000000
   0.000000  -0.000000   0.000000  -0.000000   0.000000
 r'*r*var/(sig*sig):
   1.000000  -0.000000   0.000000  -0.000000   0.000000
  -0.000000   1.000000   0.000000  -0.000000   0.000000
  -0.000000   0.000000   1.000000  -0.000000   0.000000
  -0.000000   0.000000   0.000000   1.000000   0.000000
  -0.000000  -0.000000   0.000000  -0.000000   1.000000
*/
