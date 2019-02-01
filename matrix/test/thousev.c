/*  thousev.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  housev

    Uses:  matprt

    Input file:  sm5.bin
*/
#include "ccmath.h"
FILE *fp;
void main(int na,char **av)
{ int n,m;
  double *a,*d,*dp;
  if(na!=2){ printf("para: input_file\n"); exit(1);}
  fp=fopen(*++av,"rb");
  fread((void *)&n,sizeof(int),1,fp);
  m=n*n;
  a=(double *)calloc(m+2*n,sizeof(double));
  d=a+m; dp=d+n;
  fread((void *)a,sizeof(double),m,fp);
  printf(" HR rotation: dim= %d\n",n);
  printf(" a-in:\n"); matprt(a,n,n," %8.4f");
  
/* Householder rotation of symmetric input matrix to tridiagonal form
   with transformation matrix computation */
  housev(a,d,dp,n);

  printf(" diag:\n"); matprt(d,1,n," %8.4f");
  printf("   od:\n"); matprt(dp,1,n," %8.4f");
  printf(" transform matrix:\n");
  matprt(a,n,n," %8.4f");
}
/* Test output

 HR rotation: dim= 5
 a-in:
   1.6943  -0.4050  -0.5220   0.0590   0.3536
  -0.4050   2.8423  -0.0295   0.0263   0.1459
  -0.5220  -0.0295   2.1464  -0.2846   0.2146
   0.0590   0.0263  -0.2846   1.5947  -0.0474
   0.3536   0.1459   0.2146  -0.0474   1.7222
 diag:
   1.6943   2.0402   2.3130   2.3056   1.6469
   od:
   0.7517  -0.5270  -0.3146   0.3204   0.0000
 transform matrix:
   1.0000   0.0000   0.0000   0.0000   0.0000
   0.0000  -0.5388  -0.6945   0.0784   0.4704
   0.0000   0.6470  -0.0394  -0.2396   0.7228
   0.0000  -0.5046   0.4933  -0.6590   0.2602
   0.0000  -0.1910   0.5223   0.7086   0.4342
*/
