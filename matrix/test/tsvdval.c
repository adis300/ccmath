/*  tsvdval.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  svdval

    Uses:  matprt

    Input file:  svd?.dat  with ? -> 1 to 7
*/
#include "ccmath.h"
#include <math.h>
char fma[]=" %11.6f",fme[]=" %14.7f",fmf[]=" %9.6f";
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

/* compute the singular values of a real matrix  (best for m near n) */
  i=svdval(d,a,m,n);

  if(i== -1){ printf("error: m < n\n"); exit(-1);}
  printf(" sval:\n");
  matprt(d,1,n,fme);
}
/* Test output

 dim: 7 x 5
 a-in:
    2.000000    0.400000   -1.000000   -3.200000    0.800000
    0.300000   -2.000000    1.300000    2.700000   -1.600000
   -0.400000    0.500000    1.000000   -3.100000    1.500000
    1.200000    0.380000    0.880000   -1.000000    0.700000
   -0.250000    2.000000    0.600000   -0.500000   -1.800000
    0.750000    1.000000   -2.000000    3.500000    2.000000
    1.000000    0.500000    1.000000    0.500000    6.000000
 sval:
      7.2554647      6.4588852      3.4706396      2.5914230      1.9733276
*/
