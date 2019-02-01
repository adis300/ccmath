/*  tmsort.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  msort  dubcmp

    Uses:  unfl  surand

    Input parameter:  n -> integer: size of sort list
*/
#include "ccmath.h"
void main(int na,char **av)
{ struct llst *st,*t; int i,n;
  double *x; struct llst *dat;
  unsigned seed;
  if(na!=2){ printf("para: size(<=50)\n"); exit(1);}
  n=atoi(*++av); seed=123456789L;
  x=(double *)calloc(n,sizeof(double));
  dat=(struct llst *)calloc(n,sizeof(struct llst));
  setunfl(seed);
  printf("     Test of Merge Sort\n");
  printf("  %d input points\n",n);
/* generate sort list of random numbers */
  for(i=0; i<n ;) x[i++]=unfl();

/* initialize linked list of pointers */
  st=dat;
  for(i=0,t=st; i<n ;++i){
    t->pls=(char *)(x+i); t->pt=t+1; ++t;
   }
  (t-1)->pt=NULL;

/* sort the linked list */
  st=msort(st,n,dubcmp);

  printf(" input series   sorted series\n");
  for(i=0,t=st; t!=NULL ;++i,t=t->pt)
    printf("   %7.3f         %7.3f\n",x[i],*(double *)(t->pls));
}
/*  Test output

     Test of Merge Sort
  25 input points
 input series   sorted series
     0.550           0.009
     0.071           0.071
     0.905           0.139
     0.779           0.152
     0.009           0.209
     0.688           0.311
     0.152           0.328
     0.209           0.379
     0.757           0.416
     0.838           0.418
     0.790           0.493
     0.493           0.550
     0.931           0.688
     0.963           0.716
     0.311           0.757
     0.418           0.779
     0.821           0.790
     0.379           0.809
     0.416           0.821
     0.920           0.838
     0.861           0.861
     0.139           0.905
     0.328           0.920
     0.716           0.931
     0.809           0.963
*/
