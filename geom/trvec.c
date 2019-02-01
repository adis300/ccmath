/*  trvec.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
void trvec(double *c,double *a,double *b,int n)
{ double *mx;
  for(mx=c+n; c<mx ;) *c++ = *a++ + *b++;
}
