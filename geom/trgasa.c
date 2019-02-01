/*  trgasa.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
int trgasa(double a,double ss,double b,double *asn)
{ double h;
  double pi=3.141592653589793;
  if(a<0. || b<0.) return -1;
  asn[1]=h=pi-a-b;
  h=sin(h);
  asn[0]=ss*sin(a)/h;
  asn[2]=ss*sin(b)/h;
  return 0;
}
