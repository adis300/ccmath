/*  drmod.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "arma.h"
#include <stdlib.h>
extern struct mcof *par,*pma;
extern int nar,nma,np;
static int max,mxm,kst,kd; static double *pz,*pm;
double drmod(double y,double *dr)
{ struct mcof *p,*q; double yp,*pf,*pd,*pl;
  yp=0.; pl=dr+np;
  for(pf=dr,p=par,q=p+nar; p<q ;++p){
    *pf= *(pz+(kst+p->lag)%max);
    yp+= p->cf * *pf++;
   }
  for(p=pma,q=p+nma; p<q ;++p){
    *pf= *(pm+(kst+p->lag)%max);
    yp+= p->cf * *pf++;
   }
  if(nma){
    for(pf=dr,pd=pz+2*max; pf<pl ;++pd,++pf)
      for(p=pma,q=p+nma; p<q ;++p)
        *pf+= p->cf * *(pd+((kd+p->lag)%mxm)*np);
    kd=(kd+mxm-1)%mxm; pd=pz+2*max+np*kd;
    for(pf=dr; pf<pl ;) *pd++ = *pf++;
   }
  kst=(kst+max-1)%max; *(pm+kst)=(yp-=y);
  *(pz+kst)=y; return -yp;
}
void setdr(int k)
{ if(k){ max=mxm=kst=kd=0; np=nma+nar;
    if(nar) max=(par+nar-1)->lag+1;
    if(nma && (mxm=(pma+nma-1)->lag+1)>max) max=mxm;
    pz=(double *)calloc(2*max+np*mxm,sizeof(double));
    pm=pz+max;
   }
  else free(pz);
}
