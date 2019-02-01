/*  sdiff.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#define MXD 6
static double f[MXD];
double sdiff(double y,int nd,int k)
{ double s;
  if(k==0) for(k=0; k<nd ;) f[k++]=0.;
  for(k=0; k<nd ;){
    s=y-f[k]; f[k++]=y; y=s; }
  return s;
}
double sintg(double y,int nd,int k)
{ double s;
  if(k==0) for(k=0; k<nd ;) f[k++]=0.;
  for(k=nd-1; k>=0 ;){
    s=f[k]; f[k--]+=y; y=s; }
  return f[0];
}
