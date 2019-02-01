/*  tchouse.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  chouse

    Uses:  cmprt  matprt

    Input file:  hm4.bin
*/
#include "ccmath.h"
char fmt[]="(%7.3f,%7.3f)";
void main(int na,char **av)
{ Cpx *a; double *d,*ud; int n;
  FILE *fb;
  if(na!=2){ printf("para: input_file\n"); exit(1);}
  fb=fopen(*++av,"rb");
  fread((void *)&n,sizeof(int),1,fb);
  a=(Cpx *)calloc(n*n,sizeof(Cpx));
  d=(double *)calloc(n+n,sizeof(double)); ud=d+n;
  fread((void *)a,sizeof(Cpx),n*n,fb);
  printf(" mat a-in:\n"); cmprt(a,n,n,fmt);

/* Householder rotation to tridiagonal form */
  chouse(a,d,ud,n);

  printf(" diagonals:\n"); matprt(d,1,n," %8.4f");
  printf(" above-diag:\n"); matprt(ud,1,n," %8.4f");
  printf(" mat a-out:\n"); cmprt(a,n,n,fmt);
}
/* Test output

 mat a-in:
(  2.232, -0.000)( -0.073, -0.075)( -0.321,  0.030)(  0.379,  0.031)
( -0.073,  0.075)(  1.673,  0.000)( -0.102, -0.006)(  0.266, -0.178)
( -0.321, -0.030)( -0.102,  0.006)(  1.284,  0.000)(  0.143,  0.048)
(  0.379, -0.031)(  0.266,  0.178)(  0.143, -0.048)(  1.812,  0.000)
 diagonals:
   2.2318   1.3401   1.8998   1.5283
 above-diag:
   0.5093   0.3350   0.1322   0.0000
 mat a-out:
(  2.232, -0.000)( -0.073, -0.075)( -0.321,  0.030)(  0.379,  0.031)
( -0.073,  0.075)(  1.673,  0.000)( -0.102, -0.006)(  0.266, -0.178)
( -0.321, -0.030)( -0.102,  0.006)(  1.284,  0.000)(  0.143,  0.048)
(  0.379, -0.031)(  0.266,  0.178)(  0.143, -0.048)(  1.812,  0.000)
*/
