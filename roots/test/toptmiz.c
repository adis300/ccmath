/*  toptmiz.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  optmiz

    A new function can be specified by setting the system dimension ND
    and coding a new 'double func(x)' to evaluate the criteria function,
    with x the parameter vector.
*/
#include "ccmath.h"
#define ND 2
char nm[]="Rosenbrock";
void main(void)
{ double x[ND],de,test;
  double func(double *x);
  int i,n=ND,max=60;
  test=1.e-12; de=1.e-9;
  printf("     Test of Optimizer (%s function)\n",nm);
  printf(" max iterations = %d\n",max);
  printf(" convergence threshold= %8.2e\n",test);
  printf(" derivative interval= %8.2e\n",de);
  fprintf(stderr," input initial vector (%d components)\n",n);
  for(i=0; i<n ;) scanf("%lf",x+i++);
  printf(" input vector: ");
  for(i=0; i<n ;) printf("  %f",x[i++]); printf("\n");
  if(optmiz(x,n,func,de,test,max)) printf(" optimal solution\n");
  else printf(" convergence failure\n");
  printf(" x-vector: ");
  for(i=0; i<n ;) printf("  %f",x[i++]); printf("\n");    
  printf(" minimum F(x)= %e\n",func(x));
}
/* Rosenbrock criteria function */
double func(double *x)
{ double f,y;
  y=x[0]; f=1.-y; y=x[1]-y*y;
  return 100.*y*y+f*f;
}
/* Test output

     Test of Optimizer (Rosenbrock function)
 max iterations = 60
 convergence threshold= 1.00e-12
 derivative interval= 1.00e-09
 input vector:   -1.000000  1.000000
 optimal solution
 x-vector:   1.000000  1.000000
 minimum F(x)= 6.019086e-17
*/
