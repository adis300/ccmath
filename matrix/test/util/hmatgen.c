/*  hmatgen.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <time.h>
#include "ccmath.h"
void main(int na,char **av)
{ Cpx *h,*u; FILE *fp;
  int i,n,m; unsigned int seed; double *e,s;
  if(na!=3){ printf("para: size o_file\n"); exit(1);}
  n=atoi(*++av); m=n*n;
  fp=fopen(*++av,"wb");
  fwrite((void *)&n,sizeof(int),1,fp);
  h=(Cpx *)calloc(2*m,sizeof(Cpx)); u=h+m;
  e=(double *)calloc(n,sizeof(double));
  for(i=0,s=1.; i<n ;++i,s+=.5) e[i]=s;
  seed=(unsigned int)time(NULL); setunfl(seed);
  unitary(u,n);
  hmgen(h,e,u,n);
  fwrite((void *)h,sizeof(Cpx),m,fp);
}
