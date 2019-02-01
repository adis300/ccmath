/*  thsort.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  hsort  dubcmp

    Uses:  unfl  surand

    Input parameter:  n -> integer: size of sort list
*/
#include "ccmath.h"
double *x,**v;
void main(int na,char **av)
{ int i,n;
  if(na!=2){ printf("para: size\n"); exit(-1);}
  n=atoi(*++av); setunfl(123456789);
  x=(double *)calloc(n,sizeof(double));
  v=(double **)calloc(n,sizeof(double *));
  printf("     Test of Heap Sort\n");
/* generate series of random values */
  for(i=0; i<n ;) x[i++]=unfl();
  printf("  %d points input\n",n);

/* initialize pointer array */
  for(i=0; i<n ;++i) v[i]=x+i;

/* sort pointer array */
  hsort((void *)v,n,dubcmp);

  printf(" input series    sorted series\n");
  for(i=0; i<n ;++i)
    printf("   %7.3f          %7.3f\n",x[i],*v[i]);
}
/*  Test output

     Test of Heap Sort
  25 points input
 input series    sorted series
     0.550            0.009
     0.071            0.071
     0.905            0.139
     0.779            0.152
     0.009            0.209
     0.688            0.311
     0.152            0.328
     0.209            0.379
     0.757            0.416
     0.838            0.418
     0.790            0.493
     0.493            0.550
     0.931            0.688
     0.963            0.716
     0.311            0.757
     0.418            0.779
     0.821            0.790
     0.379            0.809
     0.416            0.821
     0.920            0.838
     0.861            0.861
     0.139            0.905
     0.328            0.920
     0.716            0.931
     0.809            0.963
*/
