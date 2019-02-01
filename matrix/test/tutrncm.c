/*  tutrncm.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  utrncm  utrnhm

    Uses:  hconj  unitary  hmgen  cmcpy  cmprt

    Input parameter:  n  -> size of matrices is n by n
*/
#include "ccmath.h"
void main(int na,char **av)
{ int n,m,k; Cpx *a,*u,*v,*h,*s;
  double *q; unsigned int seed;
  if(na!=2){ printf("para: dim\n"); exit(1);}
  n=atoi(*++av); m=n*n;
  a=(Cpx *)calloc(4*m,sizeof(Cpx));
  q=(double *)calloc(n,sizeof(double));
  h=a+m; u=h+m; v=u+m;
  seed=123456789; setunfl(seed);
  for(k=1; k<=n ;++k) q[k-1]=(double)k;
  unitary(u,n); hmgen(h,q,u,n);
  printf(" matrix h:\n");
  cmprt(h,n,n,"(%7.3f,%7.3f)");
  cmcpy(v,u,n*n); hconj(v,n);

/* transform of h by the unitary matrix v */
  utrncm(a,v,h,n);

  printf(" matrix conjugate vhv^:\n");
  cmprt(a,n,n,"(%7.3f,%7.3f)");

/* transform Hermitian h by the unitary matrix v */
  utrnhm(a,v,h,n);

  printf(" hermitian conjugate a=vhv^:\n");
  cmprt(a,n,n,"(%7.3f,%7.3f)");
/* check transform by inversion */
  utrnhm(v,u,a,n);
  printf(" hermitian conjugate uau^:\n");
  cmprt(v,n,n,"(%7.3f,%7.3f)");
}
/* Test output

 matrix h:
(  2.740, -0.000)(  0.313,  0.438)( -0.587, -0.205)(  0.179, -0.000)
(  0.313, -0.438)(  1.857, -0.000)(  0.457, -0.444)( -0.375, -0.091)
( -0.587,  0.205)(  0.457,  0.444)(  2.482,  0.000)( -0.955,  0.000)
(  0.179,  0.000)( -0.375,  0.091)( -0.955, -0.000)(  2.921, -0.000)
 matrix conjugate vhv^:
(  1.000, -0.000)( -0.000, -0.000)(  0.000, -0.000)(  0.000,  0.000)
( -0.000,  0.000)(  2.000, -0.000)(  0.000, -0.000)(  0.000,  0.000)
(  0.000,  0.000)(  0.000,  0.000)(  3.000, -0.000)(  0.000, -0.000)
( -0.000,  0.000)(  0.000, -0.000)(  0.000,  0.000)(  4.000,  0.000)
 hermitian conjugate a=vhv^:
(  1.000, -0.000)( -0.000, -0.000)(  0.000, -0.000)(  0.000,  0.000)
( -0.000,  0.000)(  2.000, -0.000)(  0.000, -0.000)(  0.000,  0.000)
(  0.000,  0.000)(  0.000,  0.000)(  3.000, -0.000)(  0.000, -0.000)
(  0.000, -0.000)(  0.000, -0.000)(  0.000,  0.000)(  4.000,  0.000)
 hermitian conjugate uau^:
(  2.740, -0.000)(  0.313,  0.438)( -0.587, -0.205)(  0.179, -0.000)
(  0.313, -0.438)(  1.857, -0.000)(  0.457, -0.444)( -0.375, -0.091)
( -0.587,  0.205)(  0.457,  0.444)(  2.482, -0.000)( -0.955,  0.000)
(  0.179,  0.000)( -0.375,  0.091)( -0.955, -0.000)(  2.921, -0.000)
*/
