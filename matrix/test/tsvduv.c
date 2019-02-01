/*  tsvduv.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  svduv

    Uses:  rmmult  trnm  mcopy  matprt

    Input file:  svd?.dat  with ? -> 1 t0 7
*/
#include "ccmath.h"
#include <math.h>
char fma[]=" %11.6f",fme[]=" %14.7f",fmf[]=" %9.6f";
void main(int na,char **av)
{ int i,j,m,n;
  double *a,*d,*u,*v;
  double *a1;
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

/* singular value decomposition  d = u'*a*v  (best for m near n) */
  i=svduv(d,a,u,m,v,n);

  if(i== -1){ printf("error: m<n\n"); exit(-1);}
  printf(" mat-u:\n");
  matprt(u,m,m,fmf);
  printf(" mat-v:\n");
  matprt(v,n,n,fmf);
  printf(" sval:\n");
  matprt(d,1,n,fme);
/* check decomposition by computing d */
  rmmult(a,a1,v,m,n,n);
  trnm(u,m); rmmult(a1,u,a,m,m,n);
  printf(" mat u'*a*v:\n");
  matprt(a1,m,n,fme);
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
 mat-u:
  0.152297 -0.748933  0.122096 -0.598107  0.098468 -0.183220
 -0.136715  0.223829  0.443467 -0.329615 -0.787079 -0.080045
  0.036130  0.571222  0.288810 -0.527014  0.549438 -0.096764
  0.319870 -0.139342  0.775977  0.482525  0.154164 -0.139751
 -0.921648 -0.189547  0.250486  0.087283  0.210383  0.003759
  0.071116 -0.085798  0.200339 -0.124214  0.030012  0.964943
 mat-v:
  0.074355 -0.089069  0.993246
 -0.962047 -0.268641  0.047930
  0.262558 -0.959113 -0.105663
 sval:
     11.7105726     10.8589905      5.3023406
 mat u'*a*v:
     11.7105726      0.0000000      0.0000000
      0.0000000     10.8589905     -0.0000000
      0.0000000      0.0000000      5.3023406
      0.0000000      0.0000000     -0.0000000
     -0.0000000     -0.0000000     -0.0000000
     -0.0000000      0.0000000     -0.0000000
*/
