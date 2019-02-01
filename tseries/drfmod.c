/*  drfmod.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "armaf.h"
#include <stdlib.h>
extern struct mcof *pfc,*par,*pma;
extern int nar,nma,nfc,np,ndif;
static int kst,kd,max,mxm,*kz; static double *pm,*pz;
double drfmod(struct fmod y,double *dr)
{ struct mcof *p,*q; double yp,*pf,*pd,*pl,sa; int j;
  yp=sa=(pfc+y.fac)->cf;
  for(j=0,pf=dr; j<nfc ;j++,pf++){
     if(j==y.fac) *pf=1.; else *pf=0.;
     for(p=par,q=p+nar; p<q ;p++)
        if(*(kz+(kst+p->lag)%max)==j) *pf -= p->cf;
    }
  if(ndif){ pd=pz+2*max+np*mxm; pl=dr+nfc;
     for(pf=dr; pf<pl ;pf++)
        for(j=0; j<ndif ;j++){
           sa= *pf- *pd; *pd++ = *pf; *pf=sa;}
     for(j=0; j<ndif ;j++){
        sa=yp- *pd; *pd++ =yp; yp=sa;}
    }
  for(p=par,q=p+nar; p<q ;p++){
     *pf= *(pz+(kst+p->lag)%max);
     yp += p->cf * *pf++;}
  for(p=pma,q=p+nma; p<q ;p++){
     *pf= *(pm+(kst+p->lag)%max);
     yp += p->cf * *pf++;}
  if(nma){ pl=dr+np;
      for(pf=dr,pd=pz+2*max; pf<pl ;pd++,pf++)
         for(p=pma,q=p+nma; p<q ;p++)
             *pf += p->cf * *(pd+((kd+p->lag)%mxm)*np);
      kd=(kd+mxm-1)%mxm; pd=pz+2*max+np*kd;
      for(pf=dr; pf<pl;) *pd++ = *pf++;
     }
  kst=(kst+max-1)%max; *(pm+kst)=(yp-=y.val);
  *(pz+kst)=y.val-sa; *(kz+kst)=y.fac;
  return -yp;
}
void setdrf(int k)
{ if(k){ max=mxm=kst=kd=0; np=nfc+nma+nar;
      if(nar) max=(par+nar-1)->lag+1;
      if(nma && (mxm=(pma+nma-1)->lag+1)>max) max=mxm;
      pz=(double *)calloc(2*max+np*mxm+ndif*(nfc+1),sizeof(double));
      kz=(int *)calloc(max,sizeof(int));
      pm=pz+max; }
  else{ free(pz); free(kz);}
}
