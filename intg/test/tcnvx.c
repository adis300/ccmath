/*  tcnvx.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  fintg
*/
#include <math.h>
#include "ccmath.h"
/* convergence test threshold */
double te=1.e-12;
/* initial convolution displacement and increment*/
double r=0.,dr=0.1;
char fi[]="norm(x-r)";
double cs=0.398942280402;
void main(void)
{ double a,b,te=1.e-12;
  double fnrm(double x);
  printf(" Convolution Integrals Test\n\n");
  printf("   convergence threshold= %e\n\n",te);
  printf(" %s over x : [-1, 1]\n",fi);
  for(a= -1.,b=1.; r<2.0001 ;r+=dr){
    printf(" r=%10.6f  I= %12.7f\n",r,fintg(a,b,25,te,fnrm));
   }
}
/* Normal probability density of x-r.
   Note that the parameter r is delivered as an external
   to the standard format integrand fnrm.
*/
double fnrm(double x)
{ double ldexp();
  x-=r;
  return exp(-ldexp(x*x,-1))*cs;
}
/* Test output

 Convolution Integrals Test

   convergence threshold= 1.000000e-12

 norm(x-r) over x : [-1, 1]
 r=  0.000000  I=    0.6826895
 r=  0.100000  I=    0.6802738
 r=  0.200000  I=    0.6730749
 r=  0.300000  I=    0.6612359
 r=  0.400000  I=    0.6449902
 r=  0.500000  I=    0.6246553
 r=  0.600000  I=    0.6006224
 r=  0.700000  I=    0.5733460
 r=  0.800000  I=    0.5433294
 r=  0.900000  I=    0.5111113
 r=  1.000000  I=    0.4772499
 r=  1.100000  I=    0.4423077
 r=  1.200000  I=    0.4068368
 r=  1.300000  I=    0.3713645
 r=  1.400000  I=    0.3363807
 r=  1.500000  I=    0.3023279
 r=  1.600000  I=    0.2695919
 r=  1.700000  I=    0.2384967
 r=  1.800000  I=    0.2093003
 r=  1.900000  I=    0.1821943
 r=  2.000000  I=    0.1573054
*/
