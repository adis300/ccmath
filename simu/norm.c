/*  norm.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
static unsigned int s,h,sbuf[256];
static unsigned int a=69069,c=244045795;
static double g=4.6566128730773925e-10;
void norm(double *err)
{ double x,y,r;
  register int i;
  do{ i=(s>>24); s=sbuf[i];
    h=h*a+c; sbuf[i]=h; x=s*g-1.;
    i=(s>>24); s=sbuf[i];
    h=h*a+c; sbuf[i]=h; y=s*g-1.;
    r=x*x+y*y;
   } while(r>=1.);
  r=sqrt(-2.*log(r)/r);
  err[0]=x*r; err[1]=y*r;
}
void setnorm(unsigned int sa)
{ int k;
  for(h=sa,k=0; k<=256 ;++k){
    h=h*a+c;
    if(k<256) sbuf[k]=h; else s=h;
   }
}
