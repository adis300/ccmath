/*  tmop1.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  mattr  rmmult  vmul  vnrm  matprt

    Input file:  mop1.dat
*/
#include "ccmath.h"
void main(int na,char **av)
{ int i,n; FILE *fp;
  double *p,*a,*b,*c,*u,*v,s;
  if(na!=2){ printf("para: input_file\n"); exit(-1);}
  fp=fopen(*++av,"r");
  fscanf(fp,"%d",&n);
  a=(double *)calloc(3*n*n+2*n,sizeof(double));
  b=a+n*n; c=b+n*n; u=c+n*n; v=u+n;
  for(i=0,p=a; i<n*n ;++i) fscanf(fp,"%lf",p++);
  for(i=0,p=v; i<n ;++i) fscanf(fp,"%lf",p++);

  printf("Matrix Operations Test 1\n");
  printf(" input matrix A:\n"); matprt(a,n,n,"%10.5f ");

/* transpose matrix */
  mattr(b,a,n,n);

  printf(" transpose B=A'\n"); matprt(b,n,n,"%10.5f ");

/* multiply matrices */
  rmmult(c,a,b,n,n,n);

  printf(" product C=A*A'\n"); matprt(c,n,n,"%10.5f ");
  printf(" input vector v:\n"); matprt(v,1,n,"%10.5f ");

/* matrix vector multiplication */
  vmul(u,c,v,n);

  printf(" product u=C*v\n"); matprt(u,1,n,"%10.5f ");

/* vector inner product */
  s=vnrm(u,v,n);

  printf(" <u,v>= %12.7f\n",s);
}
/* Test output

Matrix Operations Test 1
 input matrix A:
   6.00000    4.00000   -2.00000   -3.00000    1.00000   -4.00000 
   3.00000   -7.00000    2.00000    4.00000   -2.00000    1.00000 
   0.00000    3.00000    5.00000   -4.00000    2.00000   -1.00000 
   2.00000   -1.00000    0.00000    4.00000    2.00000   -3.00000 
   1.00000    0.00000    2.00000    5.00000   -3.00000    4.00000 
  -4.00000    2.00000   -6.00000    3.00000    0.00000    8.00000 
 transpose B=A'
   6.00000    3.00000    0.00000    2.00000    1.00000   -4.00000 
   4.00000   -7.00000    3.00000   -1.00000    0.00000    2.00000 
  -2.00000    2.00000    5.00000    0.00000    2.00000   -6.00000 
  -3.00000    4.00000   -4.00000    4.00000    5.00000    3.00000 
   1.00000   -2.00000    2.00000    2.00000   -3.00000    0.00000 
  -4.00000    1.00000   -1.00000   -3.00000    4.00000    8.00000 
 product C=A*A'
  82.00000  -32.00000   20.00000   10.00000  -32.00000  -45.00000 
 -32.00000   83.00000  -32.00000   22.00000   37.00000  -18.00000 
  20.00000  -32.00000   55.00000  -12.00000  -20.00000  -44.00000 
  10.00000   22.00000  -12.00000   34.00000    4.00000  -22.00000 
 -32.00000   37.00000  -20.00000    4.00000   55.00000   31.00000 
 -45.00000  -18.00000  -44.00000  -22.00000   31.00000  129.00000 
 input vector v:
   1.00000    1.00000    1.00000    1.00000    1.00000    1.00000 
 product u=C*v
   3.00000   60.00000  -33.00000   36.00000   75.00000   31.00000 
 <u,v>=  172.0000000
*/
