/*  htgasa.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
int htgasa(double a,double cc,double b,double *ans)
{ double sa,sb,x;
  double pi=3.141592653589793;
  if(a<0. || b<0.) return -1;
  sa=sin(a); a=cos(a); sb=sin(b); b=cos(b);
  x=sa*sb*cosh(cc)-a*b;
  ans[1]=atan2(sqrt(1.-x*x),x);
  cc=sinh(cc)*sa*sb/sin(ans[1]);
  x=cc/sb; ans[0]=log(x+sqrt(x*x+1.));
  x=cc/sa; ans[2]=log(x+sqrt(x*x+1.));
  return 0;
}
