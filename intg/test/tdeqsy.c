/*  tdeqsy.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  deqsy

    To specify a new convergence test threshold use the call
    tdeqsy new_te
*/
#include <math.h>
#include "ccmath.h"
/* convergence test threshold */
double te=1.e-8;
/* system dimension parameter */
int n=2;
int fsys(double x,double *y,double *d);
void main(int na,char **av)
{ double a,b,dx,y[2];
  int m;
  printf("     Test of Differential System Solver\n\n");
  if(na != 1) te=atof(*++av);
  printf("   convergence threshold= %.2e\n\n",te);
  y[0]=20.; y[1]=0.; a=0.;
  printf(" x= %6.3f  y0= %10f  y1= %10f\n",a,y[0],y[1]);
/* integrate with 0.25 increments and 20 initial steps/increment */
  for(dx=.25; a<7.5 ;a=b){
    b=a+dx; m=deqsy(y,n,a,b,20,te,fsys);
    printf(" x= %6.3f  y0= %10f  y1= %10f  m=%d\n",b,y[0],y[1],m);
   }
}
/* system function for the second order system
   dy/dt = v , dv/dt = -f^2*y - r*v
*/
int fsys(double x,double *y,double *d)
{ double f=1.,r=.5;
  d[0]=y[1]; d[1]= -f*f*y[0]-r*y[1];
}
/* Test output

     Test of Differential System Solver

   convergence threshold= 1.00e-08

 x=  0.000  y0=  20.000000  y1=   0.000000
 x=  0.250  y0=  19.403339  y1=  -4.651330  m=3
 x=  0.500  y0=  17.742734  y1=  -8.484261  m=3
 x=  0.750  y0=  15.240260  y1= -11.370938  m=3
 x=  1.000  y0=  12.141097  y1= -13.253832  m=3
 x=  1.250  y0=   8.696494  y1= -14.140843  m=3
 x=  1.500  y0=   5.148365  y1= -14.097148  m=3
 x=  1.750  y0=   1.716249  y1= -13.234662  m=3
 x=  2.000  y0=  -1.412891  y1= -11.700004  m=3
 x=  2.250  y0=  -4.091769  y1=  -9.661852  m=3
 x=  2.500  y0=  -6.216722  y1=  -7.298489  m=3
 x=  2.750  y0=  -7.728642  y1=  -4.786260  m=3
 x=  3.000  y0=  -8.611197  y1=  -2.289486  m=3
 x=  3.250  y0=  -8.886756  y1=   0.047721  m=3
 x=  3.500  y0=  -8.610539  y1=   2.107510  m=3
 x=  3.750  y0=  -7.863524  y1=   3.802091  m=3
 x=  4.000  y0=  -6.744692  y1=   5.075336  m=3
 x=  4.250  y0=  -5.363124  y1=   5.902336  m=3
 x=  4.500  y0=  -3.830440  y1=   6.287191  m=3
 x=  4.750  y0=  -2.253977  y1=   6.259362  m=3
 x=  5.000  y0=  -0.731016  y1=   5.868967  m=3
 x=  5.250  y0=   0.655718  y1=   5.181425  m=3
 x=  5.500  y0=   1.841181  y1=   4.271836  m=3
 x=  5.750  y0=   2.779739  y1=   3.219454  m=3
 x=  6.000  y0=   3.445548  y1=   2.102565  m=3
 x=  6.250  y0=   3.831743  y1=   0.994027  m=3
 x=  6.500  y0=   3.948608  y1=  -0.042351  m=3
 x=  6.750  y0=   3.820959  y1=  -0.954477  m=3
 x=  7.000  y0=   3.484989  y1=  -1.703639  m=3
 x=  7.250  y0=   2.984812  y1=  -2.265202  m=3
 x=  7.500  y0=   2.368956  y1=  -2.628386  m=3
*/
