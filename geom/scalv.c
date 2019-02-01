/*  scalv.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
void scalv(double *r,double s,int n)
{ double *mx;
  for(mx=r+n; r<mx ;) *r++ *=s;
}
