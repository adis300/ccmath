/*  tsecrt.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  secrt

    To find roots of another function, redefine 'double fa(x)'.
*/
#include "ccmath.h"
#include <math.h>
char fdn[]="cos(x)-x";
void main(void)
{ double x,dx,fa(double x);
  printf("     Test of Secant Root Function\n");
  printf(" input function: %s\n",fdn);
/*  starting values x,x+dx defined here */
  x=1.; dx=.1;
  printf(" input estimated root = %f increment = %f\n",x,dx);
  x=secrt(fa,x,dx,1.e-14);
  printf(" solution to F(x)=0 : x = %18.12f\n",x);
  printf("          test F(x) = %e\n",fa(x));
}
/* function for which root is desired */
double fa(double x)
{ return cos(x)-x;
}
/* Test output

     Test of Secant Root Function
 input function: cos(x)-x
 input estimated root = 1.000000 increment = 0.100000
 solution to F(x)=0 : x =     0.739085133215
          test F(x) = -5.128276e-17
*/
