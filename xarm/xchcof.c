/*  xchcof.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "xpre.h"
static struct xpr cs[52];
void xchcof(struct xpr *c,int m,struct xpr (*xfunc)())
{ struct xpr a,b; int i,j,k,n;
  ++m; n=2*m;
  a=xdiv(pi2,inttox(m)); b=a; cs[0]=one;
  for(j=0; j<m ;++j) c[j]=zero;
  for(j=1; j<=n ;b=xadd(b,a,0),++j) cs[j]=xcos(b);
  for(j=1; j<n ;j+=2){
    a=(*xfunc)(cs[j]); c[0]=xadd(c[0],a,0);
    for(k=1; k<m ;++k){
      i=(k*j)%(2*n); if(i>n) i=2*n-i;
      c[k]=xadd(c[k],xmul(a,cs[i]),0);
     }
   }
  b=xpr2(xdiv(one,inttox(m)),1);
  for(j=0; j<m ;++j) c[j]=xmul(c[j],b);
}
