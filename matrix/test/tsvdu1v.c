/*  tsvdu1v.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  svdu1v

    Uses:  rmmult  trnm  matprt

    Input file:  svd?.dat  with ? -> 1 to 7
*/
#include "ccmath.h"
#include <math.h>
char fma[]=" %11.6f";
char fmf[]=" %9.6f";
char fme[]=" %13.7f";
void main(int na,char **av)
{ int i,j,m,n;
  double *a,*d,*v;
  double *a1;
  double *p,*q;
  FILE *fin;
  if(na!=2){ printf("para: file_in\n"); exit(-1);}
  fin=fopen(*++av,"r");
  fscanf(fin,"%d %d",&m,&n);
  if(m<n){ printf("error m<n\n"); exit(-1);}
  a=(double *)calloc(m*n,sizeof(double));
  a1=(double *)calloc(m*n,sizeof(double));
  v=(double *)calloc(n*n,sizeof(double));
  d=(double *)calloc(n,sizeof(double));
  for(i=0,p=a; i<m ;++i){
    for(j=0; j<n ;++j) fscanf(fin,"%lf",p++);
   }
  printf(" dim: %d x %d\n",m,n);
  printf(" a-in:\n");
  matprt(a,m,n,fma);

/* singular value decomposition  a = u1*d*v' (best for m near n) */
  i=svdu1v(d,a,m,v,n);

  if(i== -1){ printf("error: m<n\n"); exit(-1);}
  printf(" mat-u1:\n");
  matprt(a,m,n,fmf);
  printf(" mat-v:\n");
  matprt(v,n,n,fmf);
  printf(" sval:\n");
  matprt(d,1,n,fme);
/* check decomposition by computing a */
  trnm(v,n);
  for(i=0,p=v; i<n ;++i){
    for(j=0; j<n ;++j) *p++ *=d[i];
   }
  rmmult(a1,a,v,m,n,n);
  printf(" u1*d*v': %d x %d\n",m,n);
  matprt(a1,m,n,fma);
}
/* Test output

 dim: 3 x 3
 a-in:
    1.500000    0.500000    8.200000
    2.000000    1.000000   -3.000000
    1.000000   -2.000000   -6.000000
 mat-u1:
  0.769185  0.400531 -0.497925
 -0.267256 -0.506145 -0.819995
 -0.580455  0.763801 -0.282275
 mat-v:
  0.003638  0.187404 -0.982276
  0.119812 -0.975288 -0.185627
  0.992790  0.117014  0.026001
 sval:
    10.6687413     1.8799384     2.7173133
 u1*d*v': 3 x 3
    1.500000    0.500000    8.200000
    2.000000    1.000000   -3.000000
    1.000000   -2.000000   -6.000000
*/
