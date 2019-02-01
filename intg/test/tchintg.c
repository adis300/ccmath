/*  tchintg.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  chintg  fchb

    To specify a new order parameter use 'tchintg' order
*/
#include <math.h>
#include "ccmath.h"
#define MDM 60
/* order of Tchebycheff approximation */
int mp=8;
double Pi=3.14159265358979324;
double func(double x);
void main(int na,char **av)
{ double x,y,f,a[MDM],Pi2=Pi/2.;
  printf("     Test of Tchebycheff Integration\n\n");
  if(na!=1) mp=atoi(*++av);
  printf("  order = %d\n",mp);
  f=chintg(a,mp,func);
  printf("  test magnitude = %14.10f\n\n",f);
  printf("     y       computed       exact\n");
  for(y= -1.; y<=1. ;y+=.5){
    f=fchb(y,a,mp)*Pi2/2.; x=Pi2*(1.+y)/2.;
    printf("  %6.3f  %13.8f  %13.8f\n",y,f,1.-cos(x));
   }
}
/* test integrand function
   defined on x from -1 to 1.
   Integral is 1-cos(Pi*(1+x)/4).
*/
double func(double x)
{ double y;
  y=(1.+x)/2.; return sin(Pi*y/2.);
}
/*  Test output

     Test of Tchebycheff Integration

  order = 8
  test magnitude =   0.0000089716

     y       computed       exact
  -1.000     0.00000000     0.00000000
  -0.500     0.07612047     0.07612047
   0.000     0.29289322     0.29289322
   0.500     0.61731657     0.61731657
   1.000     1.00000000     1.00000000
*/
