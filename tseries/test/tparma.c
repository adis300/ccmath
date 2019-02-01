/*  tparma.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  parma

    Uses:  sarma  setsim  nrml  setnrml

    Input parameter:  model_file -> name of file specifying an ARMA
                                    time series model [ ts?.dat ]
*/
#include "ccmath.h"
struct mcof *par,*pma; int nar,nma,np;
double x[50],e[50];
void main(int na,char **av)
{ struct mcof *pa; int n,i,j,j1;
  double y; unsigned int seed;
  FILE *fp;
  if(na!=2){ printf("para: model_file\n"); exit(-1);}
  printf("     Test of Time Series Prediction\n\n");
  fp=fopen(*++av,"r");
  printf("  model file: %s\n",*av);

/* load and print model data */
  fscanf(fp,"%d %d",&nar,&nma); np=nar+nma;
  par=(struct mcof *)calloc(np,sizeof(*pa));
  pma=par+nar;
  printf(" model inputs:\n");
  for(j=0,pa=par; j<np ;++j,++pa){
    fscanf(fp,"%lf %d",&(pa->cf),&(pa->lag));
    printf(" %6.3f  %2d  ",pa->cf,pa->lag);
    if(j<nar) printf("ar\n"); else printf("ma\n");
    pa->lag-=1;
   }

/* initialize series simulation */
  fscanf(fp,"%u",&seed);
  setnrml(seed);
  printf("  random seed= %u\n",seed);
  setsim(1); n=45;
  printf("    x          e           p1");
  printf("          p2          p3\n");

/* generate series */
  for(j=0; j<n ;++j){
    x[j]=sarma(e[j]=nrml());
    if(j>=25){
      printf(" %10.6f  %10.6f",x[j],e[j]);
      for(i=1,j1=j+i; i<4 ;++i){

/* compute one step predictions of the series */
        y=parma(x+j1,e+j1); ++j1;

        printf("  %10.6f",y);
       }
      printf("\n");
     }
   }
}
/*  Test output

     Test of Time Series Prediction

  model file: data/ts2.dat
 model inputs:
  0.800   1  ar
  0.400   1  ma
  random seed= 2137714571
    x          e           p1          p2          p3
  -0.175885   -0.140701   -0.084428   -0.067542   -0.054034
   0.797082    0.881509    0.285062    0.228049    0.182439
  -0.930649   -1.215710   -0.258235   -0.206588   -0.165270
   1.001739    1.259974    0.297402    0.237922    0.190337
   0.769070    0.471668    0.426589    0.341271    0.273017
  -0.003327   -0.429916    0.169305    0.135444    0.108355
  -0.833684   -1.002989   -0.265752   -0.212601   -0.170081
  -1.325153   -1.059402   -0.636362   -0.509090   -0.407272
  -0.377461    0.258901   -0.405529   -0.324423   -0.259539
   0.495890    0.901419    0.036144    0.028915    0.023132
  -1.701646   -1.737790   -0.666201   -0.532961   -0.426369
  -0.497855    0.168346   -0.465622   -0.372498   -0.297998
   0.780821    1.246443    0.126079    0.100863    0.080691
   0.034823   -0.091256    0.064361    0.051489    0.041191
  -0.284627   -0.348988   -0.088106   -0.070485   -0.056388
  -0.486986   -0.398880   -0.230037   -0.184030   -0.147224
  -0.563082   -0.333045   -0.317247   -0.253798   -0.203038
  -0.658024   -0.340776   -0.390108   -0.312087   -0.249669
  -0.229034    0.161074   -0.247657   -0.198126   -0.158500
  -3.308820   -3.061163   -1.422591   -1.138073   -0.910458
*/
