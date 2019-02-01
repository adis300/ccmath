/*  tsany.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  sany     (Time series structure analysis.)

    Input parameter:  input_file -> name of binary input file containing
                                    time series data
                                    [ format identical to output files
                                      of garma ]

    Prompted input:  at prompt  'diff-order m_smoo lags ? '
                         enter  nd -> integer: order of time series
                                               differencing
                                m_smoo -> integer: degree of spectral
                                                   smoothing
                                lags -> integer: maximum lag used in
                                                 autocorrelation analysis
*/
#include "ccmath.h"
#include <math.h>
double *x;
int nmax;
void main(int na,char **av)
{ int j,n,nd,ms,lag; double xm;
  double *cd,*ci; FILE *fp;
  if(na!=2){ printf("para: input_file\n"); exit(-1);}
  printf("  Time Series Autocorrelation Analysis\n");
  fp=fopen(*++av,"rb");
  printf("     input file: %s\n", *av);
  fread((void *)&nmax,sizeof(int),1,fp);
  x=(double *)calloc(nmax,sizeof(*x));
  n=fread((char *)x,sizeof(double),nmax,fp);
  printf(" %d points input\n\n",n);
/* prompted input of analysis parameters */
  fprintf(stderr,"diff_ord m_smoo lags ? ");
  scanf("%d %d %d",&nd,&ms,&lag);
  cd=(double *)calloc(2*(lag+1),sizeof(*cd));
  ci=cd+lag+1;

/* autocorrelation analysis (direct and inverse) of time series */
  n=sany(x,n,&xm,cd,ci,nd,ms,lag);

/* print analysis output */
  printf(" difference order = %d\n",nd);
  printf(" series mean = %11.6f\n",xm);
  printf(" 2nd moments: d= %11.6f i= %11.6f\n",cd[0],ci[0]);
  if(nd) printf(" difference order = %d\n",nd);
  if(ms) printf(" degree of smoothing = %d\n",2*ms+1);
  printf(" autocorrelation sigma = %.3f\n",sqrt(1./n));
  printf("direct and inverse autocorrelations:\n");
  printf(" lag    ac      iac\n");
  for(j=1; j<=lag ;++j)
    printf(" %2d  %6.3f  %6.3f\n",j,cd[j],ci[j]);
}
/*  Test output

  Time Series Autocorrelation Analysis
     input file: data/ts0.b
 400 points input

 difference order = 0
 series mean =   -0.076884
 2nd moments: d=    0.004257 i=  842.337984
 degree of smoothing = 5
 autocorrelation sigma = 0.050
direct and inverse autocorrelations:
 lag    ac      iac
  1   0.406  -0.465
  2  -0.316   0.287
  3  -0.531   0.127
  4  -0.233  -0.048
  5   0.109   0.096
  6   0.250  -0.077
  7   0.141   0.065
  8   0.016  -0.037
  9  -0.083   0.034
 10  -0.107  -0.062
 11  -0.066   0.141
 12   0.032  -0.132
 13   0.011   0.085
 14  -0.007  -0.004
 15   0.016  -0.061
 16   0.042   0.045
 17   0.043  -0.069
 18  -0.003  -0.015
 19  -0.039   0.011
 20  -0.010  -0.076
*/
