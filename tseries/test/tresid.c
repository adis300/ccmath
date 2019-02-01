/*  tresid.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  resid     (analysis of time series model residuals)

    Input parameter:  dfile -> name of binary file containing time
                               series model residual data
                               [created by tmest or tfmest]

    Prompted inputs:  at prompt  'lags / '
                          enter  lag -> integer: maximum lag for
                                                 autocorrelation
                                                 computation

                      at prompt  'xmin xmax bins ? '
                          enter   xmin -> minimum for residual histogram
                                  xmax -> maximum for residual histogram
                                  nb -> number of histogram bins

                      at prompt  ' Print Power Spectra ? (y/n) '
                          enter  y  to print the power spectra
                                 n  for no power spectra output
*/                        
#include "ccmath.h"
double *x; int nmax;
void main(int na,char **av)
{ int j,n,lag,nb,*ph,cks[2];
  double xa,xb,d,*pac;
  FILE *fp; char cfg[4];
  if(na!=2){ printf("para: dfile\n"); exit(-1);}
  fprintf(stderr,"lags ? "); scanf("%d",&lag);
  fprintf(stderr,"xmin xmax bins ? ");
  scanf("%lf %lf %d",&xa,&xb,&nb);

/* read residual data file */
  fp=fopen(*++av,"rb");
  printf("  input file: %s\n",*av);
  fread((void *)&nmax,sizeof(int),1,fp);
  x=(double *)calloc(nmax,sizeof(*x));
  n=fread((void *)x,sizeof(double),nmax,fp);
  printf("  series size= %d\n",n);

/* perform analysis of model residuals */
  n=resid(x,n,lag,&pac,nb,xa,xb,&ph,cks);

  printf(" second moment= %10.5f\n",pac[0]);
  printf(" lag  autocorrelation\n");
  for(j=1; j<=lag ;++j) printf(" %2d %10.6f\n",j,pac[j]);
  printf("\n series histogram\n");
  d=(xb-xa)/nb;
  for(j=0; j<nb ;++j){
    printf(" %6.2f to %6.2f  %4d\n",xa,xa+d,ph[j]);
    xa+=d;
   }
  printf("  outside bounds: %d < and %d >\n\n",ph[-1],ph[nb]);
  printf(" Kolmogorov-Smirnov Test\n");
  printf("  %d outside .25 bounds\n",cks[0]);
  printf("  %d outside .05 bounds\n\n",cks[1]);
  fprintf(stderr,"Print Power Spectra ? (y/n) ");
  scanf("%s",cfg);
  if(cfg[0]=='y'){
    printf("\n Power Spectra\n");
    for(j=0,n/=2; j<n ;++j) printf(" %3d  %9.2e\n",j,x[j]);
   }
}
/*  Test output

  input file: data/ts0.er
  series size= 400
 second moment=  368.58503
 lag  autocorrelation
  1   0.003769
  2  -0.005663
  3  -0.035316
  4   0.054365
  5  -0.045980
  6   0.049339
  7  -0.046908
  8   0.062634
  9   0.024480
 10  -0.021133
 11  -0.111454
 12   0.072015
 13  -0.062202
 14  -0.011037
 15   0.040825
 16   0.038032
 17   0.068237
 18   0.014309
 19  -0.040311
 20   0.024654

 series histogram
  -4.00 to  -3.50     1
  -3.50 to  -3.00     1
  -3.00 to  -2.50     2
  -2.50 to  -2.00     8
  -2.00 to  -1.50     8
  -1.50 to  -1.00    49
  -1.00 to  -0.50    71
  -0.50 to   0.00    70
   0.00 to   0.50    78
   0.50 to   1.00    57
   1.00 to   1.50    37
   1.50 to   2.00    13
   2.00 to   2.50     5
   2.50 to   3.00     0
   3.00 to   3.50     0
   3.50 to   4.00     0
  outside bounds: 0 < and 0 >

 Kolmogorov-Smirnov Test
  0 outside .25 bounds
  0 outside .05 bounds

*/
