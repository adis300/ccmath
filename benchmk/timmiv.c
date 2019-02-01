/*  timmiv.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
     Time the execution of a matrix inverse

     Input parameter: n = dimension of matrix
*/
#include <time.h>
#include "ccmath.h"
void main(na,av)
int na; char **av;
{ int i,j,n;
  unsigned int seed; clock_t st,en;
  double *a;
  if(na!=2){ printf("para: dim\n"); exit(1);}
  printf("     Time Matrix Inverse\n");
  n=atoi(*++av);
  seed=(unsigned int)time(NULL); setnrml(seed);
  printf(" dimension: %d x %d\n",n,n);
  a=(double *)calloc(n*n,sizeof(double));
  for(i=0,j=n*n; i<j ;) a[i++]=nrml();
  st=clock();
  i=minv(a,n);
  en=clock();
  printf(" time= %.3f sec.\n",(double)(en-st)/(double)CLOCKS_PER_SEC);
  if(i) printf(" singular matrix\n");
  else printf(" matrix inverted\n");
}
