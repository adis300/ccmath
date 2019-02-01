/*  timslpac.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Time the solution of a real linear system of 'small' dimension.

    Input parameters:  dim= n -> a system of dimension n
                       iterations= m -> repeat computation m times
*/
#include <time.h>
#include "ccmath.h"
void main(int na,char **av)
{ int i,j,k,n,n2,n3,m;
  double *a,*a1,*x,*p; unsigned int seed;
  double dt,s; clock_t st,en;
  if(na!=3){ printf(" para: dim iterations\n"); exit(1);}
  printf("     Time Small Linpac");
  n=atoi(*++av); m=atoi(*++av); n2=n*n; n3=n2+n;
  printf(" dim: %d  itt: %d\n",n,m);
  a=(double *)calloc(m*n3,sizeof(double));
  seed=(unsigned int)time(NULL); setnrml(seed);
  for(k=0,a1=a; k<m ;++k,a1+=n3){
    for(i=0,p=a1; i<n2 ;++i) *p++ =nrml();
    for(p=a1,x=a1+n2,i=0; i<n ;++i){ x[i]=0.;
      for(j=0; j<n ;++j) x[i]+= *p++;
     }
   }
  st=clock();
  for(i=0,a1=a; i<m ;++i){
    x=a1+n2;
    k=solv(a1,x,n);
    if(k) printf(" matrix singular");
    a1+=n3;
   }
  en=clock();
  dt=(double)(en-st)/(double)CLOCKS_PER_SEC;
  dt/=(double)m;
  printf(" time : %.3f sec.",dt);
  s=(double)n;
  s=2*(s/3.+1.)*s*s/(1.e6*dt);
  printf("  %.2f Mflops\n",s);
}
