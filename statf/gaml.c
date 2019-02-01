/*  gaml.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
double gaml(x)
double x;
{ double g,h;
  for(g=1.; x<30. ;g*=x,x+=1.); h=x*x;
  g=(x-.5)*log(x)-x+.918938533204672-log(g);
  g+=(1.-(1./6.-(1./3.-1./(4.*h))/(7.*h))/(5.*h))/(12.*x);
  return g;
}
