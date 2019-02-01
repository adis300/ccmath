/*  fftgr.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "complex.h"
#include <stdlib.h>
void fftgr(double *x,struct complex *ft,int n,int *kk,int inv)
{ struct complex a,b,z,w,*d,*p,*f,*fb;
  double tpi=6.283185307179586,sc,q,*t;
  int *mm,*m,kp,i,j,k,jk,jl,ms,mp;
  mm=(int *)malloc((kk[0]+1)*sizeof(int));
  d=(struct complex *)malloc(kk[*kk]*sizeof(w));
  for(i=1,*mm=1,m=mm; i<=kk[0] ;++i,++m) *(m+1)= *m*kk[i];
  for(j=0,t=x; j<n ;++j){ jl=j; f=ft;
    for(i=1,m=mm; i<=kk[0] ;++i){
      k=n/ *++m; f+=(jl/k)* *(m-1); jl%=k;}
    f->re= *t++; f->im=0.;
   }
  if(inv=='d'){ for(i=0,sc=1./n,f=ft; i<n ;++i) (f++)->re*=sc;}
  for(i=1,m=mm; i<=kk[0] ;++i){
    ms= *m++; mp= *m; kp=kk[i]; q=tpi/mp; if(inv=='d') q= -q;
    a.re=cos(q); a.im=sin(q); b.re=cos(q*=ms); b.im=sin(q);
    for(j=0; j<n ;j+=mp){
      fb=ft+j; z.re=1.; z.im=0.;
      for(jk=0; jk<ms ;++jk,++fb){ p=d; w=z;
        for(k=0; k<kp ;++k,++p){ f=fb+mp-ms; *p= *f;
          while(f>fb){ f-=ms;
            sc=f->re+p->re*w.re-p->im*w.im;
            p->im=f->im+p->im*w.re+p->re*w.im; p->re=sc; }
          sc=w.re*b.re-w.im*b.im;
          w.im=w.im*b.re+w.re*b.im; w.re=sc;
         }
        for(k=0,f=fb,p=d; k<kp ;++k,f+=ms) *f= *p++;
        sc=z.re*a.re-z.im*a.im;
        z.im=z.im*a.re+z.re*a.im; z.re=sc;
       }
     }
   }
  free(d); free(mm);
}
