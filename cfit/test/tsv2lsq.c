/*  tsv2lsq.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Tests:  sv2lsq

    Uses:  sv2uv

    Input file:  tlsq1.dat
*/
#include "ccmath.h"
void main(int na,char **av)
{ int m,n,i;
  double *a,*b,*d,*v,*p;
  double *a1,*b1,*u,s;
  FILE *fp;
  if(na!=2){ printf("para: in_file\n"); exit(-1);}
  fp=fopen(*++av,"r");
  fscanf(fp,"%d %d",&m,&n);
  printf(" %d meas. %d param.\n",m,n);
  a=(double *)calloc(m*n,sizeof(double));
  b=(double *)calloc(m,sizeof(double));
  d=(double *)calloc(n,sizeof(double));
  v=(double *)calloc(n*n,sizeof(double));
  a1=(double *)calloc(m*n,sizeof(double));
  b1=(double *)calloc(m,sizeof(double));
  u=(double *)calloc(m*m,sizeof(double));
  for(i=0,p=a; i<m*n ;++i) fscanf(fp,"%lf",p++);
  for(i=0,p=b; i<n ;++i) fscanf(fp,"%lf",p++);
  mcopy(a1,a,m*n); mcopy(b1,b,m);

/*  Least squares SVD solution for d_points >> parameters */
  sv2lsq(d,a,b,m,v,n);
  
  printf(" sing-val:\n"); matprt(d,1,n," %10.6f");
  printf(" vec-b~:\n"); matprt(b,1,m," %10.6f");
  printf(" v-mat:\n"); matprt(v,n,n," %9.6f");
  for(i=n,s=0.; i<m ;++i) s+=b[i]*b[i];
  printf(" ssq= %10.6f\n\n",s);

/* Singular value decomposition check */  
  sv2uv(d,a1,u,m,v,n);
  
  printf(" sing-val:\n"); matprt(d,1,n," %10.6f");
  trnm(u,m); vmul(b,u,b1,m);
  printf(" vec-b1~:\n"); matprt(b,1,m," %10.6f");
  printf(" v1-mat:\n"); matprt(v,n,n," %9.6f");
}
/* Test output

 7 meas. 4 param.
 sing-val:
   7.639121   5.102374   4.015163   1.421469
 vec-b~:
   1.204588  -2.114046  -0.040991   0.422213  -0.780484   1.000088  -0.374839
 v-mat:
  0.195529 -0.515817  0.811628  0.192251
 -0.581590 -0.642625 -0.352005  0.353381
  0.595632  0.034045 -0.298332  0.745025
 -0.518405  0.565514  0.358260  0.532071
 ssq=   1.749837

 sing-val:
   7.639121   5.102374   4.015163   1.421469
 vec-b1~:
   1.204588  -2.114046  -0.040991   0.422213  -0.780484   1.000088  -0.374839
 v1-mat:
  0.195529 -0.515817  0.811628  0.192251
 -0.581590 -0.642625 -0.352005  0.353381
  0.595632  0.034045 -0.298332  0.745025
 -0.518405  0.565514  0.358260  0.532071
*/
