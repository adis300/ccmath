/*  trcspbs.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  rcspbes  setrcsb

    Uses:  (implicit)  jspbes  yspbes  kspbes

*/
#include "ccmath.h"
#include <math.h>
void main(void)
{ double x,f[10]; int i,n,j;
  char ty[2],dr[2];
  for(j=0; j<3 ;++j){
	switch(j){
      case 0: printf(" j(n,x)\n");
			  ty[0]='j'; dr[0]='d'; x=2.; n=9; break;
	  case 1: printf(" y(n,x)\n");
			  ty[0]='y'; dr[0]='u'; x=1.5; n=1; break;
	  case 2: printf(" k(n,x)\n");
			  ty[0]='k'; dr[0]='u'; x=1.5; n=1; break;
	 }
    printf("  argument x= %.4f\n",x);

/* initialize spherical Bessel function recursion */
    setrcsb(n,x,ty[0],dr[0],f,f+1);

    for(i=0; i<8 ;++i){

/* recursive computation of spherical Bessel functions */
      if(i>=2) f[i]=rcspbs();

      printf(" %3d  %16.8f\n",n,f[i]);
      if(dr[0]=='u') ++n; else --n;
     }
	printf("\n");
   }
}
/*  Test output

 j(n,x)
  argument x= 2.0000
   9        0.00000071
   8        0.00000668
   7        0.00005610
   6        0.00041404
   5        0.00263517
   4        0.01407939
   3        0.06072210
   2        0.19844795

 y(n,x)
  argument x= 1.5000
   1       -0.69643541
   2       -1.34571269
   3       -3.78927356
   4      -16.33756394
   5      -94.23611009
   6     -674.72724335
   7    -5753.39999895
   8   -56859.27274614

 k(n,x)
  argument x= 1.5000
   1        0.24792240
   2        0.64459824
   3        2.39658320
   4       11.82865318
   5       73.36850229
   6      549.86433663
   7     4838.85941977
   8    48938.45853433

*/
