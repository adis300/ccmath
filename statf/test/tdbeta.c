/*  tdbeta.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  qbeta  pctb

    Input parameters:  a -> real: first distribution parameter
                       b -> real: second distribution parameter
*/
#include "ccmath.h"
#define N 11
double pct[]={.001,.01,.05,.1,.25,.5,.75,.9,.95,.99,.999};
void main(int na,char **av)
{ double a,b,p,z,c; int k;
  if(na!=3){ printf("para: pa pb\n"); exit(-1);}
  printf("     Test of Beta Distribution\n");
  a=atof(*++av); b=atof(*++av);
  printf("  parameters: a= %.3f  b= %.3f\n",a,b);
  printf("    p         Z(p)           check\n");
  for(k=0; k<N ;){ p=pct[k++];

/* compute percentage point of beta distribution */
    z=pctb(p,a,b);

/* compute distribution function to check percentage point */
    c=qbeta(z,a,b);

    printf(" %7.3f  %12.9f  %12.9f\n",p,z,c);
   }
}
/*  Test output

     Test of Beta Distribution
  parameters: a= 1.200  b= 5.700
    p         Z(p)           check
   0.001   0.000592167   0.001000000
   0.010   0.004064426   0.010000000
   0.050   0.015940213   0.050000000
   0.100   0.029219640   0.100000000
   0.250   0.068136143   0.250000000
   0.500   0.142049914   0.500000000
   0.750   0.248855357   0.750000000
   0.900   0.366166339   0.900000000
   0.950   0.441384054   0.950000000
   0.990   0.581886023   0.990000000
   0.999   0.722519029   0.999000000
*/
