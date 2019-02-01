/*  tgaml.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  gaml
*/
#include "ccmath.h"
#include <math.h>
void main(void)
{ double x,y,z;
  printf("     Test of Gamma Function Evaluation\n");
  printf("    x       log(gamma(x))            gamma(x)\n");  
  for(x=.5; x<10.1 ; x+=.5){

/* compute the logarithm of the gamma function and the gamma function */
    y=gaml(x); z=exp(y);

    printf(" %6.3f  %16.12f  %19.8f\n",x,y,z);
   }
}
/* Test output

     Test of Gamma Function Evaluation
    x       log(gamma(x))            gamma(x)
  0.500    0.572364942925           1.77245385
  1.000    0.000000000000           1.00000000
  1.500   -0.120782237635           0.88622693
  2.000    0.000000000000           1.00000000
  2.500    0.284682870473           1.32934039
  3.000    0.693147180560           2.00000000
  3.500    1.200973602347           3.32335097
  4.000    1.791759469228           6.00000000
  4.500    2.453736570842          11.63172840
  5.000    3.178053830348          24.00000000
  5.500    3.957813967619          52.34277778
  6.000    4.787491742782         120.00000000
  6.500    5.662562059857         287.88527782
  7.000    6.579251212010         720.00000000
  7.500    7.534364236759        1871.25430580
  8.000    8.525161361065        5040.00000000
  8.500    9.549267257301       14034.40729348
  9.000   10.604602902745       40320.00000000
  9.500   11.689333420797      119292.46199461
 10.000   12.801827480081      362880.00000000
*/
