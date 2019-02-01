/*  thmgen.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  hmgen  unitary

    Uses:  cmprt

    Input parameter: n -> size of matrix is n by n
*/
#include "ccmath.h"
unsigned int seed=123456789;
void main(int na,char **av)
{ Cpx *h,*u,*p;
  int i,j,n; double *e,s;
  if(na!=2){ printf("para: size\n"); exit(1);}
  n=atoi(*++av);
  h=(Cpx *)calloc(n*n,sizeof(Cpx));
  u=(Cpx *)calloc(n*n,sizeof(Cpx));
  e=(double *)calloc(n,sizeof(double));
/* initialize real eigenvalues */
  for(i=0,s=1.; i<n ;++i,s+=.5) e[i]=s;
  setunfl(seed);

/*  generate a unitary matrix */
  unitary(u,n);

  printf(" unitary matrix\n");
  cmprt(u,n,n,"(%8.3f,%8.3f)");

/* generate a Hermitian matrix with the specified eigenvalues */
  hmgen(h,e,u,n);

  printf(" hermitian matrix:\n");
  cmprt(h,n,n,"(%8.3f,%8.3f)");
}
/* Test output

 unitary matrix
(   0.296,   0.253)(  -0.244,   0.070)(  -0.182,   0.803)(  -0.051,   0.323)
(  -0.632,   0.251)(   0.497,  -0.111)(   0.211,   0.439)(  -0.040,  -0.199)
(   0.489,   0.305)(   0.348,   0.357)(  -0.153,   0.018)(   0.018,  -0.629)
(   0.105,   0.207)(   0.599,   0.263)(  -0.081,  -0.234)(   0.006,   0.676)
 hermitian matrix:
(   1.870,  -0.000)(   0.157,   0.219)(  -0.294,  -0.102)(   0.090,  -0.000)
(   0.157,  -0.219)(   1.429,  -0.000)(   0.228,  -0.222)(  -0.187,  -0.046)
(  -0.294,   0.102)(   0.228,   0.222)(   1.741,  -0.000)(  -0.478,   0.000)
(   0.090,   0.000)(  -0.187,   0.046)(  -0.478,  -0.000)(   1.960,  -0.000)
*/
