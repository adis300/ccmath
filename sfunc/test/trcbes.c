/*  trcbes.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  rcbes  setrcb

    Uses:  (implicit) jbes  nbes  ibes  kbes

*/
#include "ccmath.h"
#include <math.h>
void main(void)
{ double v,x,f[10]; int i,j;
  char ty[2],dr[2];
  for(j=0; j<4 ;++j){
	switch(j){
      case 0: printf(" J(v,x)\n");
			  ty[0]='j'; dr[0]='d'; x=2.; v=10.4; break;
	  case 1: printf(" I(v,x)\n");
			  ty[0]='i'; dr[0]='d'; x=2.5; v=12.2; break;
	  case 2: printf(" Y(v,x)\n");
			  ty[0]='y'; dr[0]='u'; x=5.1; v=1.4; break;
	  case 3: printf(" K(v,x)\n");
			  ty[0]='k'; dr[0]='u'; x=3.5; v=2.3; break;
	 }
    printf("  argument x= %.4f\n",x);

/* initialize recursion */
    setrcb(v,x,ty[0],dr[0],f,f+1);

    for(i=0; i<9 ;++i){

/* recursive computation of Bessel functions */
      if(i>=2) f[i]=rcbes();
      printf(" %6.2f  %20.12f\n",v,f[i]);
      if(dr[0]=='u') v+=1.; else v-=1.;
     }
	printf("\n");
   }
}
/*  Test output

 J(v,x)
  argument x= 2.0000
  10.40        0.000000097768
   9.40        0.000001008154
   8.40        0.000009378876
   7.40        0.000077774404
   6.40        0.000566151710
   5.40        0.003545596542
   4.40        0.018580069614
   3.40        0.078206709761
   2.40        0.247322743574

 I(v,x)
  argument x= 2.5000
  12.20        0.000000021531
  11.20        0.000000212165
  10.20        0.000001922531
   9.20        0.000015900019
   8.20        0.000118946674
   7.20        0.000796190200
   6.20        0.004705002227
   5.20        0.024133001245
   4.20        0.105098287408

 Y(v,x)
  argument x= 5.1000
   1.40        0.272244667311
   2.40        0.329761926063
   3.40        0.038119498395
   4.40       -0.278935928203
   5.40       -0.519420707843
   6.40       -0.821013806054
   7.40       -1.541162962252
   8.40       -3.651380672638
   9.40      -10.486914547616

 K(v,x)
  argument x= 3.5000
   2.30        0.037839743370
   3.30        0.073984294366
   4.30        0.177352984175
   5.30        0.509765912625
   6.30        1.721215462410
   7.30        6.706141577300
   8.30       29.695406042003
   9.30      147.547210233658
  10.30      813.803437569441

*/
