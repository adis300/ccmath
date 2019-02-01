/*  nrml.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
static unsigned int a=1664525U,c=907633387U;
static unsigned int s,h,sbuf[256];
static int kf;
static double rc=4.6566128730773926e-10,e;
double nrml()
{ double x,y,r; int i;
  if(kf){
    do{ i=(int)(s>>24); s=sbuf[i];
      h=a*h+c; sbuf[i]=h;
      x=rc*s-1.;
      i=(int)(s>>24); s=sbuf[i];
      h=a*h+c; sbuf[i]=h;
      y=rc*s-1.; r=x*x+y*y;
     } while(r>=1.);
    r=sqrt(-2.*log(r)/r);
    x*=r; e=y*r;
   }
  else x=e;
  kf^=1; return x;
}
void setnrml(unsigned int sa)
{ int j;
  for(h=sa,j=0; j<=256 ;++j){
    h=a*h+c;
    if(j<256) sbuf[j]=h; else s=h;
   }
  kf=1;
}
