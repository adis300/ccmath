/*  tbes.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  jbes, nbes, ibes, and kbes

           The order v for each can be altered within the switch
           statement.

           The range and interval of evaluation are determined by
           the variables xmx and dx.
*/
#include "ccmath.h"
#include <math.h>
void main(void)
{ double (*fun)(double a,double b);
  double x,dx,f,v,xmx; int j;
  printf("     Test of Bessel Functions\n");
  xmx=12.; dx=1.;
  for(j=0; j<4 ;++j){
	switch(j){
      case 0: fun=jbes; printf("     J(v,x)\n");
			  v=1.80; x=0.; break;
      case 1: fun=nbes; printf("     N(v,x)\n");
			  v=3.5; x=1.; break;
      case 2: fun=ibes; printf("     I(v,x)\n");
			  v=2.7; x=1.; break;
      case 3: fun=kbes; printf("     K(v,x)\n");
			  v=4.6; x=1.; break;
	 }
    printf(" order v= %.2f\n",v);
    for(; x<=xmx ; x+=dx){

/* compute Bessel function selected by switch */
      f=(*fun)(v,x);
      printf(" %7.2f   %17.10f\n",x,f);
	 }
	printf("\n");
   }
}
/* Test output

     Test of Bessel Functions
     J(v,x)
 order v= 1.80
    0.00        0.0000000000
    1.00        0.1564953153
    2.00        0.4096192323
    3.00        0.4956809158
    4.00        0.3044283399
    5.00       -0.0411746941
    6.00       -0.2907158917
    7.00       -0.2746423137
    8.00       -0.0395702153
    9.00        0.1999476991
   10.00        0.2461068874
   11.00        0.0787106587
   12.00       -0.1415053711

     N(v,x)
 order v= 3.50
    1.00      -13.2794437122
    2.00       -1.6749282998
    3.00       -0.7020759742
    4.00       -0.3489020979
    5.00       -0.0275520680
    6.00        0.2379492346
    7.00        0.3224108545
    8.00        0.1840993147
    9.00       -0.0672543256
   10.00       -0.2405238622
   11.00       -0.2101775567
   12.00       -0.0152197192

     I(v,x)
 order v= 2.70
    1.00        0.0394595060
    2.00        0.3118860810
    3.00        1.2715236097
    4.00        4.1546417707
    5.00       12.3406324265
    6.00       34.9860623925
    7.00       96.7606070579
    8.00      263.9019977303
    9.00      713.8835083590
   10.00     1921.6066961826
   11.00     5156.9166970254
   12.00    13813.9614128165

     K(v,x)
 order v= 4.60
    1.00      151.5056564064
    2.00        5.1315724152
    3.00        0.5856692563
    4.00        0.1052128995
    5.00        0.0236907369
    6.00        0.0060764387
    7.00        0.0016924427
    8.00        0.0004983860
    9.00        0.0001526807
   10.00        0.0000481574
   11.00        0.0000155300
   12.00        0.0000050955

*/
