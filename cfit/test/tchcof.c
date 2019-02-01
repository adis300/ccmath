/*  tchcof.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  chcof
*/
#include "ccmath.h"
#include <math.h>
char fnam[]="exp(x)";
void main(void)
{ double c[20],fun(double x);
  int m=16,j;
  printf(" Test of Tchebycheff Coefficient Generator\n");
  printf("     function = %s\n",fnam);
  chcof(c,m,fun);
  for(j=0; j<=m ;++j) printf(" %2d %9.7f\n",j,c[j]);
}
/* other functions whose Tchebycheff series is
   desired can be substituted below. */
double fun(double x)
{ double y=exp(x);
  return y;
}
/* Test output

 Test of Tchebycheff Coefficient Generator
     function = exp(x)
  0 2.5321318
  1 1.1303182
  2 0.2714953
  3 0.0443368
  4 0.0054742
  5 0.0005429
  6 0.0000450
  7 0.0000032
  8 0.0000002
  9 0.0000000
 10 0.0000000
 11 0.0000000
 12 0.0000000
 13 0.0000000
 14 0.0000000
 15 -0.0000000
 16 0.0000000
*/
