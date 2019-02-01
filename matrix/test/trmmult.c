/*  trmmult.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  rmmult

    Uses:  matprt nrml

    Input parameters:  n1 n2 n3 -> matrix sizes
                                   matrix A is n1 by n2
                                   matrix B is n2 by n3
                                  product C is n1 by n3
*/
#include "ccmath.h"
char fmt[]=" %8.4f";
void main(int na,char **av)
{ int n,m,k,i; double *a,*b,*c,*d;
  unsigned int seed;
  if(na!=4){ printf("para: dim1 dim2 dim3\n"); exit(1);}
  n=atoi(*++av); m=atoi(*++av); k=atoi(*++av);
  a=(double *)calloc(n*m,sizeof(double));
  b=(double *)calloc(m*k,sizeof(double));
  c=(double *)calloc(n*k,sizeof(double));
  d=(double *)calloc(n*k,sizeof(double));
  seed=123456789; setnrml(seed);
  for(i=0; i<n*m ;++i) a[i]=nrml();
  for(i=0; i<m*k ;++i) b[i]=nrml();
  printf(" matrix a:\n");
  matprt(a,n,m,fmt);
  printf(" matrix b:\n");
  matprt(b,m,k,fmt);

/* multiply general real matrices */
  rmmult(c,a,b,n,m,k);

  printf(" product matrix c=a*b:\n");
  matprt(c,n,k,fmt);
/* check product if first factor is a square matrix */
  if(n==m){
    minv(a,n); rmmult(d,a,c,n,m,k);
    printf(" matrix b?:\n");
    matprt(d,n,k,fmt);
   }
}
/* Test output

 matrix a:
   0.4557  -0.4533   1.6577  -0.7214
  -0.7719  -0.2094  -1.1154  -0.5361
   0.0687   1.2485  -0.2458   0.1434
 matrix b:
  -1.0685   0.5778   0.3996
  -0.0495   1.3866   0.2262
  -0.7969   0.7173   1.8117
  -0.4851   0.0622   1.0920
 product matrix c=a*b:
  -1.4355   0.7789   2.2950
   1.9841  -1.5698  -2.9621
  -0.0090   1.6035   0.0212
*/
