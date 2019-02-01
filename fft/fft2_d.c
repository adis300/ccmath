/*  fft2_d.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <stdlib.h>
#include "complex.h"
void fft2(struct complex *ff,int k,int j);
fft2_d(struct complex *a,int m,int n,int f)
{ register int md,nd,i,j; struct complex *p,*q;
  register struct complex *r,*s;
  md=1<<m; nd=1<<n;
  for(i=0,p=a; i<md ;++i){
    fft2(p,n,f); p+=nd;
   }
  q=(struct complex *)calloc(sizeof(*q),md);
  for(i=0,p=a-nd; i<nd ;++i){
    for(r=q,s=p,j=0; j<md ;++j) *r++ = *(s+=nd);
    fft2(q,m,f);
    for(r=q,s=p++,j=0; j<md ;++j) *(s+=nd)= *r++;
   }
  free(q);
}
