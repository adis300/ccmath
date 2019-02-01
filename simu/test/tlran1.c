/*  tlran1.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  lran1  setlran1

    Input parameters:  s -> unsigned integer: pseudorandom generator seed
                       n -> integer: sample size
*/
#include "ccmath.h"
void main(int na,char **av)
{ unsigned int s,r; int n,i;
  if(na!=3){ printf("para: seed(hex) num_out\n"); exit(-1);}
  sscanf(*++av,"%x",&s); n=atoi(*++av);
  printf(" seed= %x\n",s);
  printf(" sample size= %d\n",n);

/* initialize pseudorandom integer generator */
  setlran1(s);

  for(i=0; i<n ;++i){

/* generate a random integer */
    r=lran1();

    printf(" %4d  %10lu\n",i,r);
   }
}
/* Test output

 seed= 3da1c1b8
 sample size= 25
    0  1147015565
    1  4215971343
    2  2638703892
    3  2850019134
    4    60758986
    5  2757140380
    6  1503001327
    7  3143427066
    8  3287463124
    9  3962593372
   10  2570482967
   11  1452892730
   12   652187553
   13  3989832113
   14  4164285454
   15  4148572115
   16   933243824
   17   697183984
   18   402603850
   19    54443216
   20  2764401681
   21  2739542720
   22  3445168188
   23  4060914414
   24  4262990861
*/
