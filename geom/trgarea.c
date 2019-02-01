/*  trgarea.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
double trgarea(double a,double b,double c)
{ double s;
  s=a+b+c;
  s=sqrt(s*(s-a-a)*(s-b-b)*(s-c-c));
  return .25*s;
}
