/*  stgaaa.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
int stgaaa(double a,double b,double c,double *ang)
{ double s;
  double pi=3.141592653589793;
  if(a+b+c<=pi) return -1;
  a=cos(a); b=cos(b); c=cos(c);
  s=a*b*c; s+=s;
  s=sqrt(1.-a*a-b*b-c*c-s);
  ang[0]=atan2(s,b*c+a);
  ang[1]=atan2(s,a*c+b);
  ang[2]=atan2(s,a*b+c);
  return 0;
}
