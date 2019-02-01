/*  tpsi.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  psi  psih
*/
#include "ccmath.h"
void main(void)
{ double h,p,ph; int i;
  printf("    Test of the psi Functions\n");
  for(i=1; i<=16 ;++i){
    h=(double)i+0.5;

/* evaluate psi functions for integer and half-integer argument */
    p=psi(i); ph=psih(h);

    printf(" psi(%2d)= %12.8f  psi(%4.1f)= %12.8f\n",i,p,h,ph);
   }
}
/*  Test output

    Test of the psi Functions
 psi( 1)=  -0.57721566  psi( 1.5)=   0.03648997
 psi( 2)=   0.42278434  psi( 2.5)=   0.70315664
 psi( 3)=   0.92278434  psi( 3.5)=   1.10315664
 psi( 4)=   1.25611767  psi( 4.5)=   1.38887093
 psi( 5)=   1.50611767  psi( 5.5)=   1.61109315
 psi( 6)=   1.70611767  psi( 6.5)=   1.79291133
 psi( 7)=   1.87278434  psi( 7.5)=   1.94675748
 psi( 8)=   2.01564148  psi( 8.5)=   2.08009082
 psi( 9)=   2.14064148  psi( 9.5)=   2.19773788
 psi(10)=   2.25175259  psi(10.5)=   2.30300103
 psi(11)=   2.35175259  psi(11.5)=   2.39823913
 psi(12)=   2.44266168  psi(12.5)=   2.48519565
 psi(13)=   2.52599501  psi(13.5)=   2.56519565
 psi(14)=   2.60291809  psi(14.5)=   2.63926973
 psi(15)=   2.67434666  psi(15.5)=   2.70823524
 psi(16)=   2.74101333  psi(16.5)=   2.77275137
*/
