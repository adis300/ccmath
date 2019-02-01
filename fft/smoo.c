/*  smoo.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <stdlib.h>
smoo(double *x,int n,int m)
{ double *p,*q,*pmax,*pmin,*pa,*pb,*ph;
  int ms; double s,t;
  ms=2*m+1; ph=x+n/2;
  p=pmin=(double *)calloc(ms,sizeof(*pmin));
  q=pmax=pmin+ms-1; s=t=0.;
  for(pa=x+m,pb=ph-m; pa>x ;){
    t+=(*p++ = *q-- = *pa--); s+= *pb++;}
  *ph=s/m; t=ms*(*pa++ = *q=t/m); s=1./ms;
  for(p=pmax,q=pmin,pb=pa+m; pa<ph;){
    t-= *q; if((++q)>pmax) q=pmin;
    if((++p)>pmax) p=pmin;
    t+=(*p= *pb++); *pa++ =s*t;
   }
  for(pa=ph-1,pb=ph+1; pa>x ;) *pb++ = *pa--;
  free(pmin);
}
