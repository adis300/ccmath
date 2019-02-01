/*  tdrbes.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  drbes

          Types:  j -> dJ(v,x)/dx
                  y -> dN(v,x)/dx
                  i -> dI(v,x)/dx
                  k -> dK(v,x)/dx
          Orders may be altered by changing values of v
          within the switch statement.
*/
#include "ccmath.h"
#include <math.h>
void main(void)
{ double v,x,dx,f; int m; char t[2];
  printf("     Bessel Function Derivatives Test\n");
  for(m=0; m<4 ;++m){
    switch(m){
      case 0: printf(" dJ(v,x)/dx\n");
			  t[0]='j'; v=0.; break;
      case 1: printf(" dN(v,x)/dx\n");
			  t[0]='y'; v=2.3; break;
      case 2: printf(" dI(v,x)/dx\n");
			  t[0]='i'; v=4.5; break;
      case 3: printf(" dK(v,x)/dx\n");
			  t[0]='k'; v=3.25; break;
     }
    printf(" order v= %.2f\n",v);
    for(x=dx=1.; x<5.1 ;x+=dx){

/* compute Bessel function derivatives */
      f=drbes(x,v,t[0],NULL);
      printf(" %6.2f   %12.8f\n",x,f);
	 }
	printf("\n");
   }
}
/* Test output

     Bessel Function Derivatives Test
 dJ(v,x)/dx
 order v= 0.00
   1.00    -0.44005059
   2.00    -0.57672481
   3.00    -0.33905896
   4.00     0.06604333
   5.00     0.32757914

 dN(v,x)/dx
 order v= 2.30
   1.00     4.23306040
   2.00     0.56127971
   3.00     0.41100314
   4.00     0.34183666
   5.00     0.11196541

 dI(v,x)/dx
 order v= 4.50
   1.00     0.00405527
   2.00     0.05547528
   3.00     0.30962054
   4.00     1.25491869
   5.00     4.37349196

 dK(v,x)/dx
 order v= 3.25
   1.00   -37.66688974
   2.00    -1.70426458
   3.00    -0.23443446
   4.00    -0.04821152
   5.00    -0.01202528

*/
