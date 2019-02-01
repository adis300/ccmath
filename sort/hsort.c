/*  hsort.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#define Swap(x,y) (tmp=(x),(x)=(y),(y)=tmp)
static void rheap(void **v,int k,int n,int (*comp)());
void hsort(void **v,int n,int (*comp)())
{ int k; char *tmp;
  for(k=n/2-1; k>=0 ;) rheap(v,k--,n,comp);
  for(--n; n>0 ;){ Swap(v[0],v[n]); rheap(v,0,n--,comp);}
}
static void rheap(void **v,int k,int n,int (*comp)())
{ int m=n-1,j; char *tmp;
  for(j=2*k+1; j<n ;k=j,j=2*k+1){
    if(j<m && (*comp)(v[j+1],v[j])>0) ++j;
    if((*comp)(v[j],v[k])>0) Swap(v[k],v[j]);
    else break;
   }
}
