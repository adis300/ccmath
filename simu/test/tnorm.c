/*  tnorm.c    CCMATH mathematics library source code.
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
    Test:  norm  setnorm

    Input parameters:  s -> unsigned integer: pseudorandom generator seed
                       n -> integer: sample size
*/
#include "ccmath.h"
void main(int na,char **av)
{ double err[2],xm,ssq; unsigned int s;
  int n,i,p;
  if(na!=3){ printf("para: seed size\n"); exit(-1);}
  sscanf(*++av,"%x",&s); n=atoi(*++av);
  printf(" seed= %x\n",s);
  printf(" sample size= %d\n",n);
  if(n>1000) p=0; else p=1;
/* initialize generator */
  setnorm(s); xm=ssq=0.;
  for(i=0; i<n ;i+=2){

/* generate Box-Miller random normals */
    norm(err);

    if(p){ printf(" %4d  %9.4f\n",i,err[0]);
      printf(" %4d  %9.4f\n",i+1,err[1]);
     }
    xm+=(err[0]+err[1]);
    ssq+=(err[0]*err[0]+err[1]*err[1]);
   }
  printf(" xmean= %e  mean-sq= %e\n",xm/n,ssq/n);
}
/* Test output

 seed= 7766805b
 sample size= 20
    0    -0.4754
    1     0.7146
    2    -1.1171
    3    -1.6604
    4    -0.9207
    5     0.4097
    6    -0.5606
    7     1.9327
    8     1.0167
    9     0.4116
   10    -0.4588
   11     0.6418
   12     2.5712
   13     0.5139
   14     0.3770
   15     1.1803
   16    -2.0606
   17     0.4766
   18    -0.2401
   19    -0.2630
 xmean= 1.244806e-01  mean-sq= 1.232132e+00
*/
