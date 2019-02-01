/*  txdiv.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  xdiv  xmul

    Uses:  dubtox

    Prompted input:  at prompt  'x y? : '
                         enter  x -> real: numerator
                                y -> real: denominator (y!=0)
                                y = 0 terminates session
*/
#define XMATH 1
#include "ccmath.h"
int decd=30;
void main(void)
{ struct xpr f,s,t;
  double x,y; int k;
  while(1){
    fprintf(stderr,"x y? : ");
    scanf("%lf %lf",&x,&y);
	if(y==0.) break;
    s=dubtox(x); t=dubtox(y);
    printf(" inputs: s= "); prxpr(s,decd);
    printf("         t= "); prxpr(t,decd);
    
/* extended precision division */
    f=xdiv(s,t); printf("s/t: "); prxpr(f,decd);

/* check division with a multiply */
    s=xmul(f,t); printf("  s: "); prxpr(s,decd);
   }
}
/*  Test output

 inputs: s=   1.000000000000000000000000000000e+0
         t=   3.000000000000000000000000000000e+0
s/t:   3.333333333333333333333333333333e-1
  s:   1.000000000000000000000000000000e+0
 inputs: s=   4.000000000000000000000000000000e+0
         t=   7.000000000000000000000000000000e+0
s/t:   5.714285714285714285714285714286e-1
  s:   4.000000000000000000000000000000e+0
 inputs: s=   2.000000000000000000000000000000e+0
         t=   1.600000000000000000000000000000e+1
s/t:   1.250000000000000000000000000000e-1
  s:   2.000000000000000000000000000000e+0
*/
