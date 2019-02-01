/*  norm2.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
static unsigned int s,h,ss[256];
static unsigned int a=1664525U,c=244045795U;
static double rc=9.313225750491594e-10;
unsigned int lranb(unsigned int);
void norm2(double *err)
{ double x,y,r;
  register int i;
  do{ s=lranb(s); h=h*a+c; i=(h>>24);
    x=rc*ss[i]-1.; ss[i]=s;
    s=lranb(s); h=h*a+c; i=(h>>24);
    y=rc*ss[i]-1.; ss[i]=s;
    r=x*x+y*y;
   } while(r>=1.);
  r=sqrt(-2.*log(r)/r);
  err[0]=x*r; err[1]=y*r;
}
void setnorm2(unsigned int sa)
{ int k;
  for(s=sa,k=0; k<=256 ;++k){
    s=lranb(s);
    if(k<256) ss[k]=s; else h=s;
   }
}
