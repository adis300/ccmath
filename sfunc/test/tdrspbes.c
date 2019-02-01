/*  tdrspbes.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  drspbes

               j ->  dj(v,x)/dx
               k ->  dk(v,x)/dx
               y ->  dy(v,x)/dx

            The order n for each derivative can be altered by
            resetting n within the switch statement.
*/
#include "ccmath.h"
#include <math.h>
void main(void)
{ double x,dx,xmx,f; char t[2]; int n,m;
  printf("     Sperical Bessel Function Derivative Test\n");
  xmx=11.; dx=2.;
  for(m=0; m<4 ;++m){
    switch(m){
      case 0: printf(" dj(n,x)/dx\n");
			  t[0]='j'; n=0; x=0.; break;
      case 1: printf(" dy(n,x)/dx\n");
			  t[0]='y'; n=3; x=2.; break;
      case 2: printf(" dk(n,x)/dx\n");
			  t[0]='k'; n=2; x=2.; break;
	  case 3: printf(" dk(n,x)/dx\n");
			  t[0]='k'; n= -4; x=2.; break;
	 }
	printf("  order = %d\n",n);
    for(; x<xmx ;x+=dx){

/* compute derivative of spherical Bessel function */
      f=drspbes(x,n,t[0],NULL);
      printf(" %6.2f   %12.8f\n",x,f);
	 }
	printf("\n");
   }
}
/*  Test output

     Sperical Bessel Function Derivative Test
 dj(n,x)/dx
  order = 0
   0.00     0.00000000
   2.00    -0.43539777
   4.00    -0.11611075
   6.00     0.16778992
   8.00    -0.03364623
  10.00    -0.07846694

 dy(n,x)/dx
  order = 3
   2.00     2.23474169
   4.00     0.22777107
   6.00     0.08881071
   8.00    -0.10449958
  10.00    -0.02693831

 dk(n,x)/dx
  order = 2
   2.00    -0.43138122
   4.00    -0.01237737
   6.00    -0.00080904
   8.00    -0.00006953
  10.00    -0.00000681

 dk(n,x)/dx
  order = -4
   2.00    -0.20300292
   4.00    -0.00915782
   6.00    -0.00068854
   8.00    -0.00006290
  10.00    -0.00000636

*/
