/*  tnrml.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
     Test:  nrml()  setnrml()

     Input parameters:  s -> unsigned integer: pseudorandom seed
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
/* initialize pseudorandom normal generator */
  setnrml(s);

  xm=ssq=0.;
  for(i=0; i<n ;++i){
 
/* generate a random normal */
   x=nrml();

    if(p) printf(" %4d  %f\n",i,x);
    xm+=x; ssq+=x*x;
   }
  printf(" xmean= %e  mean-sq= %e\n",xm/n,ssq/n);
}
/* Test output

 seed= 11b6976b
 sample size= 20
    0  0.389395
    1  -0.415056
    2  0.357256
    3  -2.008815
    4  0.920138
    5  -0.299221
    6  -0.535197
    7  0.122434
    8  -0.880706
    9  0.212040
   10  -0.716048
   11  -0.697573
   12  0.386809
   13  0.488488
   14  0.409810
   15  0.611474
   16  -0.199908
   17  -0.150721
   18  0.516392
   19  0.642420
 xmean= -4.232949e-02  mean-sq= 4.608276e-01
*/
