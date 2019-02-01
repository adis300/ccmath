/*  tchypb.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  csinh  casinh
           ccosh  cacosh
	       ctanh  catanh

    interactive input with 'tchypb'
    input from file with 'tchypb data/chypb.dat'
*/
#include "ccmath.h"
void main(int na,char **av)
{ Cpx z,f,u; FILE *fp;
  if(na>1) fp=fopen(*++av,"r");
  while(1){
    if(na==1){ printf("z ? ");     /* enter Ctrl-Z to terminate */    
      if(scanf("%lf %lf",&z.re,&z.im)==EOF) break;
     }
    else{
      if(fscanf(fp,"%lf %lf",&z.re,&z.im)==EOF) break;
      printf(" z=(%f, %f)\n",z.re,z.im);
     }
    f=csinh(z); u=casinh(f);
    printf(" sinh = (%f, %f)\n",f.re,f.im);
    printf(" asinh= (%f, %f)\n",u.re,u.im);
    f=ccosh(z); u=cacosh(f);
    printf(" cosh = (%f, %f)\n",f.re,f.im);
    printf(" acosh= (%f, %f)\n",u.re,u.im);
    f=ctanh(z); u=catanh(f);
    printf(" tanh = (%f, %f)\n",f.re,f.im);
    printf(" atanh= (%f, %f)\n",u.re,u.im);
   }
}
/* Test output

 z=(1.000000, 1.000000)
 sinh = (0.634964, 1.298458)
 asinh= (1.000000, 1.000000)
 cosh = (0.833730, 0.988898)
 acosh= (1.000000, 1.000000)
 tanh = (1.083923, 0.271753)
 atanh= (1.000000, 1.000000)
 z=(-0.800000, 0.750000)
 sinh = (-0.649817, 0.911647)
 asinh= (-0.800000, 0.750000)
 cosh = (0.978586, -0.605367)
 acosh= (0.800000, -0.750000)
 tanh = (-0.897049, 0.376669)
 atanh= (-0.800000, 0.750000)
 z=(-0.300000, -1.200000)
 sinh = (-0.110345, -0.974296)
 asinh= (-0.300000, -1.200000)
 cosh = (0.378787, 0.283825)
 acosh= (0.300000, 1.200000)
 tanh = (-1.420875, -1.507490)
 atanh= (-0.300000, -1.200000)
 z=(1.500000, -0.600000)
 sinh = (1.757370, -1.328270)
 asinh= (1.500000, -0.600000)
 cosh = (1.941527, -1.202282)
 acosh= (1.500000, -0.600000)
 tanh = (0.960485, -0.089361)
 atanh= (1.500000, -0.600000)
*/
