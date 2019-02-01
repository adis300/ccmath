/*  tbran2.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  bran2  setbran2

    Input parameters:  s -> unsigned integer: pseudorandom generator seed
                       n -> integer parameter
                       m -> sample size
*/
#include "ccmath.h"
void main(int na,char **av)
{ unsigned int s; int n,m,i,k,*nh;
  if(na!=4){ printf("para: seed(hex) argument num_out\n"); exit(-1);}
  sscanf(*++av,"%x",&s); n=atoi(*++av); m=atoi(*++av);
  printf(" seed= %x\n",s);
  printf(" arg: n= %d\n",n);
  printf(" sample size m= %d\n",m);
  nh=(int *)calloc(sizeof(int),n+1);

/* initialize pseudorandom integer generator */
  setbran2(s);

  for(i=0; i<m ;++i){

/* generate a random integer in thr range 0 to n-1 */
    k=bran2(n); ++nh[k];
    if(m<100) printf(" %4d  %4d\n",i,k);
   }
  printf(" distribution\n");
  for(i=0; i<=n ;++i) printf("%3d  %4d\n",i,nh[i]);
}
/* Test output

 seed= ef7bdb3
 arg: n= 12
 sample size m= 240000
 distribution
  0  19750
  1  20128
  2  20234
  3  20022
  4  20118
  5  20006
  6  19816
  7  20083
  8  19867
  9  20116
 10  19963
 11  19897
 12     0
*/
