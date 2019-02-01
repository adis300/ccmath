/*  tfintg.c    CCMATH mathematics library source code.
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
/* Convergence test parameter */
double te=1.e-12;
double Pi=3.14159265358979324;
char in1[]="normal probability density";
char in2[]="1/(1+x*x)";
void main(void)
{ double a,b; int j;
  double fnrm(double x),frf(double x);
  printf("     Test of Numerical Integration\n\n");
  printf("   convergence threshold= %.2e\n",te);
  printf("\n integrand 1 = %s\n",in1);
  for(j=0,a=0.,b=1.; j<5 ;++j,b+=1.)
    printf(" %f to %f  I= %12.8f\n",a,b,fintg(a,b,25,te,fnrm));
  printf("\n integrand 2 = %s\n",in2);
  for(j=0,a=0.,b=1.; j<5 ;++j,b+=1.)
    printf(" %f to %f  I= %12.8f\n",a,b,fintg(a,b,25,te,frf));
}
/* test function for rational integrand */
double frf(double x)
{ return 1./(1.+x*x);
}
/* test function for normal probability density */
double fnrm(double x)
{ return exp(-x*x/2.)/sqrt(2.*Pi);
}
/*  Test output

     Test of Numerical Integration

   convergence threshold= 1.00e-12

 integrand 1 = normal probability density
 0.000000 to 1.000000  I=   0.34134475
 0.000000 to 2.000000  I=   0.47724987
 0.000000 to 3.000000  I=   0.49865010
 0.000000 to 4.000000  I=   0.49996833
 0.000000 to 5.000000  I=   0.49999971

 integrand 2 = 1/(1+x*x)
 0.000000 to 1.000000  I=   0.78539816
 0.000000 to 2.000000  I=   1.10714872
 0.000000 to 3.000000  I=   1.24904577
 0.000000 to 4.000000  I=   1.32581766
 0.000000 to 5.000000  I=   1.37340077
*/
