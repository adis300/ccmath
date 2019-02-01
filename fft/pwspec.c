/*  pwspec.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <stdlib.h>
int pwspec(double *x,int n,int m)
{ int j,kk[32]; double s;
  struct complex {double re,im;} *p,*q;
  n=pfac(n,kk,'e');
  p=(struct complex *)malloc(n*sizeof(*p));
  fftgr(x,p,n,kk,'d');
  for(s=0.,j=0; j<n ;++j) s+=x[j]*x[j];
  for(s/=n,q=p,j=0; j<n ;++q)
    x[j++]=(q->re*q->re+q->im*q->im)/s;
  if(m) smoo(x,n,m);
  free(p); return n;
}
