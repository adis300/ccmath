/*  tsv2uv.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  sv2uv

    Uses:  rmmult  trnm  mcopy  matprt

    Input file:  svd?.dat  with ? -> 1 to 7
*/
#include "ccmath.h"
#include <math.h>
char fma[]=" %11.6f",fme[]=" %14.7f",fmf[]=" %9.6f";
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

/* singular value decomposition  d = u'*a*v (best for m>>n) */
  i=sv2uv(d,a,u,m,v,n);

  if(i== -1){ printf(" error: m < n\n"); exit(-1);}
  printf(" sval:\n"); matprt(d,1,n,fme);
  printf(" u:\n"); matprt(u,m,m,fmf);
  printf(" v:\n"); matprt(v,n,n,fmf);
/* check decomposition by computing d */
  trnm(u,m); rmmult(a,u,a1,m,m,n);
  rmmult(a1,a,v,m,n,n);
  printf(" u'*a*v:\n"); matprt(a1,m,n,fme);
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
 u:
  0.271122  0.427936  0.343106 -0.653808  0.249396  0.197172  0.311612
 -0.328716 -0.348913 -0.546868 -0.314360  0.391614  0.455786  0.105908
  0.293866  0.424266 -0.228978  0.252257 -0.200141  0.684595 -0.329925
  0.166418  0.140431 -0.112043 -0.100491  0.588615 -0.320892 -0.693176
 -0.176523  0.192674  0.250787  0.612398  0.609670  0.145853  0.317522
  0.187889 -0.612905  0.594907 -0.007430  0.070898  0.381587 -0.290587
  0.798701 -0.287459 -0.318467  0.157780  0.145575 -0.121898  0.342165
 v:
  0.208055 -0.007013  0.156832 -0.626802  0.734294
  0.166805  0.118164  0.579478  0.675843  0.407007
  0.008114  0.111517 -0.789312  0.366225  0.479962
 -0.232556 -0.952540  0.012948  0.119083  0.155680
  0.935276 -0.257330 -0.128170  0.045331 -0.201389
 u'*a*v:
      7.2554647     -0.0000000     -0.0000000     -0.0000000      0.0000000
      0.0000000      6.4588852      0.0000000     -0.0000000     -0.0000000
     -0.0000000     -0.0000000      3.4706396     -0.0000000     -0.0000000
      0.0000000     -0.0000000     -0.0000000      2.5914230     -0.0000000
      0.0000000     -0.0000000     -0.0000000      0.0000000      1.9733276
      0.0000000      0.0000000     -0.0000000      0.0000000     -0.0000000
     -0.0000000     -0.0000000     -0.0000000      0.0000000      0.0000000
*/
