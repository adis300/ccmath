/*  tchpade2.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  chpade  ftch
    Uses:  chcof  matprt

    This test uses a restricted range for the argument of the
    exponential function.

    Alternative values for the degree of the numerator (nn) and
    denominator (nd) can be used with the call: 'tchpade2 nn nd'
    mc > nn+nd is required.
*/
#include "ccmath.h"
#include <math.h>
#define ND 15
#define NP 30
int nn=3,nd=3;
int mc=12;
char fnam[]="exp([1+x]/4)";
void main(int na,char **av)
{ double c[NP],a[ND],b[ND],fun(),y,f,er,xx,maxer;
  int j;
  if(na==3){
    nn=atoi(*++av); nd=atoi(*++av);
   }
  printf("     Test of Rational Tchebycheff Approximation\n");
  printf("          approximating  %s\n\n",fnam);
  chcof(c,mc,fun);
  printf(" series coefficients:\n");
  for(j=0; j<=mc ;++j) printf(" %2d  %14.10f\n",j,c[j]);
  chpade(c,a,nn,b,nd);
  printf(" numerator coef.:\n"); matprt(a,nn,1,"  %23.15f");
  printf(" denominator coef.:\n"); matprt(b,nd,1,"  %23.15f");
  for(maxer=0.,y=-1.; y<1.005 ;y+=.01){
    er=ftch(y,a,nn,b,nd); f=fun(y); er-=f;
    if((er=fabs(er))>maxer){ maxer=er; xx=y;}
   }
  printf(" maximum error = %e at x= %f\n",maxer,xx);
}
/* function evaluated on interval -1 <= x <= 1 */
double fun(x)
double x;
{ double y=(1.+x)/4.;
  return exp(y);
}
/* Test output

     Test of Rational Tchebycheff Approximation
          approximating  exp([1+x]/4)

 series coefficients:
  0    2.6083336414
  1    0.3235207557
  2    0.0201675957
  3    0.0008392246
  4    0.0000262053
  5    0.0000006548
  6    0.0000000136
  7    0.0000000002
  8    0.0000000000
  9    0.0000000000
 10    0.0000000000
 11   -0.0000000000
 12    0.0000000000
 numerator coef.:
        1.284027649433916
        0.160146208006370
        0.004000678757135
 denominator coef.:
        1.000000000000000
       -0.124694061784970
        0.003113992884993
 maximum error = 1.466643e-11 at x= 1.000000
*/
