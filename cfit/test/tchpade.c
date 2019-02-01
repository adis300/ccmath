/*  tchpade.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  chpade  ftch
    Uses:  chcof  matprt

    Alternative values for the degree of the numerator (nn) and
    denominator (nd) can be used with the call: 'tchpade nn nd'
    mc > nn+nd is required
*/
#include "ccmath.h"
#include <math.h>
#define ND 15
#define NP 30
int nn=3,nd=3;
/* increase mc if you intend to use nn+nd > 12 */
int mc=12;
char fnam[]="exp([1+x]/2)";
void main(int na,char **av)
{ double c[NP],a[ND],b[ND],fun(),y,f,er,xx,maxer;
  int j;
  if(na==3){
    nn=atoi(*++av); nd=atoi(*++av);
   }
  printf("     Test of Rational Tchebycheff Approximation\n");
  printf("          approximating %s\n\n",fnam);
  chcof(c,mc,fun);
  printf(" series coefficients:\n");
  for(j=0; j<=mc ;++j) printf(" %2d  %14.10f\n",j,c[j]);
  chpade(c,a,nn,b,nd);
  printf(" numerator coef.:\n"); matprt(a,nn,1,"  %14.10f");
  printf(" denominator coef.:\n"); matprt(b,nd,1," %14.10f");
/*
   loop for approximate evaluation of the maximum error of
   the Tchebycheff Pade' approximation
*/
  for(maxer=0.,y=-1.; y<1.01 ;y+=.05){
    er=ftch(y,a,nn,b,nd); f=fun(y); er-=f;
    if((er=fabs(er))>maxer){ maxer=er; xx=y;}
   }
  printf(" maximum error = %e at x= %f\n",maxer,xx);
}
/*
   The function used here is evaluated on the interval
   -1 <= x <= 1. Other functions defined on this
   interval may be substituted.
*/
double fun(x)
double x;
{ double y=(1.+x)/2.;
  return exp(y);
}
/* Test output

     Test of Rational Tchebycheff Approximation
          approximating exp([1+x]/2)

 series coefficients:
  0    3.5067753088
  1    0.8503916538
  2    0.1052086936
  3    0.0087221047
  4    0.0005434368
  5    0.0000271154
  6    0.0000011281
  7    0.0000000402
  8    0.0000000013
  9    0.0000000000
 10    0.0000000000
 11    0.0000000000
 12    0.0000000000
 numerator coef.:
    1.6487668676
    0.4085533815
    0.0203671089
 denominator coef.:
   1.0000000000
  -0.2475754597
   0.0123256203
 maximum error = 2.916283e-09 at x= 1.000000
*/
