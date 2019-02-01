/*  tsolvtd.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  solvtd

    Uses:  matprt

    Input file:  std.dat
*/
#include "ccmath.h"
void main(int na,char **av)
{ int i,n; FILE *fp;
  double *p,*a,*b,*c,*x;
  if(na!=2){ printf("para: input_file\n"); exit(-1);}
  fp=fopen(*++av,"r");
  fscanf(fp,"%d",&n);
  a=(double *)calloc(4*n,sizeof(double));
  b=a+n; c=b+n; x=c+n;
  for(i=0,p=a; i<n ;++i) fscanf(fp,"%lf",p++);
  for(i=0,p=b; i<n-1 ;++i) fscanf(fp,"%lf",p++);
  for(i=0,p=c; i<n-1 ;++i) fscanf(fp,"%lf",p++);
  for(i=0,p=x; i<n ;++i) fscanf(fp,"%lf",p++);
  printf("Test of Linear Tridiagonal Solver\n");
  printf(" input matrix diagonal  a\n"); matprt(a,1,n,"%10f ");
  printf("   below diagonal  b\n"); matprt(b,1,n-1,"%10f ");
  printf("   above diagonal  c\n"); matprt(c,1,n-1,"%10f ");
  printf(" input vector x:\n"); matprt(x,1,n,"%10f ");

/* solve the tridiagonal linear system */
  solvtd(a,b,c,x,n-1);

  printf(" solution vector y:\n"); matprt(x,n,1,"%10f ");
}
/* Test output

Test of Linear Tridiagonal Solver
 input matrix diagonal  a
  1.000000   2.000000   3.000000   6.000000  -2.000000   7.000000 
   below diagonal  b
  3.000000  -1.000000   4.000000  -3.000000   2.000000 
   above diagonal  c
  2.000000   1.000000  -2.000000  -1.000000   5.000000 
 input vector x:
  3.000000   6.000000   0.000000   9.000000   0.000000   9.000000 
 solution vector y:
  1.000000 
  1.000000 
  1.000000 
  1.000000 
  1.000000 
  1.000000 
*/
