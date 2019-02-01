/*  sany.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "../ccmath.h"
int sany(double *x,int n,double *pm,double *cd,double *ci,
       int nd,int ms,int lag)
{ struct complex *pc,*p,**qc,**q;
  int j,kk[16]; double *px,sd,si;
  *pm=xmean(x,n);
  if(nd){
    x[0]=sdiff(x[0],nd,0);
    for(j=1,px=x+1; j<n ;++j,++px)
      *px=sdiff(*px,nd,1);
    x+=nd; n-=nd;
   }
  n=pfac(n,kk,'e');
  pc=(struct complex *)calloc(n,sizeof(*pc));
  qc=(struct complex **)calloc(n,sizeof(*qc));
  fftgr(x,pc,n,kk,'d');
  for(j=0,p=pc; j<n ;++p)
    x[j++]=p->re*p->re+p->im*p->im;
  p=pc;
  if(ms){ smoo(x,n,ms);
    p->re=x[0]; p->im=1./x[0];
   }
  else{ sd=.5*(x[1]+x[n-1]);
    p->re=sd; p->im=1./sd;
   }
  for(j=1,++p; j<n ;++j,++p){
    p->re=x[j]; p->im=1./x[j];
   }
  fftgc(qc,pc,n,kk,'d');
  q=qc;
  sd=cd[0]=(*q)->re; si=ci[0]=(*q)->im;
  for(j=1,++q; j<=lag ;++j,++q){
    cd[j]=(*q)->re/sd; ci[j]=(*q)->im/si;
   }
  free(pc); free(qc);
  return n;
}
