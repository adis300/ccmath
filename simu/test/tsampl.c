/*  tsampl.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
                    CCMATH
    Numerical Analysis Library Test Program
    Copyright 1993, 1996 by The Calculating
    Company. All rights reserved.
*/
/*
    Test:  sampl

    Uses:  bran  setbran

    Input parameters:  nt -> integer: number of samples
                       seed -> unsigned integer: pseudorandom generator seed
*/
#include "ccmath.h"
#define MM 30
void main(int na,char **av)
{ int dat[MM],*bdf[MM],his[MM],*sam[6];
  int nt,ns,n,m,i,j,k,p; unsigned int seed;
  n=MM; m=6;
  if(na!=3){ printf("para: reps seed\n"); exit(-1);}
  nt=atoi(*++av);
  if(nt>30) p=0; else p=1;
/* initialize random generator */
  sscanf(*++av,"%x",&seed); setbran(seed);
  printf("     Random Sample Generator Test\n");
  printf("      seed= %x\n",seed);
  for(i=0,ns=0; i<n ;++i){
    dat[i]=i+1; bdf[i]=dat+i;
    his[i]=0;
   }
  for(i=0; i<nt ;++i){

/* generate  a random sample */
    sampl((void *)sam,m,(void *)bdf,n);

    for(j=0; j<m ;++j){
      if(p) printf("%3d",*sam[j]);
      k= *sam[j]-1; ++his[k];
     }
    if(p) printf("\n");
    ns+=m;
   }
  printf("\n total points %d\n",ns);
  printf(" frequency of appearence\n");
  for(i=0; i<n ;++i){
    nt+=his[i];
    printf(" %2d %3d\n",i+1,his[i]);
   }
}
/*  Test output

     Random Sample Generator Test
      seed= c1a34567

 total points 30000
 frequency of appearence
  1 1018
  2 944
  3 1026
  4 1012
  5 1023
  6 1002
  7 985
  8 1026
  9 1029
 10 1022
 11 1003
 12 959
 13 990
 14 1004
 15 1066
 16 954
 17 973
 18 1002
 19 975
 20 989
 21 990
 22 991
 23 1030
 24 1065
 25 975
 26 998
 27 993
 28 955
 29 1005
 30 996
*/
