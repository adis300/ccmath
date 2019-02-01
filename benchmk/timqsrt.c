/*  timqsrt.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Time the sort of an array orreal numbers using quick-sort.

    Input parameter:  size= n -> array of n double precision numbers
*/
#include <time.h>
#include "ccmath.h"
void main(int na,char **av)
{ int i,f,n; double *x,**v;
  unsigned int seed; clock_t st,en;
  if(na!=2){ printf("para: size\n"); exit(1);}
  n=atoi(*++av);
  seed=(unsigned int)time(NULL); setnrml(seed);
  printf("     Time Quick Sort\n");
  printf("  %d points input\n",n);
  x=(double *)calloc(n,sizeof(*x));
  v=(double **)calloc(n,sizeof(x));
  for(i=0; i<n ;) x[i++]=nrml();
  st=clock();
  for(i=0; i<n ;++i) v[i]=x+i;
  qsrt(v,0,n-1,dubcmp);
  en=clock();
  for(i=1,f=0; i<n ;++i){
    if(*v[i] < *v[i-1]){ f=1; break;}
   }
  if(f) printf("  sort failed\n");
  printf(" time= %.3f sec.\n",(double)(en-st)/(double)CLOCKS_PER_SEC);
}
