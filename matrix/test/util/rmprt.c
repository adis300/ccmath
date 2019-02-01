/*  rmprt.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "ccmath.h"
char fmt[]=" %7.3f";
void main(int na,char **av)
{ double *a; int n;
  FILE *fb;
  if(na!=2){ printf("para: input_file\n"); exit(1);}
  fb=fopen(*++av,"rb");
  fread((void *)&n,sizeof(int),1,fb);
  a=(double *)calloc(n*n,sizeof(double));
  fread((void *)a,sizeof(double),n*n,fb);
  printf(" %d\n",n);
  matprt(a,n,n,fmt);
}
