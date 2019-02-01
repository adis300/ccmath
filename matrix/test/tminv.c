/*  tminv.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
   Test:  minv

   Uses:  mmul  mcopy  matprt

   Input data file:  mat.dat
*/
#include "ccmath.h"
void main(int na,char **av)
{ int i,n; FILE *fp;
  double *p,*a,*b,*c;
  if(na!=2){ printf("para: input_file\n"); exit(-1);}
  fp=fopen(*++av,"r");
  fscanf(fp,"%d",&n);
  a=(double *)calloc(3*n*n,sizeof(double));
  b=a+n*n; c=b+n*n;
  for(i=0,p=a; i<n*n ;++i) fscanf(fp,"%lf",p++);
  printf("Test of Matrix Inverse\n");
  printf(" input matrix A:\n"); matprt(a,n,n,"%10f ");
  mcopy(b,a,n*n);

/* invert a general real matrix */
  i=minv(a,n);

  if(i) printf( "singular matrix\n");
  else{
    printf(" inverse matrix:\n"); matprt(a,n,n,"%10f ");
    mmul(c,a,b,n);
    printf(" product C=inverse*A:\n"); matprt(c,n,n,"%12.9f ");
   }
}
/* Test output

Test of Matrix Inverse
 input matrix A:
  6.000000   3.000000   1.000000   2.000000 
  3.000000   5.000000   2.000000  -1.000000 
  1.000000   2.000000   3.000000  -2.000000 
  2.000000  -1.000000  -2.000000   4.000000 
 inverse matrix:
  0.527273  -0.290909  -0.309091  -0.490909 
 -0.290909   0.436364  -0.036364   0.236364 
 -0.309091  -0.036364   0.836364   0.563636 
 -0.490909   0.236364   0.563636   0.836364 
 product C=inverse*A:
 1.000000000 -0.000000000  0.000000000 -0.000000000 
 0.000000000  1.000000000  0.000000000  0.000000000 
 0.000000000  0.000000000  1.000000000  0.000000000 
 0.000000000  0.000000000  0.000000000  1.000000000 
*/
