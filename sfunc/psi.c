/*  psi.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
double psi(int m)
{ double s= -.577215664901533; int k;
  for(k=1; k<m ;++k) s+=1./k;
  return s;
}
double psih(double v)
{ double s= -1.963510026021423,r;
  for(r=.5; r<v ;r+=1.) s+=1./r;
  return s;
}
