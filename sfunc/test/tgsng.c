/*  tgsng.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  gsng

    Input file:  gsng.dat
*/
#include "ccmath.h"
#include <math.h>
void main(int na,char **av)
{ FILE *fp;
  double h,k,b,an,as,bs,ds;
  double rad=1.74532925199433e-2;
  if(na!=2){ printf("para: input_file\n"); exit(1);}
  fp=fopen(*++av,"r");
  printf("     Elliptic Integrals:\n");
  printf("     Test of Transform from Singular Case\n");
  while(fscanf(fp,"%lf %lf",&an,&k)!=EOF){
    printf(" input: ang= %.2f  k= %.3f\n",an,k);
    an*=rad; b=sqrt(1.-k*k);
    fscanf(fp,"%lf %lf %lf",&as,&bs,&ds);
    if(ds==0.){ bs=1.-bs*bs; ds=bs/b; bs=1./bs;}
    printf( " a= %f  b= %f  c= %f\n",as,bs,ds);

/* transform a singular elliptic integral to nonsingular form */
    h=gsng(&as,&bs,&ds,b,an);

    printf(" output: a= %f  b= %f  c= %f\n",as,bs,ds);
    printf("         integral = %12.8f\n\n",h);
   }
}
/*  Test output

     Elliptic Integrals:
     Test of Transform from Singular Case
 input: ang= 20.00  k= 0.500
 a= 1.000000  b= -0.333333  c= -3.464102
 output: a= 0.000000  b= -0.066667  c= 1.082532
         integral =   0.43184736

 input: ang= 25.00  k= 0.600
 a= 1.000000  b= 2.500000  c= -1.000000
 output: a= 1.666667  b= 1.833333  c= 1.000000
         integral =  -0.33890034

 input: ang= 30.00  k= 0.800
 a= 1.000000  b= -0.125000  c= -13.333333
 output: a= -0.000000  b= -0.076555  c= 1.548148
         integral =   0.24430963

*/
