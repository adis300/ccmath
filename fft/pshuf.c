/*  pshuf.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <stdlib.h>
#include "complex.h"
pshuf(Cpx **pa,Cpx **pb,int *kk,int n)
{ int *mm,*m,i,j,k,jk; struct complex **p,**q;
  mm=(int *)malloc((kk[0]+1)*sizeof(int));
  for(i=1,*mm=1,m=mm; i<=kk[0] ;++i,++m) *(m+1)= *m*kk[i];
  for(j=0,p=pb; j<n ;++j){ jk=j; q=pa;
    for(i=1,m=mm; i<=kk[0] ;++i){
      k=n/ *++m; q+=(jk/k)* *(m-1); jk%=k; }
    *q= *p++;
   }
  free(mm);
}
