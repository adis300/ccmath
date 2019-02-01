/*  tlrand.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  lrand  setlrand

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
  setlrand(s);

  for(i=0; i<n ;++i){

/* generate a random integer */
    r=lrand();

    printf(" %4d  %10lu\n",i,r);
   }
}
/* Test output

 seed= 75bcd15
 sample size= 50
    0   469049721
    1  2053676357
    2  1781357515
    3  1206231778
    4   891865166
    5   141988902
    6   553144097
    7   236130416
    8    94122056
    9  1361431000
   10   132558215
   11   965377566
   12   861798677
   13  1620648971
   14  1712160696
   15     3947872
   16  1927375294
   17   753234910
   18   203033305
   19    29242052
   20  1844896448
   21  1805706150
   22   264363646
   23    16132679
   24   558996431
   25  1959543839
   26   244091681
   27   755116797
   28  1767137056
   29   573662182
   30  1486201491
   31  1206160980
   32  1849446827
   33   974514711
   34  1958455755
   35  1284016716
   36   405777109
   37  1635291738
   38   852526260
   39   397959036
   40  1233441294
   41   788183767
   42  1325437273
   43   776376980
   44   457263688
   45  1534315250
   46   252773574
   47   642804452
   48  1771680354
   49  1770944023
*/
