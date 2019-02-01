/*  tevfmod.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  evfmod  setevf

    Uses:  sarma  setsim  sintg  sdiff  nrml setnrml  bran setbran

    Input parameters:  n -> integer: length of generated series

                       model_file -> name of factor model specification
                                     file [ tsf?.dat ]
*/
#include "ccmath.h"
struct mcof *pfc,*pma,*par;
int nfc,nma,nar,np,ndif;
void main(int na,char **av)
{ struct mcof *pa; int n,i,j; unsigned int seed;
  double ep,e;
  FILE *fp; struct fmod y;
  if(na!=3){ printf("para: n model_file\n"); exit(-1);}
  printf("Test of Factor Model Residual Computation\n\n");
  n=atoi(*++av);
  fp=fopen(*++av,"r");
  printf("  model file: %s\n",*av);

/* load and print model parameters */
  fscanf(fp,"%d %d %d %d",&nfc,&nar,&nma,&ndif);
  np=nfc+nma+nar;  
  pfc=(struct mcof *)calloc(np,sizeof(*pa));
  par=pfc+nfc; pma=par+nar;
  for(j=0,pa=pfc; j<np ;j++,++pa){
     fscanf(fp,"%lf %d",&(pa->cf),&(pa->lag));
     pa->lag-=1;
   }
  fscanf(fp,"%u",&seed);
  printf("Model Definition\n");
  printf("factor parameters\n");
  for(j=0,pa=pfc; j<nfc ;j++,pa++)
      printf("%f\n",pa->cf);
  printf("autoregressive parameters and lags\n");
  for(j=0,pa=par; j<nar ;j++,pa++)
      printf("%f  %d\n",pa->cf,pa->lag+1);
  printf("moving average paramerers and lags\n");
  for(j=0,pa=pma; j<nma ;j++,pa++)
      printf("%f  %d\n",pa->cf,pa->lag+1);
  printf("difference order = %d\n",ndif);

/* initialize model simulation */
  setnrml(seed); setbran(seed);
  printf("  random seed= %u\n",seed);
  printf("\n    y        e          ep\n");
  setevf(1); setsim(1);

/* generate series */
  for(j=0; j<n ;j++){
      y.fac=bran(nfc); y.val=sarma(e=nrml());
      if(ndif) y.val=sintg(y.val,ndif,j);
      y.val+=(pfc+y.fac)->cf;
      printf("%8.4f %8.4f",y.val,e);
      if(ndif) y.val=sdiff(y.val,ndif,j);

/* compute factor model residual */
      ep=evfmod(y);

      printf("   %8.4f\n",ep);
   }
}
/*  Test output

Test of Factor Model Residual Computation

  model file: data/tfs0.dat
Model Definition
factor parameters
0.000000
1.000000
autoregressive parameters and lags
0.800000  1
-0.400000  2
moving average paramerers and lags
-0.500000  1
difference order = 0
  random seed= 123456789

    y        e          ep
  0.4557   0.4557     0.4557
  0.1390  -0.4533    -0.4533
  1.3600   1.6577     1.6577
  2.1398  -0.7214    -0.7214
 -0.7648  -0.7719    -0.7719
 -0.6631  -0.2094    -0.2094
 -1.2447  -1.1154    -1.1154
 -1.2243  -0.5361    -0.5361
 -0.0809   0.0687     0.0687
  1.3078   1.2485     1.2485
  1.8571  -0.2458    -0.2458
  0.9831   0.1434     0.1434
 -0.9531  -1.0685    -1.0685
 -1.1122   0.5778     0.5778
  1.1801   0.3996     0.3996
  0.7392  -0.0495    -0.0495
  2.8812   1.3866     1.3866
  3.1287   0.2262     0.2262
  1.2667  -0.7969    -0.7969
 -0.3193   0.7173     0.7173
  1.8082   1.8117     1.8117
  2.9950  -0.4851    -0.4851
  1.6924   0.0622     0.0622
  0.8790   1.0920     1.0920
  0.4248  -1.5475    -1.5475
 -1.2122  -0.6268    -0.6268
 -3.2803  -1.4272    -1.4272
 -1.4864   0.9666     0.9666
  1.4548  -0.1515    -0.1515
  2.1863   1.3036     1.3036
*/
