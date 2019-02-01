/*  htgaaa.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
int htgaaa(double a,double b,double c,double *as)
{ double y,sa,sb,sc;
  double pi=3.141592653589793;
  if(a+b+c>=pi) return -1;
  sa=sin(a); sb=sin(b); sc=sin(c);
  a=cos(a); b=cos(b); c=cos(c);
  y=a*b*c; y+=y;
  y=sqrt(y+a*a+b*b+c*c-1.);
  a=y/(sb*sc); as[0]=log(a+sqrt(a*a+1.));
  b=y/(sa*sc); as[1]=log(b+sqrt(b*b+1.));
  c=y/(sa*sb); as[2]=log(c+sqrt(c*c+1.));
  return 0;
}
