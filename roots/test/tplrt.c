/*  tplrt.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  plrt  polyc

    To use an input data file call 'tplrt file'.
    Input data files pol1.dat and pol2.dat
*/
#include "ccmath.h"
#include <math.h>
#define NN 10
/* complex structure is defined by */
/* struct complex {double re,im;}; */
int n=7;
double cof[]={ 10., -4., 7., 8., -3., 7., -2., 1.};
void main(int na,char **av)
{ struct complex py,root[NN];
  double ra,rb,s; int i,ns;
  FILE *fp;
  if(na==2){
    fp=fopen(*++av,"r");
    for(n=0; fscanf(fp,"%lf",cof+n)!=EOF ;++n);
   }
  printf("     Test of Polynomial Root Program\n");
  printf(" polynomial degree = %d\n",n);
  printf("  coefficients:\n");
  for(i=n; i>=0 ;) printf("    %8.4f\n",cof[i--]);
  ra=1.; rb=2.;
  ns=plrt(cof,n,root,ra,rb);
  printf("  return status = %d\n",ns);
  printf("    roots and residuals\n");
  for(i=0; i<n ;++i){ py=polyc(root[i],cof,n);
    s=sqrt(py.re*py.re+py.im*py.im);
    printf(" %d  %10.6f  %10.6f    %9.3e\n",i,root[i].re,root[i].im,s);
   }
}
/* Test output

     Test of Polynomial Root Program
 polynomial degree = 7
  coefficients:
      1.0000
     -2.0000
      7.0000
     -3.0000
      8.0000
      7.0000
     -4.0000
     10.0000
  return status = 0
    roots and residuals
 0   -1.000000    0.000000    0.000e+00
 1    0.000000   -1.414214    5.447e-15
 2    0.000000    1.414214    5.447e-15
 3    0.500000   -0.866025    2.031e-15
 4    0.500000    0.866025    2.031e-15
 5    1.000000   -2.000000    0.000e+00
 6    1.000000    2.000000    0.000e+00
*/
