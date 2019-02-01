/*  tcsqrt.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  csqrt
    Uses:  cmul

    interactive input with 'tcsqrt'
    input from file with 'tcsqrt data/csqrt.dat'
*/
#include "ccmath.h"
void main(int na,char **av)
{ Cpx z,f; FILE *fp;
  if(na>1) fp=fopen(*++av,"r");
  while(1){
    if(na==1){
      printf(" z? ");     /* enter Ctrl-Z to terminate input */    
      if(scanf("%lf %lf",&z.re,&z.im)==EOF) break;
     }
    else{ if(fscanf(fp,"%lf %lf",&z.re,&z.im)==EOF) break;
      printf(" z=(%f, %f)\n",z.re,z.im);
     }
    f=csqrt(z);
    printf("  sqrt=(%f, %f)\n",f.re,f.im);
    f=cmul(f,f);
    printf(" check=(%f, %f)\n",f.re,f.im);
   }
}
/* Test output

 z=(1.000000, 1.000000)
  sqrt=(1.098684, 0.455090)
 check=(1.000000, 1.000000)
 z=(-1.000000, 0.500000)
  sqrt=(0.242934, 1.029086)
 check=(-1.000000, 0.500000)
 z=(-1.000000, -0.500000)
  sqrt=(0.242934, -1.029086)
 check=(-1.000000, -0.500000)
 z=(2.000000, -1.000000)
  sqrt=(1.455347, -0.343561)
 check=(2.000000, -1.000000)
*/
