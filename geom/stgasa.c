/*  stgasa.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
int stgasa(double a,double c,double b,double *ang)
{ double sa,sb,sc; int f;
  double pi=3.141592653589793;
  if(a>=0. && b>=0.) f=0;
  else if(a<0. && b<0.){ a= -a; b= -b; f=1;}
  else return -1;
  c*=.5; sc=sin(c); c=cos(c);
  b=.5*(a-b); a-=b;
  sa=sin(a); a=cos(a); sb=sin(b); b=cos(b);
  ang[0]=atan2(sc*b,c*a);
  ang[2]=atan2(sc*sb,c*sa);
  ang[1]=atan2(sa/cos(ang[2]),a/cos(ang[0]));
  a=ang[0]-ang[2]; ang[0]+=ang[2]; ang[2]=a;
  ang[1]+=ang[1];
  if(ang[1]>0.) ang[1]=pi-ang[1];
  else ang[1]= -ang[1]-pi;
  if(f) ang[1]= -ang[1];
  return 0;
}
