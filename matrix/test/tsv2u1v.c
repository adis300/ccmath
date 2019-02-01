/*  tsv2u1v.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  sv2u1v

    Uses:  rmmult  trnm  mcopy  matprt

    Input file:  svd?.dat  with ? -> 1 to 7
*/
#include "ccmath.h"
#include <math.h>
char fma[]=" %11.6f";
char fmf[]=" %9.6f";
char fme[]=" %14.8f";
void main(int na,char **av)
{ int i,j,m,n;
  double *a,*d,*u,*v;
  double *a1,*a0,*u0,*us,*a2;
  double *p,*q;
  FILE *fin;
  if(na!=2){ printf("para: file_in\n"); exit(-1);}
  fin=fopen(*++av,"r");
  fscanf(fin,"%d %d",&m,&n);
  if(m<n){ printf("error m<n\n"); exit(-1);}
  a=(double *)calloc(m*n,sizeof(double));
  a1=(double *)calloc(m*n,sizeof(double));
  u=(double *)calloc(m*m,sizeof(double));
  v=(double *)calloc(n*n,sizeof(double));
  d=(double *)calloc(n,sizeof(double));
  for(i=0,p=a; i<m ;++i){
    for(j=0; j<n ;++j) fscanf(fin,"%lf",p++);
   }
  mcopy(a1,a,m*n);
  printf(" dim: %d x %d\n",m,n);
  printf(" a-in:\n");
  matprt(a,m,n,fma);

/* singular value decomposition a = u1*d*v'  (best for m>>n) */
  i=sv2u1v(d,a,m,v,n);

  if(i== -1){ printf(" error: m < n\n"); exit(-1);}
  printf(" sval:"); matprt(d,1,n,fme);
  printf(" u1:\n"); matprt(a,m,n,fmf);
  printf(" v:\n"); matprt(v,n,n,fmf);
/* check decomposition by inversion */
  trnm(v,n);
  for(i=0,p=v; i<n ;++i){
    for(j=0; j<n ;++j) *p++ *=d[i];
   }
  rmmult(a1,a,v,m,n,n);
  printf(" u1*d*v': %d x %d\n",m,n);
  matprt(a1,m,n,fma);
}
/* Test output

 dim: 5 x 4
 a-in:
    1.000000   -0.900000   -2.300000    1.700000
    0.500000   -3.100000   -1.000000    0.700000
    0.600000   -0.900000    0.350000   -1.000000
    1.800000   -1.200000    0.750000    3.000000
    2.000000    1.200000   -0.900000    2.700000
 sval:     5.59347662     3.63467070     1.05418064     2.40954174
 u1:
  0.479380  0.154713 -0.003105  0.654079
  0.338503  0.765917  0.082186  0.036301
 -0.060169  0.277035 -0.915582 -0.200644
  0.600246 -0.025085  0.179545 -0.709887
  0.540088 -0.558621 -0.350299  0.163296
 v:
  0.495783 -0.126147 -0.843099 -0.165742
 -0.267962 -0.936304 -0.060493  0.218795
 -0.267817 -0.148803  0.051632 -0.950508
  0.781454 -0.292025  0.531845 -0.145577
 u1*d*v': 5 x 4
    1.000000   -0.900000   -2.300000    1.700000
    0.500000   -3.100000   -1.000000    0.700000
    0.600000   -0.900000    0.350000   -1.000000
    1.800000   -1.200000    0.750000    3.000000
    2.000000    1.200000   -0.900000    2.700000
*/
