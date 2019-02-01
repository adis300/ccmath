/*  tgamanc.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  qgnc  pctgn

    Input parameters:  a -> real: gamma distribution parameter
                       dst -> real: noncentrality parameter
*/
#include "ccmath.h"
#define N 11
double pct[]={.001,.01,.05,.1,.25,.5,.75,.9,.95,.99,.999};
void main(int na,char **av)
{ double a,dsq,p,z,c; int k;
  if(na!=3){ printf("para: pg dst\n"); exit(-1);}
  printf("     Test of Noncentral Gamma Distribution\n");
  a=atof(*++av); printf("  parameter a= %.3f\n",a);
  dsq=atof(*++av); printf("  noncentral dsq = %.3f\n",dsq);
  printf("    p         Z(p)           check\n");
  for(k=0; k<N ;){ p=pct[k++];

/* compute percentage point of noncentral gamma distribution */
    z=pctgn(p,a,dsq);

/* compute distribution function to check percentage point */
    c=qgnc(z,a,dsq);

    printf(" %7.3f  %12.9f  %12.9f\n",p,z,c);
   }
}
/*  Test output

     Test of Noncentral Gamma Distribution
  parameter a= 3.100
  noncentral dsq = 4.200
    p         Z(p)           check
   0.001  21.582406904   0.001000000
   0.010  17.089269887   0.010000000
   0.050  13.555017006   0.050000000
   0.100  11.852412844   0.100000000
   0.250   9.286766003   0.250000000
   0.500   6.841529037   0.500000000
   0.750   4.815335224   0.750000000
   0.900   3.340503069   0.900000000
   0.950   2.610738500   0.950000000
   0.990   1.534833738   0.990000000
   0.999   0.741684823   0.999000000
*/
