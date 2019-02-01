/*  tbran.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  bran  setbran

    Input parameters:  s -> unsigned integer: pseudorandom generator seed
                       n -> integer parameter (output range [0,n-1])
                       m -> sample size
*/
#include "ccmath.h"
void main(int na,char **av)
{ unsigned int s; int n,m,i,k,*nh;
  if(na!=4){ printf("para: seed(hex) argument num_out\n"); exit(-1);}
  sscanf(*++av,"%x",&s); n=atoi(*++av); m=atoi(*++av);
  printf(" seed= %x\n",s);
  printf(" arg: n= %d\n",n);
  printf(" sample sizw m= %d\n",m);
  nh=(int *)calloc(sizeof(int),n+1);

/* initialize pseudorandom integer generator */
  setbran(s);

  for(i=0; i<m ;++i){

/* generate a random integer in thr range 0 to n-1 */
    k=bran(n); ++nh[k];
    if(m<100) printf(" %4d  %4d\n",i,k);
   }
  printf(" distribution\n");
  for(i=0; i<=n ;++i) printf("%3d  %4d\n",i,nh[i]);
}
/* Test output

 seed= 57a5387
 arg: n= 10
 sample sizw m= 20000
 distribution
  0  2017
  1  2039
  2  2035
  3  1998
  4  1923
  5  1982
  6  2080
  7  1992
  8  1951
  9  1983
 10     0
*/
