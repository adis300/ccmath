/*  tsmoo.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  smoo

    input file: smoo.dat
*/
#include "ccmath.h"
#define MM 100
double x[MM],y[MM];
void main(int na,char **av)
{ int j,m,n; FILE *fp;
  if(na!=3){ printf("para: degree dfile\n"); exit(1);}
  m=atoi(*++av); fp=fopen(*++av,"r");
  printf("     Test of Spectra Smoother\n");
  for(j=0; fscanf(fp,"%lf",x+j)!=EOF ;++j) y[j]=x[j];
  n=j;
  smoo(y,n,m);
  printf(" degree of smoothing = %d\n",2*m+1);
  printf("    input   smoothed\n");
  for(j=0; j<n ;++j) printf("%3d %6.2f %6.2f\n",j,x[j],y[j]);
}
/* Test output

     Test of Spectra Smoother
 degree of smoothing = 5
    input   smoothed
  0   8.00   4.00
  1   3.00   3.40
  2   5.00   3.00
  3   2.00   3.00
  4   1.00   2.90
  5   4.00   2.70
  6   3.00   2.50
  7   4.00   2.70
  8   1.00   2.90
  9   2.00   3.00
 10   5.00   3.00
 11   3.00   3.40
*/
