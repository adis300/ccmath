/*  smatgen.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Create a real symmetric matrix with specified eigenvalues

    Input parameters:  dim = n -> n by n matrix generated
                       o_file  -> name of binary output file
*/
#include "ccmath.h"
void main(int na,char **av)
{ int n,m; unsigned int seed;
  double *a,*ev,*evc,s; FILE *fq;
  if(na!=3){ printf("para: dim o_file\n"); exit(1);}
  n=atoi(*++av); m=n*n;
  fq=fopen(*++av,"wb");
  evc=(double *)calloc(2*m+n,sizeof(*a));
  a=evc+m; ev=a+m;
  for(m=0,s=1.; m<n ;++m){ ev[m]=s; s+=0.5;}
  seed=(unsigned int)time(NULL); setunfl(seed);
  ortho(evc,n);
  smgen(a,ev,evc,n);
  fwrite((void *)&n,sizeof(int),1,fq);
  fwrite((void *)a,sizeof(double),n*n,fq);
}
