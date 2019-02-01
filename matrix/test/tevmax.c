/*  tevmax.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
   Test:  evmax

   Uses:  vmul  vnrm  matprt

   Optional input parameter: n -> size of real Hilbert matrix
                             (defaults to n=5)
*/
#include "ccmath.h"
int n=5;
void main(int na,char **av)
{ int i,j; double *p,*a,*evc,*u;
  double ee;
  if(na==2) n=atoi(*++av);
  a=(double *)calloc(n*n+n+n,sizeof(double));
  evc=a+n*n; u=evc+n;
  for(i=0,p=a; i<n ;++i){
    for(j=0; j<n ;++j) *p++ =1./(double)(i+j+1);
   }
  printf("Test of Maximun Eigenvalue Function\n\n");
  printf("    dimension: %d\n",n);
/* compute eigenvalue of maximum modulus and the corresponding
   eigenvector for a real symmetric matrix */
  ee=evmax(a,evc,n);

  printf("max eigenvalue: ev= %e\n",ee);
  printf("eigenvector:\n");
  matprt(evc,1,n," %6.3f");
/* check eigenvalue and vector */
  vmul(u,a,evc,n);
  printf(" vector a*evc:\n");
  matprt(u,1,n," %6.3f");
  ee=vnrm(u,evc,n);
  printf(" evc'*a*evc = %9.6f\n",ee);
}
/* Test output

Test of Maximun Eigenvalue Function

    dimension: 5
max eigenvalue: ev= 1.567051e+00
eigenvector:
  0.768  0.446  0.322  0.253  0.210
 vector a*evc:
  1.203  0.699  0.504  0.397  0.329
 evc'*a*evc =  1.567051
*/
