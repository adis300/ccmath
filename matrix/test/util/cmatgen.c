/*  cmatgen.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <time.h>
#include "ccmath.h"
void main(int na,char **av)
{ Cpx *a,*p; double nrml();
  int n,m,j; unsigned int seed;
  FILE *fp;
  if(na!=3){ printf("para: dim o_file\n"); exit(1);}
  n=atoi(*++av); m=n*n;
  fp=fopen(*++av,"wb");
  a=(Cpx *)calloc(m,sizeof(Cpx));
  seed=(unsigned int)time(NULL); setnrml(seed);
  for(j=0,p=a; j<m ;++j){ p->re=nrml(); (p++)->im=nrml();}
  fwrite((void *)&n,sizeof(int),1,fp);
  fwrite((void *)a,sizeof(Cpx),m,fp);
}
