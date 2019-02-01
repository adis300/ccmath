/*  chcof.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
void chcof(double *c,int m,double (*func)())
{ double *p,*q,a,da,an,f; int j;
  ++m; q=c+m; a=1.570796326794897/m; da=a*2.;
  for(p=c; p<q ;) *p++ =0.;
  for(j=0; j<m ;++j,a+=da){
    *c+=(f=(*func)(cos(a)));
    for(p=c+1,an=0.; p<q ;) *p++ +=f*cos(an+=a);
   }
  for(p=c,an=2./m; p<q ;) *p++ *=an;
}
