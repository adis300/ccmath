/*  tsamshf.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  sampl  shuffl

    Uses:  bran  setbran

    Input parameters:  nt -> integer: number of samples generated
                       seed -> unsigned integer: pseudorandom generator seed
*/
#include <stdlib.h>
#include "ccmath.h"
#define MM 20
#define MS 5
int his[MS][MM];
void main(int na,char **av)
{ int dat[MM],*bdf[MM],*sam[MS];
  int nt,n,m,i,j,k; unsigned int ns,seed;
  n=MM; m=MS;
  if(na!=3){ printf("para: reps seed\n"); exit(-1);}
  nt=atoi(*++av);
/* initialize pseudorandom generator */
  sscanf(*++av,"%x",&seed); setbran(seed);
  printf("     Random Sample Test\n");
  printf("      seed= %x\n",seed);
  for(i=0,ns=0; i<n ;++i){
    dat[i]=i+1; bdf[i]=dat+i;
   }
  for(i=0; i<nt ;++i){

/* generate random sample */
    sampl((void *)sam,m,(void *)bdf,n);
/* shuffle random sample */
    shuffl((void *)sam,m);

    for(j=0; j<m ;++j){
      k= *sam[j]-1; ++his[j][k];
     }
    ns+=m;
   }
  printf("\n total points %d\n",ns);
  printf(" frequencies of appearence\n");
  printf(" val  p1   p2   p3   p4   p5  subtotals\n");
  for(i=0; i<n ;++i){
    printf(" %2d",i+1);
    for(j=k=0; j<m ;++j){
      printf("  %3d",his[j][i]);
      k+=his[j][i];
     }
    printf("    %d\n",k);
   }
}
/*  Test output

     Random Sample Test
      seed= ae595c0e

 total points 50000
 frequencies of appearence
 val  p1   p2   p3   p4   p5  subtotals
  1  483  482  515  507  505    2492
  2  501  519  479  465  538    2502
  3  502  517  516  490  512    2537
  4  508  488  485  497  504    2482
  5  513  439  525  547  478    2502
  6  516  506  483  515  495    2515
  7  472  506  508  516  510    2512
  8  507  475  482  478  510    2452
  9  475  521  475  490  488    2449
 10  455  460  495  542  507    2459
 11  485  532  501  492  513    2523
 12  475  514  513  486  504    2492
 13  516  493  490  523  471    2493
 14  519  515  507  497  467    2505
 15  506  516  517  493  521    2553
 16  535  484  530  518  468    2535
 17  498  544  516  475  501    2534
 18  510  477  517  478  493    2475
 19  536  496  477  492  519    2520
 20  488  516  469  499  496    2468
*/
