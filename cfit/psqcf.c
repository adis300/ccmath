/*  psqcf.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <stdlib.h>
#include "orpol.h"
void psqcf(double *b,Opol *c,int m)
{ int i,j,k; double *sm,*s,u,v;
  if(m>1){
    sm=(double *)calloc(m*m,sizeof(double));
    sm[0]=sm[m+1]=1.; sm[1]= -c[0].df;
    for(i=2; i<m ;++i){ k=i-1;
      for(j=0,s=sm+i,v=0.; j<i ;++j,s+=m){
	*s=v-c[k].df* *(s-1)-c[k].hs* *(s-2);
	v= *(s-1);
       }
      *s=1.;
     }
    for(i=0; i<m ;++i){
      for(j=i,v=0.,s=sm+(m+1)*i; j<m ;++j) v+= *s++ *c[j].cf;
      b[i]=v;
     }
    free(sm);
   }
  else b[0]=c[0].cf;
}
