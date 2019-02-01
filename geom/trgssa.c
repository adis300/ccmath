/*  trgssa.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
int trgssa(double a,double b,double ba,double *an)
{ double x,y,z,v;
  x=a*cos(ba); ba=a*sin(ba);
  a*=a; b*=b;
  if((y=b-ba*ba)<0.) return -1;
  else y=sqrt(y);
  an[0]=x+y; v=an[0]*an[0];
  z=an[0]*ba; z+=z;
  an[1]=atan2(z,a+b-v);
  an[2]=atan2(z,b+v-a);
  if(x>y){
    an[3]=x-y; v=an[3]*an[3];
    z=an[3]*ba; z+=z;
    an[4]=atan2(z,a+b-v);
    an[5]=atan2(z,b+v-a);
   }
  else an[3]=an[4]=an[5]=0.;
  return 0;
}
