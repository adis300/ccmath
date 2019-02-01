/*  theigvec.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  heigvec  hmgen

    Uses:  cmprt

    Input file:  hm4.bin
*/
#include "ccmath.h"
char fmt[]="(%7.3f,%7.3f)";
void main(int na,char **av)
{ Cpx *a,*h; double *ev; int n;
  FILE *fb;
  if(na!=2){ printf("para: input_file\n"); exit(1);}
  fb=fopen(*++av,"rb");
  fread((void *)&n,sizeof(int),1,fb);
  a=(Cpx *)calloc(2*n*n,sizeof(Cpx)); h=a+n*n;
  ev=(double *)calloc(n,sizeof(double));
  fread((void *)a,sizeof(Cpx),n*n,fb);
  printf(" mat a-in:\n"); cmprt(a,n,n,fmt);

/* compute eigenvalues and eigenvectors of a Hermitian matrix */
  heigvec(a,ev,n);

  printf(" eigenvalues:\n"); matprt(ev,1,n," %8.4f");
  printf("  evc:\n"); cmprt(a,n,n,fmt);

/* check diagonal transformation by inversion */
  hmgen(h,ev,a,n);

  printf(" evc^*a*evc:\n"); cmprt(h,n,n,fmt);
}
/* Test output

 mat a-in:
(  2.232, -0.000)( -0.073, -0.075)( -0.321,  0.030)(  0.379,  0.031)
( -0.073,  0.075)(  1.673,  0.000)( -0.102, -0.006)(  0.266, -0.178)
( -0.321, -0.030)( -0.102,  0.006)(  1.284,  0.000)(  0.143,  0.048)
(  0.379, -0.031)(  0.266,  0.178)(  0.143, -0.048)(  1.812,  0.000)
 eigenvalues:
   2.5000   1.0000   2.0000   1.5000
  evc:
(  0.854, -0.000)( -0.359, -0.000)(  0.365, -0.000)( -0.094, -0.000)
(  0.098, -0.028)( -0.315,  0.158)( -0.547,  0.387)( -0.031,  0.644)
( -0.177, -0.001)( -0.743, -0.030)( -0.203, -0.131)(  0.442, -0.402)
(  0.478, -0.012)(  0.438, -0.035)( -0.594, -0.080)(  0.367, -0.289)
 evc^*a*evc:
(  2.232,  0.000)( -0.073, -0.075)( -0.321,  0.030)(  0.379,  0.031)
( -0.073,  0.075)(  1.673,  0.000)( -0.102, -0.006)(  0.266, -0.178)
( -0.321, -0.030)( -0.102,  0.006)(  1.284,  0.000)(  0.143,  0.048)
(  0.379, -0.031)(  0.266,  0.178)(  0.143, -0.048)(  1.812, -0.000)
*/
