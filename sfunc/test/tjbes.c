/*  tjbes.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  jbes

    Prompted input:  at prompt  'order '
                                  enter v
                                          { real order v >=0)

                     at prompt  'max-x interval '
                                  enter xmx dx
                                               { real maximum x-value
                                                 and interval -> table
                                                 from x=0 to xmx at
                                                 intervals dx }
*/
#include "ccmath.h"
#include <math.h>
void main(void)
{ double x,dx,f,v,xmx;
  printf("     Test of Bessel Functions\n");
  printf("     J(v,x)\n");
  fprintf(stderr,"order "); scanf("%lf",&v);
  printf(" order= %.2f\n",v);
  fprintf(stderr,"max-x interval ");
  scanf("%lf %lf",&xmx,&dx); xmx+=dx/4.;
  for(x=0.; x<xmx ; x+=dx){

/* computr Bessel function of the first kind J(v,x) */
    f=jbes(v,x);

    printf(" %7.2f  %15.12f\n",x,f); }
}
/*  Test output

     Test of Bessel Functions
     J(v,x)
 order= 1.50
    0.00   0.000000000000
    0.50   0.091701699626
    1.00   0.240297839123
    1.50   0.387142217276
    2.00   0.491293778687
    2.50   0.525080264664
    3.00   0.477718215087
    3.50   0.356642662606
    4.00   0.185285948354
    4.50  -0.002419664543
    5.00  -0.169651306145
    5.50  -0.284746335719
    6.00  -0.327930310862
    6.50  -0.295271626977
    7.00  -0.199051713292
    7.50  -0.064553196130
    8.00   0.075931402812
    8.50   0.190462558153
    9.00   0.254504218375
    9.50   0.256088084477
   10.00   0.197982492756
   10.50   0.096463161014
   11.00  -0.022934594839
   11.50  -0.131624791664
   12.00  -0.204663448497
*/
