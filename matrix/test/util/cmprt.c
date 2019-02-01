/*  cmprt.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "ccmath.h"
char fmt[]="(%7.3f,%7.3f)";
void main(int na,char **av)
{ Cpx *a; int n;
  FILE *fb;
  if(na!=2){ printf("para: input_file\n"); exit(1);}
  fb=fopen(*++av,"rb");
  fread((void *)&n,sizeof(int),1,fb);
  a=(Cpx *)calloc(n*n,sizeof(Cpx));
  fread((void *)a,sizeof(Cpx),n*n,fb);
  printf(" %d\n",n);
  cmprt(a,n,n,fmt);
}
