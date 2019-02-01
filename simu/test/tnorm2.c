/*  tnorm2.c    CCMATH mathematics library source code.
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
    Test:  norm2  setnorm2

    Input parameters:  s -> unsigned integer: pseudorandom generator seed
                       n -> integer: sample size
*/
#include "ccmath.h"
void main(int na,char **av)
{ double err[2],xm,ssq; unsigned int s;
  int n,i,p;
  if(na!=3){ printf("para: seed(hex) size\n"); exit(-1);}
  sscanf(*++av,"%x",&s); n=atoi(*++av);
  printf(" seed= %x\n",s);
  printf(" sample size= %d\n",n);
  if(n>1000) p=0; else p=1;
/* initialize generator */
  setnorm2(s); xm=ssq=0.;

  for(i=0; i<n ;i+=2){

/* generate Box-Miller random normals with twin generator */
    norm2(err);

    if(p){ printf(" %4d  %9.4f\n",i,err[0]);
      printf(" %4d  %9.4f\n",i+1,err[1]);
     }
    xm+=(err[0]+err[1]);
    ssq+=(err[0]*err[0]+err[1]*err[1]);
   }
  printf(" xmean= %e  mean-sq= %e\n",xm/n,ssq/n);
}
/* Test output

 seed= a1b43111
 sample size= 20
    0    -1.6701
    1     3.1519
    2    -1.0815
    3     0.4229
    4     0.9838
    5    -1.0430
    6     0.1266
    7    -1.2081
    8    -0.1535
    9     0.8915
   10    -0.6163
   11    -0.2361
   12     0.8868
   13    -0.0037
   14    -0.5396
   15     2.6231
   16    -0.1957
   17     0.4740
   18     1.0475
   19     1.1288
 xmean= 2.494649e-01  mean-sq= 1.472544e+00
*/
