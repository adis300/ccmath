/*  metpr.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
double metpr(double *u,double *a,double *v,int n)
{ double r,s; int i,j;
  for(i=0,s=0.; i<n ;){
    for(j=0,r=0.; j<n ;) r+= *a++ *v[j++];
    s+=r*u[i++];
   }
  return s;
}
