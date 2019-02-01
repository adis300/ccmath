/*  solnl.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <stdlib.h>
int solnl(double *x,double *f,double (*fvec[])(),
		int n,double test)
{ double sc,del,delp; int i,j,k;
  double *p,*q,*r,*s,*pth,*py,*ps,*pb;
  pth=(double *)calloc(n*n+3*n,sizeof(*pth));
  py=pth+n*n; ps=py+n; pb=ps+n;
  for(i=0; i<n*n ;i+=n+1) *(pth+i)=1.;
  for(i=0,p=f,s=ps,del=0.; s<pb ;){
    *p=(*fvec[i++])(x); del+= *p* *p; *s++ = -(*p++); }
  for(k=0; k<20*n ;++k){
    for(i=0,sc=1.; i<5 ;++i,sc/=2.){
      for(p=pb,s=ps,q=x; s<pb ;){ *s*=sc; *p++ = *q++ + *s++;}
      for(j=0,p=py,delp=0.; j<n ;++p){
        *p=(*fvec[j++])(pb); delp+= *p* *p;}
      if(delp<del) break;
     }
    del=delp;
    for(p=x,q=pb,r=py,s=f; r<ps ;){ *p++ = *q++;
      sc= *r- *s; *s++ = *r; *r++ =sc; }
    if(del<test){ free(pth); return 1;}
    for(j=0,p=pb,r=py,sc=0.; r<ps ;){ *p=0.; s=pth+(j++);
      for(q=ps; q<pb ;s+=n) *p+= *s* *q++;
      sc+= *r++ * *p++;
     }
    for(s=ps,r=pth; s<pb ;++s)
      for(q=py; q<ps ;) *s-= *r++ * *q++;
    for(s=ps,r=pth; s<pb ;++s)
      for(q=pb,j=0; j<n ;++j) *r++ += *s* *q++/sc;
    for(s=ps,r=pth; s<pb ;++s){ *s=0.;
      for(p=f,j=0; j<n ;++j) *s-= *r++ * *p++;
     }
   }
  free(pth); return 0;
}
