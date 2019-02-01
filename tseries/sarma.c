/*  sarma.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "arma.h"
#include <stdlib.h>
extern struct mcof *par,*pma;
extern int nar,nma;
static int kst,max; static double *pz,*pm;
double sarma(double er)
{ struct mcof *p,*q; double y;
  for(y=er,p=par,q=p+nar; p<q ;++p)
    y+= p->cf * *(pz+(kst+p->lag)%max);
  for(p=pma,q=p+nma; p<q ;++p)
    y-= p->cf * *(pm+(kst+p->lag)%max);
  kst=(kst+max-1)%max; *(pm+kst)=er; *(pz+kst)=y;
  return y;
}
void setsim(int k)
{ int m;
  if(k){ kst=max=m=0;
    if(nar) max=(par+nar-1)->lag+1;
    if(nma && (m=(pma+nma-1)->lag+1)>max) max=m;
    pz=(double *)calloc(2*max,sizeof(double));
    pm=pz+max;
   }
  else free(pz);
}
