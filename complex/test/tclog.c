/*  tclog.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  clog  cexp

    input from file with 'tclog  data/clog.dat'
*/
#include "ccmath.h"
void main(int na,char **av)
{ Cpx z,f; FILE *fp;
  if(na>1) fp=fopen(*++av,"r");
  while(1){
    if(na==1){ printf(" z? ");     /* terminate input with Ctrl-Z */    
      if(scanf("%lf %lf",&z.re,&z.im)==EOF) break;
     }
    else{ if(fscanf(fp,"%lf %lf",&z.re,&z.im)==EOF) break;
      printf(" z= (%f, %f)\n",z.re,z.im);
     }
    f=cexp(z); z=clog(f);
    printf("      exp= (%f, %f)\n",f.re,f.im);
    printf("      log= (%f, %f)\n",z.re,z.im);
    f=cexp(z);
    printf(" exp(log)= (%f, %f)\n",f.re,f.im);
   }
}
/* Test output

 z= (1.000000, 2.000000)
      exp= (-1.131204, 2.471727)
      log= (1.000000, 2.000000)
 exp(log)= (-1.131204, 2.471727)
 z= (1.000000, -0.500000)
      exp= (2.385517, -1.303214)
      log= (1.000000, -0.500000)
 exp(log)= (2.385517, -1.303214)
 z= (0.500000, 4.000000)
      exp= (-1.077676, -1.247756)
      log= (0.500000, -2.283185)
 exp(log)= (-1.077676, -1.247756)
 z= (-1.200000, 3.000000)
      exp= (-0.298180, 0.042505)
      log= (-1.200000, 3.000000)
 exp(log)= (-0.298180, 0.042505)
*/
