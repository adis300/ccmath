/*  autcor.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <stdlib.h>
double *autcor(double *x,int n,int lag)
{ double *p,*q,*pmax,*cf; int j;
  cf=(double *)calloc(lag+1,sizeof(double));
  for(p=x,pmax=x+n; p<pmax ;++p)
    for(q=p,j=0; j<=lag &&q>=x ;) *(cf+j++)+= *p* *q--;
  for(j=1; j<=lag ;) *(cf+j++)/= *cf;
  return cf;
}
