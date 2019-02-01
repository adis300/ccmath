/*  htgsas.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
void htgsas(double a,double g,double b,double *an)
{ double sa,sb,sg;
  double pi=3.141592653589793;
  g=.5*(pi-g); sg=sin(g); g=cos(g);
  b=.5*(a-b); a-=b;
  sa=sinh(a); a=cosh(a); sb=sinh(b); b=cosh(b);
  an[0]=atan2(sg*b,g*a);
  an[2]=atan2(sg*sb,g*sa);
  g=sg*b/sin(an[0]);
  an[1]=log(g+sqrt(g*g-1));
  a=an[0]-an[2]; an[0]+=an[2]; an[2]=a;
  an[1]+=an[1];
}
