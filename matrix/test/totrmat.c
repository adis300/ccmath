/*  totrmat.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  otrma  otrsm  trnm

    Uses:  ortho  smgen  mcopy  matprt

    Input parameter:  n -> size of matrices is n by n
*/
#include "ccmath.h"
char fmt[]=" %8.4f";
void main(int na,char **av)
{ int n,m,k; double *a,*u,*v,*h;
  double *q; unsigned int seed;
  if(na!=2){ printf("para: dim\n"); exit(1);}
  n=atoi(*++av); m=n*n;
  a=(double *)calloc(4*m,sizeof(double));
  q=(double *)calloc(n,sizeof(double));
  h=a+m; u=h+m; v=u+m;
  seed=123456789; setunfl(seed);
  for(k=1; k<=n ;++k) q[k-1]=(double)k;
  ortho(u,n); smgen(h,q,u,n);
  printf(" matrix h:\n");
  matprt(h,n,n,fmt);

/* set v to the transpose of u */
  mcopy(v,u,n*n); trnm(v,n);

/* orthogonal transform of h by v */
  otrma(a,v,h,n);

  printf(" matrix vhv~:\n");
  matprt(a,n,n,fmt);

/* orthogonal transform of symmetric h by v */
  otrsm(a,v,h,n);

  printf(" symmetric conjugate a=vhv~:\n");
  matprt(a,n,n,fmt);
/* check transform by inversion */
  otrsm(v,u,a,n);
  printf(" symmetric conjugate uau~:\n");
  matprt(v,n,n,fmt);
}
/* Test output

 matrix h:
   2.2532  -0.6303   0.9402   0.7410
  -0.6303   2.6266   0.3221   0.1333
   0.9402   0.3221   3.1949   0.3211
   0.7410   0.1333   0.3211   1.9253
 matrix vhv~:
   1.0000  -0.0000  -0.0000  -0.0000
  -0.0000   2.0000  -0.0000  -0.0000
  -0.0000  -0.0000   3.0000   0.0000
  -0.0000  -0.0000   0.0000   4.0000
 symmetric conjugate a=vhv~:
   1.0000  -0.0000  -0.0000  -0.0000
  -0.0000   2.0000  -0.0000  -0.0000
  -0.0000  -0.0000   3.0000   0.0000
  -0.0000  -0.0000   0.0000   4.0000
 symmetric conjugate uau~:
   2.2532  -0.6303   0.9402   0.7410
  -0.6303   2.6266   0.3221   0.1333
   0.9402   0.3221   3.1949   0.3211
   0.7410   0.1333   0.3211   1.9253
*/
