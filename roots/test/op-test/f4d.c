/*  f4d.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/* 4-D function
   Minimum =0 at x[i]=0.0 for i=0,1,2,3 .
*/
double f4d(double *x)
{ double f,s; extern int count;
  ++count;
  s=x[0]+10.*x[1]; f=s*s;
  s=x[2]-x[3]; f+=5.*s*s;
  s=x[1]-2.*x[2]; f+=s*s;
  s=x[0]-x[3]; s*=s; f+=10.*s*s;
  return f;
}
