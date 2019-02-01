/*  tsolvru.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  solvru

    Uses:  vmult  mcopy  matprt

    Input file:  solru.dat
*/
#include "ccmath.h"
void main(int na,char **av)
{ int i,m,n; FILE *fp;
  double *p,*a,*x,*b,*y;
  if(na!=2){ printf("para: input_file\n"); exit(-1);}
  fp=fopen(*++av,"r");
  printf("Test of Linear Equation R-U Decomposition Solver\n");
  fscanf(fp,"%d",&n); m=n*n;
  a=(double *)calloc(2*(m+n),sizeof(double));
  b=a+m; x=b+m; y=x+n;
  for(i=0,p=a; i<m ;++i) fscanf(fp,"%lf",p++);
  for(i=0,p=x; i<n ;++i) fscanf(fp,"%lf",p++);
  printf(" input matrix A:\n"); matprt(a,n,n,"%10f ");
  printf(" input vector x:\n"); matprt(x,1,n,"%10f ");
  mcopy(b,a,n*n);

/* solve the real linear system using R-U decomposition*/
  i=solvru(a,x,n);

  if(i) printf(" matrix singular\n");
  else{ printf(" solution vector y:\n"); matprt(x,1,n,"%10f ");
/* check solution */
    vmul(y,b,x,n);
    printf(" check vector z=A*y\n"); matprt(y,1,n,"%10f ");
   }
}
/* Test output

Test of Linear Equation R-U Decomposition Solver
 input matrix A:
  4.000000  -3.000000   1.000000  -2.000000 
  0.000000  -2.000000   2.000000  -1.000000 
  0.000000   0.000000   3.000000  -2.000000 
  0.000000   0.000000   0.000000   3.000000 
 input vector x:
  1.000000   0.500000  -1.000000  -2.000000 
 solution vector y:
 -0.409722  -0.694444  -0.777778  -0.666667 
 check vector z=A*y
  1.000000   0.500000  -1.000000  -2.000000 
*/
