/*  tmop2.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  smgen  mattr  otrma  or  otrsm

    Uses:  matprt

    Input file:  mop2.dat
*/
#include "ccmath.h"
void main(int na,char **av)
{ int i,n; FILE *fp;
  double *p,*a,*b,*c,*ev;
  if(na!=2){ printf("para: input_file\n"); exit(-1);}
  fp=fopen(*++av,"r");
  fscanf(fp,"%d",&n);
  a=(double *)calloc(3*n*n+n,sizeof(double));
  b=a+n*n; c=b+n*n; ev=b+n*n;
  for(i=0,p=ev; i<n ;++i) fscanf(fp,"%lf",p++);
  for(i=0,p=a; i<n*n ;++i) fscanf(fp,"%lf",p++);

  printf("Matrix Operations Test 2\n");
  printf(" eigenvalues\n"); matprt(ev,1,n,"%10f ");
  printf(" eigenvectors\n"); matprt(a,n,n,"%10f ");

/* generate a real symmetric matrix */
  smgen(b,ev,a,n);

  printf(" input matrix\n"); matprt(b,n,n,"%10f ");
/* transpose eigenvector matrix */
  mattr(c,a,n,n);

/* orthogonal transform of b by c */
  otrma(a,c,b,n);

/*  to test the symmetric conjugation replace the previous
    line with the call below */
/*  otrsm(a,c,b,n);  */
  printf(" conjugate C=E'*A*E\n"); matprt(a,n,n,"%10f ");
}
/* Test output

Matrix Operations Test 2
 eigenvalues
  4.000000   2.000000   1.000000   0.500000 
 eigenvectors
  0.500000   0.500000  -0.500000   0.500000 
  0.500000  -0.500000  -0.500000  -0.500000 
  0.500000  -0.500000   0.500000   0.500000 
  0.500000   0.500000   0.500000  -0.500000 
 input matrix
  1.875000   0.625000   0.375000   1.125000 
  0.625000   1.875000   1.125000   0.375000 
  0.375000   1.125000   1.875000   0.625000 
  1.125000   0.375000   0.625000   1.875000 
 conjugate C=E'*A*E
  4.000000   0.000000   0.000000   0.000000 
  0.000000   2.000000   0.000000   0.000000 
  0.000000   0.000000   1.000000   0.000000 
  0.000000   0.000000   0.000000   0.500000 
*/
