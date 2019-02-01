/*  tprand.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  autcor  hist

    Uses:  setunfl  setunfl2  setnrml  setnorm2
           unfl  unfl2  nrml  norm2

    Input parameter:
		       seed -> unsigned int: random generator seed
*/
#include "ccmath.h"
#include <math.h>
void main(int na,char **av)
{ int n,f,k,i,j,lag,kb,*his;
  unsigned int seed;
  double *x,*p,a,b,h,bin,err[2];
  if(na!=2){
    printf("para: seed(hex)\n"); exit(1);}
  sscanf(*++av,"%x",&seed);
  lag=20; n=1000000;
  x=(double *)calloc(sizeof(*x),n);
  printf("     Test of Pseudorandom Generator Distributions\n\n");
  for(i=0; i<4 ;++i){
	switch(i){
	  case 0: f=0; k=0; break;
	  case 1: f=1; k=0; break;
	  case 2: f=0; k=1; break;
	  case 3: f=1; k=1; break;
	 }
    if(f) printf(" normal distribution ");
    else printf(" uniform distribution ");
    printf("generator type %d\n",k); printf("  seed = %x\n",seed);

/* generate sample of requested type */
    if(f){ a= -(b=3.); kb=12;
      if(k) setnorm2(seed); else setnrml(seed);
      for(j=0,p=x; j<n ;++j){
        if(k){ if((j&1)==0){ norm2(err); *p++ =err[0];}
               else *p++ =err[1];
         }
        else *p++ =nrml();
       }
     }
    else{ a=0.; b=1.; kb=10;
      if(k) setunfl2(seed); else setunfl(seed);
      for(j=0,p=x; j<n ;++j){
        if(k) *p++ =unfl2(); else *p++ =unfl(); }
     }

/* compute sample histogram */
    printf(" histrogram\n");
    his=hist(x,n,a,b,kb,&bin);
    for(k=0,h=a; k<kb ;a+=bin,++k)
      printf(" %6.2f to %6.2f  %4d\n",a,h+=bin,*(his+k));
    printf("  under= %d  over= %d\n",*(his-1),*(his+kb));
    if(!f){ for(k=0; k<n ;) x[k++]-=.5;}

/* compute sample autocorrelations */
    printf(" series autocorrelations\n");
    p=autcor(x,n,lag);
    printf("   second moment = %e  ",*p);
    printf("sig. cf = %f\n",sqrt(1./n));
    for(k=1,kb=lag/2+1; k<=lag/2 ;++k,++kb)
      printf("   %2d  %8.4f    %2d  %8.4f\n",k,*(p+k),kb,*(p+kb));
	printf("\n");
   }
}
/* Test output

     Test of Pseudorandom Generator Distributions

 uniform distribution generator type 0
  seed = 4c7605e3
 histrogram
   0.00 to   0.10  100686
   0.10 to   0.20  99872
   0.20 to   0.30  99988
   0.30 to   0.40  100152
   0.40 to   0.50  100347
   0.50 to   0.60  100049
   0.60 to   0.70  99832
   0.70 to   0.80  100019
   0.80 to   0.90  99549
   0.90 to   1.00  99506
  under= 0  over= 0
 series autocorrelations
   second moment = 8.330915e+04  sig. cf = 0.001000
    1   -0.0003    11   -0.0001
    2   -0.0001    12    0.0009
    3   -0.0025    13    0.0012
    4    0.0006    14   -0.0000
    5   -0.0012    15    0.0019
    6   -0.0009    16    0.0008
    7   -0.0001    17    0.0001
    8   -0.0008    18   -0.0002
    9    0.0009    19   -0.0004
   10    0.0001    20    0.0009

 normal distribution generator type 0
  seed = 4c7605e3
 histrogram
  -3.00 to  -2.50  4854
  -2.50 to  -2.00  16522
  -2.00 to  -1.50  44196
  -1.50 to  -1.00  91372
  -1.00 to  -0.50  150483
  -0.50 to   0.00  191627
   0.00 to   0.50  191121
   0.50 to   1.00  149796
   1.00 to   1.50  91644
   1.50 to   2.00  44074
   2.00 to   2.50  16766
   2.50 to   3.00  4809
  under= 1333  over= 1403
 series autocorrelations
   second moment = 1.000870e+06  sig. cf = 0.001000
    1   -0.0014    11   -0.0002
    2   -0.0003    12   -0.0025
    3   -0.0004    13   -0.0010
    4    0.0011    14   -0.0005
    5    0.0003    15   -0.0004
    6   -0.0007    16    0.0003
    7    0.0004    17    0.0007
    8   -0.0005    18   -0.0012
    9   -0.0000    19    0.0014
   10   -0.0000    20   -0.0002

 uniform distribution generator type 1
  seed = 4c7605e3
 histrogram
   0.00 to   0.10  99943
   0.10 to   0.20  100143
   0.20 to   0.30  100064
   0.30 to   0.40  100439
   0.40 to   0.50  99358
   0.50 to   0.60  100051
   0.60 to   0.70  99932
   0.70 to   0.80  100050
   0.80 to   0.90  100114
   0.90 to   1.00  99906
  under= 0  over= 0
 series autocorrelations
   second moment = 8.334222e+04  sig. cf = 0.001000
    1   -0.0011    11    0.0000
    2    0.0000    12   -0.0005
    3    0.0013    13   -0.0031
    4   -0.0010    14    0.0003
    5   -0.0009    15    0.0000
    6   -0.0012    16    0.0000
    7    0.0003    17    0.0016
    8    0.0002    18   -0.0000
    9   -0.0003    19   -0.0010
   10   -0.0002    20    0.0001

 normal distribution generator type 1
  seed = 4c7605e3
 histrogram
  -3.00 to  -2.50  4796
  -2.50 to  -2.00  16312
  -2.00 to  -1.50  44162
  -1.50 to  -1.00  92108
  -1.00 to  -0.50  150358
  -0.50 to   0.00  191441
   0.00 to   0.50  190900
   0.50 to   1.00  150109
   1.00 to   1.50  91734
   1.50 to   2.00  43993
   2.00 to   2.50  16527
   2.50 to   3.00  4853
  under= 1355  over= 1352
 series autocorrelations
   second moment = 9.987381e+05  sig. cf = 0.001000
    1    0.0002    11    0.0008
    2    0.0017    12    0.0005
    3   -0.0008    13   -0.0001
    4   -0.0004    14    0.0015
    5   -0.0012    15   -0.0002
    6   -0.0013    16   -0.0017
    7    0.0012    17    0.0001
    8    0.0010    18    0.0009
    9    0.0006    19   -0.0002
   10   -0.0014    20   -0.0007

*/
