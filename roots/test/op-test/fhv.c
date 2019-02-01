/*  fhv.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/* Helical valley function
   minimum value = 0 at x[0]=1.0, x[1]=x[2]=0.0
*/
#include <math.h>
#define Tpi 6.283185308
double fhv(double *x)
{ double r,an; extern int count;
  ++count;
  r=x[0]*x[0]+x[1]*x[1]; r=sqrt(r)-1.;
  an=x[2]-10.*atan2(x[1],x[0])/Tpi;
  return (100.*(an*an+r*r)+x[2]*x[2]);
}
