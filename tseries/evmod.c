/*  evmod.c    CCMATH mathematics library source code.
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
static int max,kst; static double *pz,*pm;
double evmod(double y)
{ struct mcof *p,*q; double yp;
  for(yp=0.,p=par,q=p+nar; p<q ;++p)
    yp+= *(pz+(kst+p->lag)%max) * p->cf;
  for(p=pma,q=p+nma; p<q ;++p)
    yp+= *(pm+(kst+p->lag)%max) * p->cf;
  kst=(kst+max-1)%max; *(pm+kst)=(yp-=y);
  *(pz+kst)=y; return -yp;
}
void setev(int k)
{ int mxm;
  if(k){ max=mxm=kst=0; np=nma+nar;
    if(nar) max=(par+nar-1)->lag+1;
    if(nma && (mxm=(pma+nma-1)->lag+1)>max) max=mxm;
    pz=(double *)calloc(2*max,sizeof(double));
    pm=pz+max;
   }
  else free(pz);
}
