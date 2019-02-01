/*  tvops1.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  dotp  scalv  trvec  crossp  leng

    Uses:  matprt
*/
#include "ccmath.h"
double x[]={ 1., 3.,4.};
double y[]={ 4., 2.,-2.};
void main(void)
{ double s,z[3];
  printf("     Vector Operations Test #1\n");
  printf(" input vectors: x and y\n");
  matprt(x,1,3," %.3f"); matprt(y,1,3," %.3f");
  printf(" dot product x.y= %f\n",dotp(x,y,3));
  s=2.; scalv(y,s,3);
  printf(" scale y by 2:\n"); matprt(y,1,3," %.3f");
  s=1./s; scalv(y,s,3);
  trvec(z,x,y,3); printf(" z=x+y: "); matprt(z,1,3," %.3f");
  crossp(z,x,y); printf("  cross product x^y:\n");
  matprt(z,1,3," %.3f");
  printf(" vector lengths:\n");
  printf(" |x|= %f\n",leng(x,0L,3)); printf(" |y|= %f\n",leng(y,0L,3));
  printf(" |x-y|= %f\n",leng(x,y,3));
}
/* Test output

     Vector Operations Test #1
 input vectors: x and y
 1.000 3.000 4.000
 4.000 2.000 -2.000
 dot product x.y= 2.000000
 scale y by 2:
 8.000 4.000 -4.000
 z=x+y:  5.000 5.000 2.000
  cross product x^y:
 -14.000 18.000 -10.000
 vector lengths:
 |x|= 5.099020
 |y|= 4.898979
 |x-y|= 6.782330
*/
