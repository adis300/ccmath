/*  tsv2val.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  sv2val

    Uses:  matprt

    Input file:  svd?.dat  with ? -> 1 to 7
*/
#include "ccmath.h"
#include <math.h>
char fma[]=" %11.6f",fme[]=" %14.7f";
void main(int na,char **av)
{ int i,j,m,n;
  double *a,*d;
  double *p,*q;
  FILE *fin;
  if(na!=2){ printf("para: file_in\n"); exit(-1);}
  fin=fopen(*++av,"r");
  fscanf(fin,"%d %d",&m,&n);
  if(m<n){ printf("error m<n\n"); exit(-1);}
  a=(double *)calloc(m*n,sizeof(double));
  d=(double *)calloc(n,sizeof(double));
  for(i=0,p=a; i<m ;++i){
    for(j=0; j<n ;++j) fscanf(fin,"%lf",p++);
   }
  printf(" dim: %d x %d\n",m,n);
  printf(" a-in:\n");
  matprt(a,m,n,fma);

/* compute singular values of a real matrix  (best for m>>n) */
  i=sv2val(d,a,m,n);

  if(i== -1){ printf("error: m < n\n"); exit(-1);}
  printf(" sval:\n");
  matprt(d,1,n,fme);
}
/* Test output

 dim: 6 x 3
 a-in:
    1.500000    0.500000    8.200000
    2.000000    1.000000   -3.000000
    1.000000   -2.000000   -6.000000
    4.500000   -3.000000    2.000000
    0.700000   11.000000   -1.000000
    1.200000   -0.500000    1.000000
 sval:
     11.7105726     10.8589905      5.3023406
*/
