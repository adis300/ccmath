/*  timeigv.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Time computation of eigenvalues and eigenvectors for a
    real symmetric matrix.

    Input file:  created by smatgen
*/
#include <time.h>
#include "ccmath.h"
void main(int na,char **av)
{ int i,n,m; FILE *fp;
  clock_t st,en;
  double dt,s,*a,*ev;
  if(na!=2){ printf("para: in_file\n"); exit(1);}
  fp=fopen(*++av,"rb");
  fread((void *)&n,sizeof(int),1,fp);
  printf(" eigenvalues & vectors: dim= %d\n",n);
  m=n*n;
  a=(double *)calloc(m,sizeof(double));
  ev=(double *)calloc(n,sizeof(double));
  fread((void *)a,sizeof(double),n*n,fp);
  st=clock();
  eigen(a,ev,n);
  en=clock();
  dt=(double)(en-st)/(double)CLOCKS_PER_SEC;
  printf(" time= %.2f sec.\n",dt);
}
