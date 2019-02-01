/*  tbetanc.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  qbnc  pctbn

    Input parameters:  a -> real: first distribution parameter
                       b -> real: second distribution parameter
                       dsq -> real: noncentrality parameter
*/
#include "ccmath.h"
#define N 11
double pct[]={.001,.01,.05,.1,.25,.5,.75,.9,.95,.99,.999};
void main(int na,char **av)
{ double a,b,dsq,p,z,c; int k;
  if(na!=4){ printf("para: pa pb dst\n"); exit(-1);}
  printf("     Test of Noncentral Beta Distribution\n");
  a=atof(*++av); b=atof(*++av); dsq=atof(*++av);
  printf("  parameters: a= %.3f  b= %.3f\n",a,b);
  printf("  noncentral dsq = %.3f\n",dsq);
  printf("    p         Z(p)           check\n");
  for(k=0; k<N ;){ p=pct[k++];

/* compute percentage point of noncentral beta distribution */
    z=pctbn(p,a,b,dsq);

/* compute distribution function to check percentage point */
    c=qbnc(z,a,b,dsq);

    printf(" %7.3f  %12.9f  %12.9f\n",p,z,c);
   }
}
/*  Test output

     Test of Noncentral Beta Distribution
  parameters: a= 1.500  b= 3.200
  noncentral dsq = 2.000
    p         Z(p)           check
   0.001   0.002195404   0.001000000
   0.010   0.010349388   0.010000000
   0.050   0.031500131   0.050000000
   0.100   0.051974339   0.100000000
   0.250   0.105912383   0.250000000
   0.500   0.199723221   0.500000000
   0.750   0.328587647   0.750000000
   0.900   0.466188660   0.900000000
   0.950   0.552526011   0.950000000
   0.990   0.707419083   0.990000000
   0.999   0.846420445   0.999000000
*/
