/*  trotax.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
  Test: rotax
  uses: matprt
*/
#include "ccmath.h"
#include <math.h>
void main(void)
{ double v[3],az,pa,an; int j;
  double rad=1.74532925199433e-02;
  printf("     Test of Axis Rotation\n");
  v[0]=1.; v[1]=v[2]=0.;
  az=60.; pa=50.; an=45.;
  printf(" input vector:\n"); matprt(v,1,3," %f");
  printf(" rotation axis: az= %.3f pa= %.3f\n",az,pa);
  printf(" rotation angle = %f\n",an);
  for(j=0; j<8 ;++j){
    rotax(v,az*rad,pa*rad,an*rad,j);
    printf(" output vector: rot = %9.3f\n",(j+1)*an);
    matprt(v,1,3,"  %9f");
   }
}
/* Test output

     Test of Axis Rotation
 input vector:
 1.000000 0.000000 0.000000
 rotation axis: az= 60.000 pa= 50.000
 rotation angle = 45.000000
 output vector: rot =    45.000
   0.750076   0.528944  -0.396994
 output vector: rot =    90.000
   0.146706   0.896890  -0.417212
 output vector: rot =   135.000
  -0.456664   0.888299  -0.048812
 output vector: rot =   180.000
  -0.706588   0.508205   0.492404
 output vector: rot =   225.000
  -0.456664  -0.020740   0.889397
 output vector: rot =   270.000
   0.146706  -0.388685   0.909616
 output vector: rot =   315.000
   0.750076  -0.380095   0.541215
 output vector: rot =   360.000
   1.000000  -0.000000   0.000000
*/
