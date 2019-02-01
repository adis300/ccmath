/*  tevmod.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  evmod  setev

    Uses:  sarma  setsim  nrml  setnrml

    Input parameters:  n -> integer: length of timseries

                       model_file -> name of ARMA model specification
                                     file [ ts?.dat ]
*/
#include "ccmath.h"
struct mcof *par,*pma; int nar,nma,np;
void main(int na,char **av)
{ struct mcof *pa; int n,j; unsigned int seed;
  double y,e;
  FILE *fp;
  if(na!=3){ printf("para: n model_file\n"); exit(-1);}
  printf("     Test of Time Series Residual Computation\n\n");
  n=atoi(*++av);
  fp=fopen(*++av,"r");
  printf("  model file: %s\n",*av);

/* load and print model parameters */
  fscanf(fp,"%d %d",&nar,&nma); np=nar+nma;
  par=(struct mcof *)calloc(np,sizeof(*pa));
  pma=par+nar;
  printf(" model inputs:\n");
  for(j=0,pa=par; j<np ;++j,++pa){
    fscanf(fp,"%lf %d",&(pa->cf),&(pa->lag));
    printf("%6.3f  %2d  ",pa->cf,pa->lag);
    if(j<nar) printf("ar\n"); else printf("ma\n");
    pa->lag-=1;
   }
  fscanf(fp,"%u",&seed);

/* initialize model simulation */
  setnrml(seed);
  printf("  random seed= %u\n",seed);
  setev(1); setsim(1);

/* generate series */
  printf("     y         e         ep\n");
  for(j=0; j<n ;++j){
    y=sarma(e=nrml());
    printf(" %8.4f  %8.4f  ",y,e);

/* compute ARMA model residuals */
    y=evmod(y);

    printf("%8.4f\n",y);
   }
}
/*  Test output

     Test of Time Series Residual Computation

  model file: data/ts2.dat
 model inputs:
 0.800   1  ar
 0.400   1  ma
  random seed= 2137714571
     y         e         ep
  -1.3795   -1.3795   -1.3795
  -1.9678   -1.4160   -1.4160
  -2.7393   -1.7314   -1.7314
  -1.1999    0.2990    0.2990
  -2.5110   -1.4316   -1.4316
  -1.9082   -0.4720   -0.4720
  -1.0084    0.3294    0.3294
  -0.2676    0.6709    0.6709
   0.3515    0.8339    0.8339
   1.9068    1.9592    1.9592
   0.0151   -0.7267   -0.7267
   0.7699    0.4671    0.4671
  -2.2702   -2.6993   -2.6993
  -0.6142    0.1223    0.1223
   1.1693    1.7096    1.7096
   0.9281    0.6764    0.6764
  -1.1574   -1.6293   -1.6293
   0.5183    0.7925    0.7925
  -1.2670   -1.3647   -1.3647
  -1.2587   -0.7909   -0.7909
  -0.2033    0.4873    0.4873
   0.2061    0.5636    0.5636
   0.8626    0.9232    0.9232
   0.4389    0.1181    0.1181
  -0.3919   -0.6958   -0.6958
  -0.1759   -0.1407   -0.1407
   0.7971    0.8815    0.8815
  -0.9306   -1.2157   -1.2157
   1.0017    1.2600    1.2600
   0.7691    0.4717    0.4717
*/
