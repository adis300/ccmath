/*  tcsplp.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  csplp
    Uses:  csfit (when tn=0)  tnsfit (when tn!=0)

    To set a nonzero tension call: 'tcsplp tn', 0 <= tn is assumed.

    The points for the interpolation lie on an ellipse, centered at
    the origin with major axis along the x-coordinate. The number of
    interpolation points (2m) and ellipse axes (a,b) can be altered
    with the call: 'tcsplp tn a b m'
*/
#include "ccmath.h"
#include <math.h>
#define MD 20
/* spline tension */
double tn;
/* 1/2 the number of points */
int m= 4;
/* ellipse axes (closed curve is an ellipse) */
double a=2.,b=1.;
void main(int na,char **av)
{ double x[MD],y[MD],z[MD],w[MD],t[MD];
  double s,ds,u,atof(); int i,j;
  double pi=3.1415926535897932;
  if(na==4){
    a=atof(*++av); b=atof(*++av); m=atoi(*++av);
   }
  printf("     Test of Periodic Splines\n");
  printf(" interpolation angle = %9.3f\n",180./m);
  tn=0.;
  for(i=0; i<2 ;++i){
    printf("\n   tension= %f\n\n",tn);
	printf(" ellipse: a= %f  b= %f\n",a,b);
    s=0.; ds=pi/m; m*=2;
    for(j=0; j<=m ;s+=ds){ x[j]=a*cos(s); y[j]=b*sin(s); t[j++]=s;}
    csplp(t,x,z,m,tn); csplp(t,y,w,m,tn);
    printf("  periodic spline coefficients\n");
    for(j=0; j<=m ;++j)
      printf(" %2d x=%9f z=%9f y=%9f w=%9f\n",j,x[j],z[j],y[j],w[j]);
    if(tn==0.) printf("\n  evaluation of periodic cubic spline\n");
    else printf("\n  evaluation of periodic tensioned spline\n");
    for(s=t[0],ds=pi/12.,u=t[m]+ds/2.; s<u ;s+=ds){
      if(s>t[m]) s=t[m];
      if(tn==0.){ a=csfit(s,t,x,z,m); b=csfit(s,t,y,w,m);}
      else{ a=tnsfit(s,t,x,z,m,tn); b=tnsfit(s,t,y,w,m,tn);}
      printf(" x= %14.10f   y= %14.10f\n",a,b);
     }
	tn=5.0; a=b=1.;
   }
}
/* Test output

     Test of Periodic Splines
 interpolation angle =    45.000

   tension= 0.000000

 ellipse: a= 2.000000  b= 1.000000
  periodic spline coefficients
  0 x= 2.000000 z=-0.350796 y= 0.000000 w=-0.000000
  1 x= 1.414214 z=-0.248050 y= 0.707107 w=-0.124025
  2 x= 0.000000 z= 0.000000 y= 1.000000 w=-0.175398
  3 x=-1.414214 z= 0.248050 y= 0.707107 w=-0.124025
  4 x=-2.000000 z= 0.350796 y= 0.000000 w=-0.000000
  5 x=-1.414214 z= 0.248050 y=-0.707107 w= 0.124025
  6 x=-0.000000 z=-0.000000 y=-1.000000 w= 0.175398
  7 x= 1.414214 z=-0.248050 y=-0.707107 w= 0.124025
  8 x= 2.000000 z=-0.350796 y=-0.000000 w=-0.000000

  evaluation of periodic cubic spline
 x=   2.0000000000   y=   0.0000000000
 x=   1.9302179004   y=   0.2583703622
 x=   1.7302610370   y=   0.4997396481
 x=   1.4142135624   y=   0.7071067812
 x=   0.9994792962   y=   0.8651305185
 x=   0.5167407245   y=   0.9651089502
 x=   0.0000000000   y=   1.0000000000
 x=  -0.5167407245   y=   0.9651089502
 x=  -0.9994792962   y=   0.8651305185
 x=  -1.4142135624   y=   0.7071067812
 x=  -1.7302610370   y=   0.4997396481
 x=  -1.9302179004   y=   0.2583703622
 x=  -2.0000000000   y=   0.0000000000
 x=  -1.9302179004   y=  -0.2583703622
 x=  -1.7302610370   y=  -0.4997396481
 x=  -1.4142135624   y=  -0.7071067812
 x=  -0.9994792962   y=  -0.8651305185
 x=  -0.5167407245   y=  -0.9651089502
 x=  -0.0000000000   y=  -1.0000000000
 x=   0.5167407245   y=  -0.9651089502
 x=   0.9994792962   y=  -0.8651305185
 x=   1.4142135624   y=  -0.7071067812
 x=   1.7302610370   y=  -0.4997396481
 x=   1.9302179004   y=  -0.2583703622
 x=   2.0000000000   y=  -0.0000000000

   tension= 5.000000

 ellipse: a= 1.000000  b= 1.000000
  periodic spline coefficients
  0 x= 1.000000 z=-0.094681 y= 0.000000 w= 0.000000
  1 x= 0.923880 z=-0.087474 y= 0.382683 w=-0.036233
  2 x= 0.707107 z=-0.066950 y= 0.707107 w=-0.066950
  3 x= 0.382683 z=-0.036233 y= 0.923880 w=-0.087474
  4 x= 0.000000 z=-0.000000 y= 1.000000 w=-0.094681
  5 x=-0.382683 z= 0.036233 y= 0.923880 w=-0.087474
  6 x=-0.707107 z= 0.066950 y= 0.707107 w=-0.066950
  7 x=-0.923880 z= 0.087474 y= 0.382683 w=-0.036233
  8 x=-1.000000 z= 0.094681 y= 0.000000 w=-0.000000
  9 x=-0.923880 z= 0.087474 y=-0.382683 w= 0.036233
 10 x=-0.707107 z= 0.066950 y=-0.707107 w= 0.066950
 11 x=-0.382683 z= 0.036233 y=-0.923880 w= 0.087474
 12 x=-0.000000 z= 0.000000 y=-1.000000 w= 0.094681
 13 x= 0.382683 z=-0.036233 y=-0.923880 w= 0.087474
 14 x= 0.707107 z=-0.066950 y=-0.707107 w= 0.066950
 15 x= 0.923880 z=-0.087474 y=-0.382683 w= 0.036233
 16 x= 1.000000 z=-0.094681 y=-0.000000 w= 0.000000

  evaluation of periodic tensioned spline
 x=   1.0000000000   y=   0.0000000000
 x=   0.9608472826   y=   0.2579862530
 x=   0.8618454582   y=   0.4969978003
 x=   0.7071067812   y=   0.7071067812
 x=   0.4969978003   y=   0.8618454582
 x=   0.2579862530   y=   0.9608472826
 x=   0.0000000000   y=   1.0000000000
 x=  -0.2579862530   y=   0.9608472826
 x=  -0.4969978003   y=   0.8618454582
 x=  -0.7071067812   y=   0.7071067812
 x=  -0.8618454582   y=   0.4969978003
 x=  -0.9608472826   y=   0.2579862530
 x=  -1.0000000000   y=   0.0000000000
 x=  -0.9608472826   y=  -0.2579862530
 x=  -0.8618454582   y=  -0.4969978003
 x=  -0.7071067812   y=  -0.7071067812
 x=  -0.4969978003   y=  -0.8618454582
 x=  -0.2579862530   y=  -0.9608472826
 x=  -0.0000000000   y=  -1.0000000000
 x=   0.2579862530   y=  -0.9608472826
 x=   0.4969978003   y=  -0.8618454582
 x=   0.7071067812   y=  -0.7071067812
 x=   0.8618454582   y=  -0.4969978003
 x=   0.9608472826   y=  -0.2579862530
 x=   1.0000000000   y=  -0.0000000000
*/
