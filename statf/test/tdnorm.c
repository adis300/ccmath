/*  tdnorm.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  qnorm  pctn
*/
#include "ccmath.h"
void main(void)
{ double z,dz,f,d;
  printf("     Test of Normal Distribution\n");
  printf("    z         Q(z)         Pct(Q)\n");
  for(z= -2.5,dz=.25; z<2.6 ;z+=dz){

/* compute distribution function for standard normal */
    f=qnorm(z);

/* compute the percentage point to check the distribution */
    d=pctn(f);

    printf(" %6.2f  %12.8f  %12.8f\n",z,f,d);
   }
}
/*  Test output

     Test of Normal Distribution
    z         Q(z)         Pct(Q)
  -2.50    0.99379033   -2.50000000
  -2.25    0.98777553   -2.25000000
  -2.00    0.97724987   -2.00000000
  -1.75    0.95994084   -1.75000000
  -1.50    0.93319280   -1.50000000
  -1.25    0.89435023   -1.25000000
  -1.00    0.84134475   -1.00000000
  -0.75    0.77337265   -0.75000000
  -0.50    0.69146246   -0.50000000
  -0.25    0.59870633   -0.25000000
   0.00    0.50000000    0.00000000
   0.25    0.40129367    0.25000000
   0.50    0.30853754    0.50000000
   0.75    0.22662735    0.75000000
   1.00    0.15865525    1.00000000
   1.25    0.10564977    1.25000000
   1.50    0.06680720    1.50000000
   1.75    0.04005916    1.75000000
   2.00    0.02275013    2.00000000
   2.25    0.01222447    2.25000000
   2.50    0.00620967    2.50000000
*/
