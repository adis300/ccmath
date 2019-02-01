/*  timmsrt.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Time the sort of an array of real numbers using a merge sort.

    Input parameter:  size= n -> array of n double precision numbers
*/
#include <time.h>
#include "ccmath.h"
void main(int na,char **av)
{ struct llst *dat,*s0,*t;
  double *x; int i,f,n;
  clock_t st,en; unsigned int seed;
  if(na!=2){ printf("para: size\n"); exit(1);}
  n=atoi(*++av);
  seed=(unsigned int)time(NULL); setnrml(seed);
  printf("     Time Merge Sort\n");
  printf("  %d input points\n",n);
  x=(double *)calloc(n,sizeof(*x));
  for(i=0; i<n ;) x[i++]=nrml();
  dat=(struct llst *)calloc(n,sizeof(*dat));
  st=clock();
  for(i=0,s0=dat,t=s0; i<n ;++i){
    t->pls=(char *)(x+i); t->pt=t+1; ++t;}
  (t-1)->pt=NULL;
  s0=msort(s0,n,dubcmp);
  en=clock();
  for(t=s0,f=0; t->pt!=NULL ;t=t->pt){
    if(*(double *)(t->pt->pls) < *(double *)(t->pls)){ f=1; break;}
   }
  if(f) printf("  sort failed\n");
  printf(" time : %.3f sec.\n",(double)(en-st)/(double)CLOCKS_PER_SEC);
}
