/*  kspbes.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
double kspbes(int n,double x)
{ double y,s,t,v; int p;
  if(x==0.) return HUGE_VAL;
  s=t=exp(-x)/x; x*=2.; v=n+.5;
  for(p=1,y=.5; y<v ;++p,y+=1.){
    t*=(v+y)*(v-y)/(p*x); s+=t; }
  return s;
}
