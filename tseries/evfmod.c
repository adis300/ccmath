/*  evfmod.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "armaf.h"
#include <stdlib.h>
extern struct mcof *par,*pma,*pfc;
extern int nar,nma,nfc,np,ndif;
static int kst,max,*kz; static double *pm,*pz;
double evfmod(struct fmod y)
{ struct mcof *p,*q; double yp,sa,*pd; int j;
  yp=sa=(pfc+y.fac)->cf;
  if(ndif){ pd=pz+2*max;
     for(j=0; j<ndif ;j++){
        sa=yp- *pd; *pd++ =yp; yp=sa;}
    }
  for(p=par,q=p+nar; p<q ;p++)
     yp+= *(pz+(kst+p->lag)%max) * p->cf;
  for(p=pma,q=p+nma; p<q ;p++)
     yp+= *(pm+(kst+p->lag)%max) * p->cf;
  kst=(kst+max-1)%max; *(pm+kst)=(yp-=y.val);
  *(pz+kst)=y.val-sa; *(kz+kst)=y.fac;
  return -yp;
}
void setevf(int k)
{ int mxm;
  if(k){ max=mxm=kst=0; np=nfc+nma+nar;
      if(nar) max=(par+nar-1)->lag+1;
      if(nma && (mxm=(pma+nma-1)->lag+1)>max) max=mxm;
      pz=(double *)calloc(2*max+ndif,sizeof(double));
      kz=(int *)calloc(max,sizeof(int));
      pm=pz+max; }
  else{ free(pz); free(kz);}
}
