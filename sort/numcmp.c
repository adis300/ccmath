/*  numcmp.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
int dubcmp(double *x,double *y)
{ if(*x > *y) return 1;
  if(*x < *y) return -1;
  return 0;
}
int intcmp(int *x,int *y)
{ if(*x > *y) return 1;
  if(*x < *y) return -1;
  return 0;
}
int unicmp(unsigned *x,unsigned *y)
{ if(*x > *y) return 1;
  if(*x < *y) return -1;
  return 0;
}
