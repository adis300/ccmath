/*  evpsqv.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
#include "orpol.h"
double evpsqv(double x,Opol *c,int m,double *v,double sig)
{ int i; double f,h,s,t,r,z;
  f=s=c[m-1].cf; t=0.;
  for(i=m-2; i>=0 ;--i){
    f=c[i].cf+(x-c[i].df)*s-c[i+1].hs*t;
    t=s; s=f;
   }
  if(v!=0){
    r=s=1.; t=z=0.;
    for(i=0; i<m ;++i){
      r*=c[i].hs; z+=s*s/r;
      h=(x-c[i].df)*s-c[i].hs*t;
      t=s; s=h;
     }
    *v=sqrt(sig*z);
   }
  return f;
}
