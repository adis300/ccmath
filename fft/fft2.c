/*  fft2.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "complex.h"
void fft2(struct complex *ft,int m,int inv)
{ int n,i,j,k,mm,mp;
  double s,t,ang,tpi=6.283185307179586;
  struct complex u,w,*p,*q,*pf;
  n=1; n<<=m; pf=ft+n-1;
  for(j=0,p=ft; p<pf ;++p){ q=ft+j;
    if(p<q){ t=p->re; p->re=q->re; q->re=t;
             t=p->im; p->im=q->im; q->im=t; }
    for(mm=n/2; mm<=j ;mm/=2) j-=mm; j+=mm;
   }
  if(inv=='d') for(p=ft,s=1./n; p<=pf ;){
                  p->re*=s; (p++)->im*=s; }
  for(i=mp=1; i<=m ;++i){
    mm=mp; mp*=2; ang=tpi/mp; if(inv=='d') ang= -ang;
    w.re=cos(ang); w.im=sin(ang);
    for(j=0; j<n ;j+=mp){ p=ft+j;
      u.re=1.; u.im=0.;
      for(k=0; k<mm ;++k,++p){ q=p+mm;
        t=q->re*u.re-q->im*u.im;
        s=q->im*u.re+q->re*u.im;
        q->re=p->re-t; q->im=p->im-s;
        p->re+=t; p->im+=s;
        t=u.re*w.re-u.im*w.im;
        u.im=u.im*w.re+u.re*w.im; u.re=t;
       }
     }
   }
}
