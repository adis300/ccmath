/*  teigen.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  eigen

    Uses:  smgen  matprt

    Input file:  sm5.bin
*/
#include "ccmath.h"
FILE *fp;
void main(int na,char **av)
{ int n,m;
  double *a,*b,*ev;
  if(na!=2){ printf("para: input_file\n"); exit(1);}
  fp=fopen(*++av,"rb");
  fread((void *)&n,sizeof(int),1,fp);
  m=n*n;
  a=(double *)calloc(2*m+n,sizeof(double));
  ev=a+m; b=ev+n;
  fread((void *)a,sizeof(double),m,fp);
  printf(" dim= %d\n",n);
  printf(" A-in:\n"); matprt(a,n,n," %8.4f");

/* compute eigenvalues and eigenvectors of a real symmetric matrix */
  eigen(a,ev,n);

  printf(" eigen values\n"); matprt(ev,1,n," %8.4f");
  printf(" eigen vectors\n"); matprt(a,n,n," %8.5f");

/* test diagonal transformation by inversion */
  smgen(b,ev,a,n);
  printf(" A-out:\n"); matprt(b,n,n," %8.4f");
}
/* Test output

 dim= 5
 A-in:
   1.6943  -0.4050  -0.5220   0.0590   0.3536
  -0.4050   2.8423  -0.0295   0.0263   0.1459
  -0.5220  -0.0295   2.1464  -0.2846   0.2146
   0.0590   0.0263  -0.2846   1.5947  -0.0474
   0.3536   0.1459   0.2146  -0.0474   1.7222
 eigen values
   3.0000   1.0000   2.5000   2.0000   1.5000
 eigen vectors
  0.35670  0.70265  0.36861  0.47849  0.11923
 -0.90804  0.20064  0.34769  0.09694  0.07017
 -0.21139  0.44377 -0.81189  0.19333 -0.24866
  0.04220  0.09316  0.28980 -0.15768 -0.93845
 -0.04200 -0.51030 -0.00887  0.83631 -0.19580
 A-out:
   1.6943  -0.4050  -0.5220   0.0590   0.3536
  -0.4050   2.8423  -0.0295   0.0263   0.1459
  -0.5220  -0.0295   2.1464  -0.2846   0.2146
   0.0590   0.0263  -0.2846   1.5947  -0.0474
   0.3536   0.1459   0.2146  -0.0474   1.7222
*/
