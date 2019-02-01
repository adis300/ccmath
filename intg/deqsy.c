/*  deqsy.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
#include <stdlib.h>
deqsy(double *y,int n,double a,double b,int nd,double te,
	  int (*fsys)())
{ double h,x,ht,st,*dp,*fp,*fq,*ap,*p,*q,*pt;
  int m,j,k;
  fp=(double *)calloc(13*n,sizeof(double));
  fq=fp+n; dp=fq+n; ap=dp+n; h=(b-a)/nd;
  for(m=0; m>=0 ;){ ++m; (*fsys)(x=a,y,dp);
    for(j=0,p=fp,q=fq,pt=dp; p<fq ;)
      *p++ =(*q++ =y[j++])+h* *pt++;
    for(j=1,st=2.*h; j<nd ;++j){ (*fsys)(x+=h,fp,dp);
      for(p=fp,q=fq,pt=dp; p<fq ;){
        ht= *q+st* *pt++; *q++ = *p; *p++ =ht; }
     }
    (*fsys)(x+=h,fp,dp);
    for(p=fp,q=fq,pt=dp; p<fq ;){
      *p+= *q++ +h* *pt++; *p++ /=2.; }
    for(j=1,k=1,pt=ap; j<m ;++j){ k*=4;
      for(p=dp,q=fp; q<fq ;){
        *p=(*q- *pt)/(k-1); *pt++ = *q; *q++ += *p++; }
     }
    for(q=fp; q<fq ;) *pt++ = *q++;
    h/=2.; nd*=2;
    if(m>1){
       for(k=0,p=fp,q=dp; p<fq ;){
         if(fabs(*q++)>te*fabs(*p++)){ k=1; break;}
        }
       if(k==0) break;
       if(m==10) m= -m;
      }
   }
  for(p=y,q=fp; q<fq ;) *p++ = *q++;
  free(fp); return m;
}
