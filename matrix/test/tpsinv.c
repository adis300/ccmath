/*  tpsinv.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  psinv

    Uses:  mmul  mcopy  matprt

    Input file:  spdm.dat
*/
#include "ccmath.h"
void main(int na,char **av)
{ double *p,*a,*b,*c;
  int i,n; FILE *fp;
  if(na!=2){ printf("para: input_file\n"); exit(-1);}
  fp=fopen(*++av,"r");
  fscanf(fp,"%d",&n);
  a=(double *)calloc(3*n*n,sizeof(double));
  b=a+n*n; c=b+n*n;
  for(i=0,p=a; i<n*n ;++i) fscanf(fp,"%lf",p++);
  printf("Test of SPD Matrix Inverse\n");
  printf("  input matrix\n"); matprt(a,n,n,"%10f ");
  mcopy(b,a,n*n);

/* invert a real symmetric positive definite matrix */
  i=psinv(a,n);

  if(i) printf("  singular input\n");
  else{
     printf("  inverse matrix\n"); matprt(a,n,n,"%10f ");
     printf("  product a*inverse\n"); mmul(c,b,a,n);
     matprt(c,n,n,"%12.9f ");
   }
}
/* Test output

Test of SPD Matrix Inverse
  input matrix
  1.875000   0.625000   0.375000   1.125000 
  0.625000   1.875000   1.125000   0.375000 
  0.375000   1.125000   1.875000   0.625000 
  1.125000   0.375000   0.625000   1.875000 
  inverse matrix
  0.937500  -0.312500   0.187500  -0.562500 
 -0.312500   0.937500  -0.562500   0.187500 
  0.187500  -0.562500   0.937500  -0.312500 
 -0.562500   0.187500  -0.312500   0.937500 
  product a*inverse
 1.000000000 -0.000000000  0.000000000  0.000000000 
-0.000000000  1.000000000 -0.000000000  0.000000000 
-0.000000000 -0.000000000  1.000000000  0.000000000 
-0.000000000 -0.000000000  0.000000000  1.000000000 
*/
