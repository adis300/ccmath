/*  psqvar.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <stdlib.h>
#include "orpol.h"
void psqvar(double *v,double sig,Opol *c,int m)
{ int i,j,k; double *sm,*s,*s1,*u,w,x;
  if(m>1){
    sm=(double *)calloc(m*m+m,sizeof(double));
    u=sm+m*m;
    sm[0]=sm[m+1]=1.; sm[1]= -c[0].df;
    for(i=2; i<m ;++i){ k=i-1;
      for(j=0,s=sm+i,w=0.; j<i ;++j,s+=m){
	*s=w-c[k].df* *(s-1)-c[k].hs* *(s-2);
	w= *(s-1);
       }
      *s=1.;
     }
    for(i=0,w=1.; i<m ;++i){
      w*=c[i].hs; u[i]=sig/w;
     }
    for(i=0,s=sm; i<m ;++i,s+=m){
      for(j=i,s1=sm+j*m; j<m ;++j,s1+=m){
	for(k=j,x=0.; k<m ;++k) x+=s[k]*s1[k]*u[k];
	v[i*m+j]=x; if(i!=j) v[j*m+i]=x;
       }
     }
    free(sm);
   }
  else v[0]=sig/c[0].hs;
}
