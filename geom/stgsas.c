/*  stgsas.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
void stgsas(double a,double g,double b,double *ang)
{ double sa,sb,sg;
  double pi=3.141592653589793;
  if(g>0.) g=.5*(pi-g); else g= -.5*(pi+g);
  sg=sin(g); g=cos(g);
  b=.5*(a-b); a-=b;
  sa=sin(a); a=cos(a); sb=sin(b); b=cos(b);
  ang[0]=atan2(sg*b,g*a);
  ang[2]=atan2(sg*sb,g*sa);
  if((sg=g*sa/cos(ang[2]))<0.707) ang[1]=asin(sg);
  else ang[1]=acos(g*a/cos(ang[0]));
  a=ang[0]-ang[2]; ang[0]+=ang[2]; ang[2]=a;
  ang[1]+=ang[1];
}
