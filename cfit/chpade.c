/*  chpade.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <stdlib.h>
void chpade(double *c,double *a,int m,double *b,int n)
{ double *mat,*ps; int r,s,k;
  mat=(double *)calloc(n*n,sizeof(double));
  for(ps=mat,s=m+1,k=1; k<=n ;){
    for(r=1; r<=n ;++r) *ps++ =(c[abs(s-r)]+c[s+r])/2.;
    b[k++]= -c[s++];
   }
  solv(mat,b+1,n); b[0]=1.;
  for(s=0; s<=m ;++s){ a[s]=c[s];
    for(r=1; r<=n ;++r) a[s]+=(c[abs(s-r)]+c[s+r])*b[r]/2.;
   }
  a[0]/=2.; free(mat);
}
