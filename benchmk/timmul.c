/*  timmul.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Time the multiplication of two real square matrices.

    Input parameter:  dimension= n -> matrices are n by n
*/
#include <time.h>
#include "ccmath.h"
void main(int na,char **av)
{ int i,n,m;
  clock_t st,en; unsigned int seed;
  double dt,r,*a,*b,*c,*p,*q;
  if(na!=2){ printf("para: dimension\n"); exit(1);}
  n=atoi(*++av);
  m=n*n;
  a=(double *)calloc(3*m,sizeof(double));
  b=a+m; c=b+m;
  seed=(unsigned int)time(NULL); setnrml(seed);
  for(i=0,p=a,q=b; i<m ;++i){
    *p++ =nrml(); *q++ =nrml();
   }
  printf(" Matrix multiply: dim= %d\n",n);
  st=clock();
  mmul(c,a,b,n);
  en=clock();
  dt=(double)(en-st)/(double)CLOCKS_PER_SEC;
  printf(" time= %.2f sec.",dt);
  r=(double)n; r=2*r*r*r/(1.e6*dt);
  printf("   %.2f Mflops\n",r);
}
