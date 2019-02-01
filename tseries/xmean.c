/*  xmean.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
double xmean(double *x,int n)
{ double xm; int j;
  for(j=0,xm=0.; j<n ;) xm+=x[j++];
  xm/=n;
  for(j=0; j<n ;) x[j++]-=xm;
  return xm;
}
