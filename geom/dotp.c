/*  dotp.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
double dotp(double *u,double *v,int m)
{ double s,*umx;
  for(umx=u+m,s=0.; u<umx ;) s+= *u++ * *v++;
  return s;
} 
