/*  evpsq.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "orpol.h"
double evpsq(double x,Opol *c,int m)
{ int i; double f,s,t;
  f=s=c[m-1].cf; t=0.;
  for(i=m-2; i>=0 ;--i){
    f=c[i].cf+(x-c[i].df)*s-c[i+1].hs*t;
    t=s; s=f;
   }
  return f;
}
