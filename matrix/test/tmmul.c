/*  tmmul.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  mmul

    Uses:  matprt nrml

    Input parameter:  n -> size square matrices are n by n
*/
#include "ccmath.h"
unsigned int seed=123456789;
void main(int na,char **av)
{ int i,n,m;
  double *a,*b,*c,*p,*q;
  if(na!=2){ printf("para: dim\n"); exit(1);}
  n=atoi(*++av); m=n*n;
  a=(double *)calloc(3*m,sizeof(double));
  b=a+m; c=b+m;
  setnrml(seed);
  for(i=0,p=a,q=b; i<m ;++i){
    *p++ =nrml(); *q++ =nrml();
   }

/* multiply two real square matrices */
  mmul(c,a,b,n);

  printf("matrix a:\n"); matprt(a,n,n," %8.4f");
  printf("matrix b:\n"); matprt(b,n,n," %8.4f");
  printf("product c:\n"); matprt(c,n,n," %8.4f");
}
/* Test output

matrix a:
   0.4557   1.6577  -0.7719  -1.1154   0.0687
  -0.2458  -1.0685   0.3996   1.3866  -0.7969
   1.8117   0.0622  -1.5475  -1.4272  -0.1515
  -0.6791   0.7716   1.1771  -0.8489  -0.9234
   1.4311  -1.6268   0.8424   0.8418  -0.0852
matrix b:
  -0.4533  -0.7214  -0.2094  -0.5361   1.2485
   0.1434   0.5778  -0.0495   0.2262   0.7173
  -0.4851   1.0920  -0.6268   0.9666   1.3036
  -0.3947   0.6178   0.2182  -0.7117  -1.2318
   0.1836  -1.9362   0.3029   0.7723  -0.4174
product c:
   0.8586  -1.0359   0.0837   0.2315   2.0969
  -0.9294   2.3960  -0.0850  -1.3260  -1.9276
   0.4739  -3.5493   0.2301  -1.5542   2.1104
   0.0130   3.4845  -1.0987   1.5674   2.6712
  -1.6388  -0.3675  -0.5893  -0.9859   0.7167
*/
