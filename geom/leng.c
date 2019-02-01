/*  leng.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
#define NULL ((void *)0)
double leng(double *a,double *b,int n)
{ double s,t; int j;
  if(b!=NULL){
    for(s=0.,j=0; j<n ;++j){ t= *a++ - *b++; s+=t*t;}
   }
  else{ for(s=0.,j=0; j<n ;++j){ t= *a++; s+=t*t;} }
  return sqrt(s);
}
