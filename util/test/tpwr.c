/*  tpwr.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  pwr
*/
#include "ccmath.h"
void main(void)
{ double y; int n;
  printf("  Test of Integer Powers Function\n");
  printf("     values of 3^n and 3^-n\n");

/* compute integer powers of y */
  for(n=1,y=3.; n<8 ;++n)
     printf(" %d  %f  %15.12f\n",n,pwr(y,n),pwr(y,-n));
}
/*  Test output

  Test of Integer Powers Function
     values of 3^n and 3^-n
 1  3.000000   0.333333333333
 2  9.000000   0.111111111111
 3  27.000000   0.037037037037
 4  81.000000   0.012345679012
 5  243.000000   0.004115226337
 6  729.000000   0.001371742112
 7  2187.000000   0.000457247371
*/
