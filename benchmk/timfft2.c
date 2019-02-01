/*  timfft2.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Time a radix-two Fast Fourier transform.

    Input parameter:  n -> length of series = 2^n  (n < 20)
*/
#include <time.h>
#include "ccmath.h"
void main(int na,char **av)
{ Cpx *f,*ft;
  int n,i,m;
  clock_t st,en; unsigned int seed;
  if(na!=2){ printf("para: log2(sz)\n"); exit(1);}
  printf(" Time Radix-2 FFT\n");
  m=atoi(*++av); n=1<<m;
  printf("  series length: %d\n",n);
  ft=(Cpx *)calloc(n,sizeof(*f));
  seed=(unsigned int)time(NULL); setnrml(seed);
  for(i=0,f=ft; i<n ;++i){
    f->re=nrml(); (f++)->im=nrml();
   }
  st=clock();
  fft2(ft,m,'i');
  en=clock();
  printf(" time= %.3f sec\n",(double)(en-st)/(double)CLOCKS_PER_SEC);
}
