/*  tsarma.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  sarma  setsim

    Uses:  nrml  setnrml

    Input parameters:  n -> integer: length of series

                       model_file -> name of ARMA model specification
                                     file [ ts?.dat ]
*/
#include "ccmath.h"
struct mcof *par,*pma; int nar,nma,np;
void main(int na,char **av)
{ struct mcof *pa; int n,i,j;
  double y,e; unsigned int seed;
  FILE *fp;
  if(na!=3){ printf("para: n model_file\n"); exit(-1);}
  printf("     Test of Time Series Simulation Generator\n");
  n=atoi(*++av);
  fp=fopen(*++av,"r");
  printf("  model file: %s\n",*av);

/* load and print model data */
  fscanf(fp,"%d %d",&nar,&nma); np=nar+nma;
  par=(struct mcof *)calloc(np,sizeof(*pa));
  pma=par+nar;
  printf(" inputs:\n");
  for(j=0,pa=par; j<np ;++j,++pa){
    fscanf(fp,"%lf %d",&(pa->cf),&(pa->lag));
    printf(" %6.3f  %2d  ",pa->cf,pa->lag);
    if(j<nar) printf("ar\n"); else printf("ma\n");
    pa->lag-=1;
   }

/* initialize model generator */
  fscanf(fp,"%u",&seed);
  setnrml(seed);
  printf("  random seed= %u\n",seed);
  setsim(1);

/* generate ARMA series values */
  printf("     y         e\n");
  for(j=0; j<n ;++j){
    y=sarma(e=nrml());
    printf(" %8.4f  %8.4f\n",y,e);
   }
}
/*  Test output

     Test of Time Series Simulation Generator
  model file: data/ts2.dat
 inputs:
  0.800   1  ar
  0.400   1  ma
  random seed= 2137714571
     y         e
  -1.3795   -1.3795
  -1.9678   -1.4160
  -2.7393   -1.7314
  -1.1999    0.2990
  -2.5110   -1.4316
  -1.9082   -0.4720
  -1.0084    0.3294
  -0.2676    0.6709
   0.3515    0.8339
   1.9068    1.9592
   0.0151   -0.7267
   0.7699    0.4671
  -2.2702   -2.6993
  -0.6142    0.1223
   1.1693    1.7096
   0.9281    0.6764
  -1.1574   -1.6293
   0.5183    0.7925
  -1.2670   -1.3647
  -1.2587   -0.7909
*/
