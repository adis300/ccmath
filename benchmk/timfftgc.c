/*  timfftgc.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Time the general radix Fast Fourier Transform (FFT)

    Input parameter:  size= n : series length
*/
#include <time.h>
#include "ccmath.h"
void main(int na,char **av)
{ Cpx *f,*ft,**pc;
  int kk[20],n,i,m;
  clock_t st,en; unsigned int seed;
  if(na!=2){ printf("para: sz\n"); exit(1);}
  n=atoi(*++av);
  n=pfac(n,kk,'o');
  ft=(Cpx *)calloc(n,sizeof(*f));
  pc=(Cpx **)calloc(n,sizeof(f));
  printf(" Time General Radix FFT\n");
  seed=(unsigned int)time(0L); setnrml(seed);
  for(i=0,f=ft; i<n ;++i){
    f->re=nrml(); (f++)->im=nrml();
   }
  printf("  series length: %d\n",n);
  st=clock();
  fftgc(pc,ft,n,kk,'d');
  en=clock();
  printf(" time= %.3f sec\n",(double)(en-st)/(double)CLOCKS_PER_SEC);
}
