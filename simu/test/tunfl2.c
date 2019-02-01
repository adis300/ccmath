/*  tunfl2.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
     Test:  unfl2()  setunfl2()

     Input parameters: s -> unsigned integer: pseudorandom seed
                       n -> integer: sample size
*/
#include <math.h>
#include "ccmath.h"
void main(int na,char **av)
{ double x,xm,ssq; unsigned int s;
  int n,i,p;
  if(na!=3){ printf("para: seed(hex) size\n"); exit(-1);}
  sscanf(*++av,"%x",&s); n=atoi(*++av);
  printf(" seed= %x\n",s);
  printf(" sample size= %d\n",n);
  if(n>1000) p=0; else p=1;
/* initialize pseudorandom uniform generator */
  setunfl2(s);

  xm=ssq=0.;
  for(i=0; i<n ;++i){
 
/* generate a random number on [0,1] */
    x=unfl2();

    if(p) printf(" %4d  %f\n",i,x);
    xm+=x; x-=.5; ssq+=x*x;
   }
  printf(" xmean= %e  mean-sq= %e\n",xm/n,ssq/n);
}
/* Test output

 seed= f53814d1
 sample size= 20
    0  0.245931
    1  0.591419
    2  0.356836
    3  0.211378
    4  0.533397
    5  0.319682
    6  0.682214
    7  0.359572
    8  0.980991
    9  0.025067
   10  0.707456
   11  0.038997
   12  0.656155
   13  0.022205
   14  0.300957
   15  0.842522
   16  0.134199
   17  0.437262
   18  0.451750
   19  0.227005
 xmean= 4.062498e-01  mean-sq= 7.999734e-02
*/

