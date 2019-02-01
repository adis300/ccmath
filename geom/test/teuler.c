/*  teuler.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
  Test: euler
  Uses: stgsas
*/
#include "ccmath.h"
#include <math.h>
void main(void)
{ double an1,an2,an3;
  double rad=1.74532925199433e-02;
  double vc[9]; int j;
  printf("     Test of Rotation Programs\n");
  an1=30.*rad; an2=40.*rad; an3=35.*rad;
  printf(" spherical triangle s-a-s\n");
  stgsas(an1,an2,an3,vc);
  printf("   input angles: %f %f %f\n",an1/rad,an2/rad,an3/rad);
  printf("  output angles: %f %f %f\n",vc[0]/rad,vc[1]/rad,vc[2]/rad);
  for(j=0; j<9 ;) vc[j++]=0.;
  vc[0]=vc[4]=vc[8]=1.;
  euler(vc,3,an1,an2,an3);
  printf("\n  rotation matrix for input angles:\n");
  for(j=0; j<9 ;){ printf("  %9f",vc[j++]); if(j%3==0) printf("\n");}
}
/* Test output

     Test of Rotation Programs
 spherical triangle s-a-s
   input angles: 30.000000 40.000000 35.000000
  output angles: 60.345951 21.705202 85.493660

  rotation matrix for input angles:
   0.256649   0.810485  -0.526541
  -0.790095   0.489714   0.368688
   0.556670   0.321394   0.766044
*/
