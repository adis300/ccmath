/*  frb.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/* Rosenbrock function:
   minimum = 0 at x[0]=1.0 x[1]=1.0
*/
double frb(double *x)
{ double f,y; extern int count;
  ++count;
  y=x[0]; f=1.0-y; y=x[1]-y*y;
  return 100.0*y*y+f*f;
}
