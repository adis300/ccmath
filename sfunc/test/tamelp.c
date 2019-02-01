/*  tamelp.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  amelp

    Input parameter:  elliptic modulus k (real with 0 < k < 1)
*/
#include <stdlib.h>
#include "ccmath.h"
void main(int na,char **av)
{ double a,k,u,phi,rad=1.74532925199433e-2;
  if(na!=2){ printf("para: modulus\n"); exit(1);}
  printf("     Test of Elliptic Amplitude Function\n");
  k=atof(*++av); printf(" modulus k= %.2f\n",k);
  printf("   a        u          amp(u)  in deg.\n");
  for(a=0.; a<91. ;a+=10.){

/* compute elliptic amplitude function */
    u=a*rad; phi=amelp(u,k);

    printf(" %6.2f  %9.6f  %9.6f  %6.2f\n",a,u,phi,phi/rad);
   }
}
/* Test output

     Test of Elliptic Amplitude Function
 modulus k= 0.80
   a        u          amp(u)  in deg.
   0.00   0.000000   0.000000    0.00
  10.00   0.174533   0.173970    9.97
  20.00   0.349066   0.344654   19.75
  30.00   0.523599   0.509204   29.18
  40.00   0.698132   0.665534   38.13
  50.00   0.872665   0.812471   46.55
  60.00   1.047198   0.949739   54.42
  70.00   1.221730   1.077830   61.76
  80.00   1.396263   1.197828   68.63
  90.00   1.570796   1.311233   75.13
*/
