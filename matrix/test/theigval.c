/*  theigval.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  heigval

    Uses:  cmprt  matprt

    Input file:  hm4.bin
*/
#include "ccmath.h"
char fmt[]="(%7.3f,%7.3f)";
void main(int na,char **av)
{ Cpx *a; double *ev; int n;
  FILE *fb;
  if(na!=2){ printf("para: input_file\n"); exit(1);}
  fb=fopen(*++av,"rb");
  fread((void *)&n,sizeof(int),1,fb);
  printf(" Hermitian eigenvalues: dim=%d\n",n);
  a=(Cpx *)calloc(n*n,sizeof(Cpx));
  ev=(double *)calloc(n,sizeof(double));
  fread((void *)a,sizeof(Cpx),n*n,fb);
  printf(" H-in:\n"); cmprt(a,n,n,fmt);

/* compute eigenvalues of a Hermitian matrix */
  heigval(a,ev,n);

  printf(" eigenvalues:\n");
  matprt(ev,1,n,"%8.4f");
}
/* Test output

 Hermitian eigenvalues: dim=4
 H-in:
(  2.232, -0.000)( -0.073, -0.075)( -0.321,  0.030)(  0.379,  0.031)
( -0.073,  0.075)(  1.673,  0.000)( -0.102, -0.006)(  0.266, -0.178)
( -0.321, -0.030)( -0.102,  0.006)(  1.284,  0.000)(  0.143,  0.048)
(  0.379, -0.031)(  0.266,  0.178)(  0.143, -0.048)(  1.812,  0.000)
 eigenvalues:
  2.5000  1.0000  2.0000  1.5000
*/
