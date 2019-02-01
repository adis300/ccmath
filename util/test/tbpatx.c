/*  tbpatx.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  bpatx

    Uses:  prxpr  dubtox  xdiv
*/
#define XMATH 1
#include "ccmath.h"
void main(void)
{ struct xpr x; int i;
  printf("    Test of Extended Precision Bit-Patterns\n");
  x=xdiv(dubtox(2.),dubtox(7.));
/* print extended precision number in ascii format */
  printf(" x= "); prxpr(x,30);

/* show bit pattern of extended precision number */
  printf("x: "); bpatx(x);

  printf("x-hex:");
  for(i=0; i<8 ;) printf(" 0x%x",x.nmm[i++]);
  printf("\n");
}
/*  Test output

    Test of Extended Precision Bit-Patterns
 x=   2.857142857142857142857142857143e-1
x: 0011111111111101^1.001001001001001001001001001001001001001001001001001
    001001001001001001001001001001001001001001001001001001001001
x-hex: 0x3ffd 0x9249 0x2492 0x4924 0x9249 0x2492 0x4924 0x9249
*/
