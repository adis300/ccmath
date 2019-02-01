/*  trgsas.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
void trgsas(double a,double g,double b,double *ans)
{ double u,s;
  u=a*b; s=u*sin(g);
  u*=cos(g); u+=u; s+=s;
  a*=a; b*=b;
  u=a+b-u; ans[1]=sqrt(u);
  ans[0]=atan2(s,b+u-a);
  ans[2]=atan2(s,a+u-b);
}
