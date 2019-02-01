/*  tcarith.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  cadd  csub  cmul  cdiv

    interactive input with 'tcarith'
    input from file with 'tcarith data/carith.dat'
*/
#include "ccmath.h"
void main(int na,char **av)
{ Cpx a,b,f; FILE *fp;
  if(na>1) fp=fopen(*++av,"r");
  while(1){
    if(na==1){ printf(" a? b?\n");
      if(scanf("%lf %lf %lf %lf",&a.re,&a.im,&b.re,&b.im)==EOF) break;
     }
    else if(fscanf(fp,"%lf %lf %lf %lf",&a.re,&a.im,&b.re,&b.im) ==EOF) break;
    printf("   a=(%f, %f) b=(%f, %f)\n",a.re,a.im,b.re,b.im);
    f=cadd(a,b); printf(" a+b=(%f, %f)\n",f.re,f.im);
    f=csub(a,b); printf(" a-b=(%f, %f)\n",f.re,f.im);
    f=cmul(a,b); printf(" a*b=(%f, %f)\n",f.re,f.im);
    f=cdiv(a,b); printf(" a/b=(%f, %f)\n",f.re,f.im);
   }
}
/* Test output

   a=(1.000000, 1.000000) b=(2.000000, -0.500000)
 a+b=(3.000000, 0.500000)
 a-b=(-1.000000, 1.500000)
 a*b=(2.500000, 1.500000)
 a/b=(0.352941, 0.588235)
   a=(1.000000, 3.000000) b=(-3.000000, -1.600000)
 a+b=(-2.000000, 1.400000)
 a-b=(4.000000, 4.600000)
 a*b=(1.800000, -10.600000)
 a/b=(-0.674740, -0.640138)
   a=(0.200000, -1.000000) b=(-0.700000, 4.000000)
 a+b=(-0.500000, 3.000000)
 a-b=(0.900000, -5.000000)
 a*b=(3.860000, 1.500000)
 a/b=(-0.251061, -0.006064)
*/
