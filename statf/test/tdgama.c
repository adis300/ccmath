/*  tdgama.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  qgama  pctg

    Input parameter:  a -> real: distribution parameter
*/
#include "ccmath.h"
#define N 11
double pct[]={.001,.01,.05,.1,.25,.5,.75,.9,.95,.99,.999};
void main(int na,char **av)
{ double a,p,z,c; int k;
  if(na!=2){ printf("para: pg\n"); exit(-1);}
  printf("     Test of Gamma Distribution\n");
  a=atof(*++av); printf("  parameter = %.3f\n",a);
  printf("    p         Z(p)           check\n");
  for(k=0; k<N ;){ p=pct[k++];

/* compute percentage point of gamma distribution */
    z=pctg(p,a);

/* compute distribution function to check percentage point */
    c=qgama(z,a);

    printf(" %7.3f  %12.9f  %12.9f\n",p,z,c);
   }
}
/*  Test output

     Test of Gamma Distribution
  parameter = 4.330
    p         Z(p)           check
   0.001  13.643140516   0.001000000
   0.010  10.567087335   0.010000000
   0.050   8.220937190   0.050000000
   0.100   7.118199152   0.100000000
   0.250   5.496086650   0.250000000
   0.500   4.001617542   0.500000000
   0.750   2.808001804   0.750000000
   0.900   1.967598809   0.900000000
   0.950   1.560462720   0.950000000
   0.990   0.967176847   0.990000000
   0.999   0.523958550   0.999000000
*/
