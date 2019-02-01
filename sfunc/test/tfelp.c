/*  tfelp.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  felp

    Input parameter:  order k  real with 0 < k < 1
*/
#include "ccmath.h"
#include <math.h>
void main(int na,char **av)
{ double a,k,f,kk,z,h,rad=1.74532925199433e-2;
  if(na!=2){ printf("para: order\n"); exit(1);}
  printf("     Test of Elliptic Integrals of 1st & 2nd Kind\n");
  k=atof(*++av); printf(" order k= %.2f\n",k);
  printf("   a      F(k,a)     E(k,a)\n");
  for(a=0.; a<91. ;a+=10.){

/* compute elliptic integrals */
    f=felp(a*rad,k,&kk,&z,&h);

    printf(" %6.2f  %9.6f  %9.6f\n",a,f,z);
   }
  printf(" Complete Integrals\n");
  printf("  K= %f   E= %f\n",kk,h);
}
/*  Test output

     Test of Elliptic Integrals of 1st & 2nd Kind
 order k= 0.80
   a      F(k,a)     E(k,a)
   0.00   0.000000   0.000000
  10.00   0.175102   0.173968
  20.00   0.353651   0.344587
  30.00   0.539268   0.508729
  40.00   0.735879   0.663720
  50.00   0.947709   0.807603
  60.00   1.178902   0.939455
  70.00   1.432303   1.059747
  80.00   1.706963   1.170698
  90.00   1.995303   1.276350
 Complete Integrals
  K= 1.995303   E= 1.276350
*/
