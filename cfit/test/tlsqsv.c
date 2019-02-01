/*  tlsqsv.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  lsqsv

    Uses:  svdlsq  eigen

    Test input:  lsqsv.dat
*/
#include "ccmath.h"
void main(int na,char **av)
{ double x,dx,f,t,ssq;
  double *a,*b,*c,*d,*v,*var,*p;
  int n,m,i,j;
  FILE *fp;
  if(na!=2){ printf("para: in_file\n"); exit(-1);}
  fp=fopen(*++av,"r");
  fscanf(fp,"%d %d %lf",&n,&m,&dx);
  a=(double *)calloc(m*n,sizeof(double));
  b=(double *)calloc(m,sizeof(double));
  c=(double *)calloc(n,sizeof(double));
  d=(double *)calloc(n,sizeof(double));
  v=(double *)calloc(n*n,sizeof(double));
  var=(double *)calloc(n*n,sizeof(double));
  for(i=0; i<n ;++i) fscanf(fp,"%lf",c+i);
  printf(" %d meas. %d param.\n",m,n);
  printf(" cf-in:\n"); matprt(c,1,n," %9.4f");
  for(i=0,x=0.,p=a; i<m ;++i){
    x+=dx;
    for(j=0,f=0.,t=1.; j<n ;++j){
      f+=c[j]*(*p++ =t); t*=x;
     }
    b[i]=f;
   }
  
/* Compute lsq solution using a singular value decomposition */
  svdlsq(d,a,b,m,v,n);

  printf(" sing-val:\n"); matprt(d,1,n," %10.6f");
/* enter threshold for a a singular value effectively = zero */
  fprintf(stderr," enter threshold: "); scanf("%lf",&t);
/* compute least squares reduced rank solution */
  ssq=lsqsv(c,&j,var,d,b,v,m,n,t);

  printf(" rank: %d ssq= %15.12f\n",j,ssq);
  printf(" cf-out:\n"); matprt(c,1,n," %12.8f");
  printf(" cf-var-mat:\n"); matprt(var,n,n," %12.9f");
/* compute eigenvectors and values of the variance matrix */
  eigen(var,d,n);
  printf(" var-ev:\n"); matprt(d,1,n," %12.9f");
  printf(" var-evec:\n"); matprt(var,n,n," %10.6f");
}
/* Test output

     (threshold entered: 2.e-3 -> reduced rank solution)

 8 meas. 5 param.
 cf-in:
    1.0000    0.4000    2.1000   -1.2000   -0.7000
 sing-val:
   3.271984   0.933026   0.184390   0.024232   0.001806
 enter threshold:  rank: 4 ssq=  0.000008101694
 cf-out:
   0.98806170   0.57253938   1.35978962   0.00969771  -1.36504152
 cf-var-mat:
  0.000011857 -0.000085383  0.000134713  0.000031663 -0.000114710
 -0.000085383  0.000700286 -0.001185774 -0.000255025  0.001039132
  0.000134713 -0.001185774  0.002120958  0.000417448 -0.001911414
  0.000031663 -0.000255025  0.000417448  0.000096597 -0.000355657
 -0.000114710  0.001039132 -0.001911414 -0.000355657  0.001752179
 var-ev:
  0.004599092  0.000079429  0.000003102  0.000000252  0.000000000
 var-evec:
   0.043243  -0.171071  -0.491188  -0.852960   0.007576
  -0.379459   0.686195   0.447672  -0.415632  -0.109486
   0.678953  -0.029656   0.506425  -0.247091   0.469705
   0.133146  -0.427051   0.429523  -0.161764  -0.767622
  -0.612728  -0.562690   0.342590  -0.111746   0.422006
*/
