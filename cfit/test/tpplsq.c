/*  tpplsq.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  pplsq
*/
#include "ccmath.h"
#define ND 100
#define NP 5
double x[ND],y[ND];
void main(void)
{ double dx,z;
/* set dimensions of arrays
   used by plsq for output */
  double bc[NP];
  int n,np,j;
  printf("     Test of Polynominal Least Squares\n");
/* set number of input points */
  n=ND;
/*
  The test fit inputs are the values of a polynominal of
  degree 4, defined in this loop.
*/
  for(j=0,dx=.1; j<n ;++j){
    z=(x[j]=j*dx); y[j]=1.+z*(1.+z*(2.+z*(-3.+.5*z))); }
/* set maximum fit order */
  np=NP;

/* Simplified polynominal least squares */  
  z=pplsq(x,y,n,bc,np);

  printf(" fit:"); matprt(bc,1,np," %9.4f");
  printf("  ssq= %e\n",z);
}
/* Test output

     Test of Polynominal Least Squares
 fit:    1.0000    1.0000    2.0000   -3.0000    0.5000
  ssq= 3.784372e-24
*/
