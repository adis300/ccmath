/*  tdrfmod.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  drfmod  setdrf

    Uses:  sarma  setsim  sintg  sdiff  nrml setnrml bran setbran 

    Input parameters:  n -> integer: length of test series

                       model_file -> name of factor model specification
                                     file  [ tfs?.dat ]
*/
#include "ccmath.h"
struct mcof *pfc,*par,*pma;
int nfc,nar,nma,np,ndif;
void main(int na,char **av)
{ struct mcof *pa; int n,i,j; unsigned int seed;
  double e,ep,*dr;
  FILE *fp; struct fmod y;
  if(na!=3){ printf("para: n model_file\n"); exit(-1);}
  printf("Test of Factor Model Derivative Computation\n\n");
  n=atoi(*++av);
  fp=fopen(*++av,"r");
  printf(" model file: %s\n",*av);

/* define model parameters */
  fscanf(fp,"%d %d %d %d",&nfc,&nar,&nma,&ndif); np=nfc+nma+nar;  
  pfc=(struct mcof *)calloc(np,sizeof(*pa));
  dr=(double *)calloc(np,sizeof(*dr));
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

/* initialize simulation */
  setnrml(seed); setbran(seed);
  printf("  random seed= %u\n",seed);
  printf("     y         e         ep\n");
  setdrf(1); setsim(1);

/* generate series and print output */
  for(j=0; j<n ;j++){
      y.fac=bran(nfc); y.val=sarma(e=nrml());
      if(ndif) y.val=sintg(y.val,ndif,j);
      y.val+=(pfc+y.fac)->cf;
      printf("%8.4f  %8.4f  ",y.val,e);
      if(ndif) y.val=sdiff(y.val,ndif,j);

/* compute factor model residuals and their derivatives */
      ep=drfmod(y,dr);

      printf("%8.4f\n",ep);
      printf("       deriv: ");
      for(i=0; i<np ;++i) printf("%6.3f ",dr[i]);
      printf("\n");
   }
}
/*  Test output

Test of Factor Model Derivative Computation

 model file: data/tfs2.dat
Model Definition
factor parameters
0.000000
-1.000000
autoregressive parameters and lags
moving average paramerers and lags
-0.700000  1
difference order = 1
  random seed= 132465798
     y         e         ep
 -1.8890   -0.8890   -0.8890
       deriv:  0.000  1.000  0.000 
 -2.3809    1.1303   -0.3777
       deriv:  0.000 -0.700  0.889 
 -0.6837    0.9060   -0.7356
       deriv:  1.000 -0.510 -0.245 
 -1.0584   -0.0090    0.5149
       deriv: -1.700  1.357  0.907 
 -1.4612    0.6035   -1.3604
       deriv:  1.190 -0.950 -1.150 
 -1.5696   -0.5308   -0.0477
       deriv:  0.167 -0.335  2.165 
 -1.6255    0.3156    0.0334
       deriv: -0.117  0.235 -1.468 
 -0.5022    0.9023   -0.0234
       deriv:  0.082 -0.164  0.994 
 -0.3592   -0.4886    0.0164
       deriv: -0.057  0.115 -0.673 
 -1.1431   -0.4418   -0.0115
       deriv:  0.040 -0.080  0.454 
 -1.4178    0.0345    0.0080
       deriv: -0.028  0.056 -0.307 
  0.4010    1.7947   -0.0056
       deriv:  0.020 -0.039  0.207 
  2.1084    0.4512    0.0039
       deriv: -0.014  0.028 -0.139 
  3.2986    0.8743   -0.0027
       deriv:  0.010 -0.019  0.093 
  2.3997   -0.5108    0.0019
       deriv: -1.007  1.014 -0.063 
 -1.1289   -2.1711   -1.0013
       deriv:  0.705 -0.709  0.042 
 -5.2988   -1.6501   -0.2991
       deriv: -0.493  0.497  0.972 
 -5.1302    1.3236   -0.7907
       deriv:  1.345 -1.348 -0.381 
 -3.5201    1.6836    0.5535
       deriv: -1.942  1.943  1.058 
 -2.1725    0.1690   -1.3874
       deriv:  2.359 -2.360 -1.294 
*/
