/*  timlpac.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Time the solution of real linear systems.

    Input parameter:  dim= n -> system of n linear equations
*/
#include <time.h>
#include "ccmath.h"
void main(int na,char **av)
{ int i,j,n; double *a,*x,*p;
  unsigned int seed;
  double dt,s,cmax,fabs(); clock_t st,en;
  if(na!=2){ printf(" para: dim\n"); exit(1);}
  n=atoi(*++av); printf(" lpac : dim= %d\n",n);
  a=(double *)calloc(n*n+n,sizeof(double));
  x=a+n*n;
  seed=(unsigned int)time(NULL); setnrml(seed);
  for(i=0,p=a,j=n*n; i<j ;++i) *p++ =nrml();
  for(p=a,i=0; i<n ;++i){ x[i]=0.;
    for(j=0; j<n ;++j) x[i]+= *p++;
   }
  st=clock();
  i=solv(a,x,n);
  en=clock();
  dt=(double)(en-st)/(double)CLOCKS_PER_SEC;
  printf(" time= %.2f sec.",dt);
  s=(double)n; s=2*(s*s*s/3+s*s);
  s=s/(1.e6*dt);
  printf("  %.2f Mflops\n",s);
  if(i) printf(" matrix singular\n");
  else{
    for(j=0,cmax=0.; j<n ;++j){
      s=fabs(x[j]-1.); if(cmax<s) cmax=s;
     }
    printf(" max_err: %e\n",cmax);
   }
}
