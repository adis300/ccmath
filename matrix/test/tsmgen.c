/*  tsmgen.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  smgen  ortho

    Uses:  matprt

    Input parameter: n -> size of matrix is n by n
*/
#include "ccmath.h"
unsigned int seed=123456789;
void main(int na,char **av)
{ double *sm,*om,*p;
  int i,j,n; double *e,s;
  if(na!=2){ printf("para: size\n"); exit(1);}
  n=atoi(*++av);
  sm=(double *)calloc(n*n,sizeof(double));
  om=(double *)calloc(n*n,sizeof(double));
  e=(double *)calloc(n,sizeof(double));
/* initialize real eigenvalues */
  for(i=0,s=1.; i<n ;++i,s+=.5) e[i]=s;
  setunfl(seed);

/*  generate an orthogonal matrix */
  ortho(om,n);

  printf(" orthogonal matrix\n");
  matprt(om,n,n," %8.3f");

/* generate a symmetric matrix with the specified eigenvalues */
  smgen(sm,e,om,n);

  printf(" symmetric matrix:\n");
  matprt(sm,n,n," %8.3f");
}
/* Test output

 orthogonal matrix
   -0.127   -0.041    0.064   -0.101   -0.984
   -0.385    0.108    0.144   -0.893    0.146
    0.690    0.509   -0.392   -0.316   -0.104
   -0.595    0.442   -0.639    0.206   -0.004
    0.072   -0.729   -0.643   -0.222    0.002
 symmetric matrix:
    2.956   -0.145    0.216   -0.073    0.003
   -0.145    2.266    0.364   -0.345    0.166
    0.216    0.364    1.454    0.266    0.171
   -0.073   -0.345    0.266    1.570    0.181
    0.003    0.166    0.171    0.181    1.753
*/
