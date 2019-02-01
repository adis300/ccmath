/*  plsq.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <stdlib.h>
#include "orpol.h"
void plsq(double *x,double *y,int n,Opol *cf,double *ssq,int m)
{ double *pm,*e,*p,*q;
  double f,s,t,u,w,tp; int i,j,k,l;
  pm=(double *)calloc(3*n,sizeof(double));
  for(i=0,w=u=0.,e=pm,p=e+n; i<n ;++i){
    w+=y[i]; u+=x[i]; *p++ =1.; *e++ =y[i];
   }
  cf[0].hs=tp=(double)n; cf[0].cf=w/tp; cf[0].df=u/tp; 
  for(k=1; k<m ;++k){ l=k-1;
    for(j=0,s=t=u=w=0.,e=pm,p=e+n,q=p+n; j<n ;++j){
      *e-= cf[l].cf* *p; s+= *e* *e;
      f=(x[j]-cf[l].df)* *p- cf[l].hs* *q;
      *q++ = *p; *p++ =f; w+=f* *e++;
      t+=(f*=f); if(k<m-1) u+=x[j]*f;
     }
    ssq[l]=s; cf[k].cf=w/t; if(k<m-1) cf[k].df=u/t;
    cf[k].hs=t/tp; tp=t;
   }
  l=m-1; t=cf[l].cf; cf[l].df=0.;
  for(j=0,e=pm,p=e+n,s=0.; j<n ;++j,++e){
    *e-=t* *p++; s+= *e* *e; 
   }
  ssq[l]=s;
  free(pm);
}
