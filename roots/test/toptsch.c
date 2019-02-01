/*  toptsch.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  optsch

    For other functions replace descriptor dfn, limit arguments
    to optsch, and define a new test function ft(x).
*/
#include "ccmath.h"
#include <math.h>
char dfn[]="1-sin(x) on 0 to Pi";
void main(void)
{ double xopt,dx;
  double ft(double x);
  printf("     Test of Optimum Line Search\n");
  printf(" minimum of %s\n",dfn);
  xopt=optsch(ft,0.,3.14159,1.e-14);
  printf(" minimum at  x = %10.6f\n",xopt);
  dx=.0001;
  printf("     test:      f(x)= %e\n",ft(xopt));
  printf("          f(x+.0001)= %e\n",ft(xopt+dx));
  printf("          f(x-.0001)= %e\n",ft(xopt-dx));
}
/* Function to be optimized */
double ft(double x)
{ return 1.-sin(x);
}
/* Test output

     Test of Optimum Line Search
 minimum of 1-sin(x) on 0 to Pi
 minimum at  x =   1.570796
     test:      f(x)= 4.499439e-18
          f(x+.0001)= 4.999700e-09
          f(x-.0001)= 5.000300e-09
*/
