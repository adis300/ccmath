/*  tplsq.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  plsq  psqcf  psqvar
*/
#include "ccmath.h"
#define ND 100
#define NP 5
double x[ND],y[ND];
void main(void)
{ double dx,z;
/* set dimensions of arrays
   used by plsq for output */
  double ssq[NP]; Opol cf[NP];
  double bc[NP],var[NP*NP];
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

/* compute polynominal fits to maximum order */
  plsq(x,y,n,cf,ssq,np);
  for(j=0; j<np ;++j)
    printf(" fit order: %d  ssq= %15.6f\n",j+1,ssq[j]);
  printf(" orthogonal polynominal cf df hs\n");
  for(j=0; j<np ;++j)
    printf(" %d  %10.6f  %10.6f  %10.6f\n",j,cf[j].cf,cf[j].df,cf[j].hs);
  for(j=2; j<=np ;++j){
/* compute polynominal coefficients */	  
    psqcf(bc,cf,j);
    z=ssq[j-1]/(double)(n-j);
/* compute coefficient variances */    
    psqvar(var,z,cf,j);
    printf(" fit: %d\n",j);
    printf("  coefficients:\n"); matprt(bc,1,j," %9.4f");
    printf("  coefficient variance matrix:\n");
    matprt(var,j,j," %10.5f");
   }
}
/* Test output

     Test of Polynominal Least Squares
 fit order: 1  ssq= 29236433.219926
 fit order: 2  ssq= 11394956.837989
 fit order: 3  ssq=  1754496.905063
 fit order: 4  ssq=    56519.429092
 fit order: 5  ssq=        0.000000
 orthogonal polynominal cf df hs
 0  311.711665    4.950000  100.000000
 1  146.328100    4.950000    8.332500
 2   41.667143    4.950000    6.664000
 3    6.900000    4.950000    6.422786
 4    0.500000    0.000000    6.339048
 fit: 2
  coefficients:
 -412.6124  146.3281
  coefficient variance matrix:
 4581.92849 -690.74299
 -690.74299  139.54404
 fit: 3
  coefficients:
  261.1453 -266.1766   41.6671
  coefficient variance matrix:
 1564.46653 -628.90480   52.67209
 -628.90480  340.96467  -32.24822
   52.67209  -32.24822    3.25740
 fit: 4
  coefficients:
  -63.5322  137.5493  -60.7979    6.9000
  coefficient variance matrix:
   87.47372  -65.92054   13.24958   -0.77678
  -65.92054   67.61380  -15.39322    0.96590
   13.24958  -15.39322    3.74640   -0.24514
   -0.77678    0.96590   -0.24514    0.01651
 fit: 5
  coefficients:
    1.0000    1.0000    2.0000   -3.0000    0.5000
  coefficient variance matrix:
    0.00000   -0.00000    0.00000   -0.00000    0.00000
   -0.00000    0.00000   -0.00000    0.00000   -0.00000
    0.00000   -0.00000    0.00000   -0.00000    0.00000
   -0.00000    0.00000   -0.00000    0.00000   -0.00000
    0.00000   -0.00000    0.00000   -0.00000    0.00000
*/
