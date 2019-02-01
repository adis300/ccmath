/*  tdrmod.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  drmod  setdr

    Uses:  sarma  setsim  nrml  setnrml

    Input parameters:  n -> integer: size of time series

                       model_file -> name of ARMA model specification
                                     file [ ts?.dat ]
*/
#include "ccmath.h"
struct mcof *par,*pma; int nar,nma,np;
void main(int na,char **av)
{ struct mcof *pa; int n,i,j; unsigned int seed;
  double y,*dr,e;
  FILE *fp;
  if(na!=3){ printf("para: n model_file\n"); exit(1);}
  printf("     Test of Time Series Derivative Computation\n\n");
  n=atoi(*++av);
  fp=fopen(*++av,"r");
  printf("  model file: %s\n",*av);

/* load and print model parameters */
  fscanf(fp,"%d %d",&nar,&nma); np=nar+nma;
  par=(struct mcof *)calloc(np,sizeof(*pa));
  dr=(double *)calloc(np,sizeof(*dr));
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
  setdr(1); setsim(1);

/* simulate series */
  printf("     y         e         ep          derivatives\n");
  for(j=0; j<n ;++j){
    y=sarma(e=nrml());
    printf(" %8.4f  %8.4f  ",y,e);

/* compute ARMA model residual and its derivatives */
    y=drmod(y,dr);

    printf("%8.4f  ",y);
    for(i=0; i<np ;) printf("%6.3f ",dr[i++]); printf("\n");
   }
}
/*  Test output

     Test of Time Series Derivative Computation

  model file: data/ts1.dat
 model inputs:
  0.600   1  ar
 -0.200   2  ar
 -0.500   1  ma
  random seed= 123456789
     y         e         ep          derivatives
   0.4557    0.4557    0.4557   0.000  0.000  0.000 
   0.0479   -0.4533   -0.4533   0.456  0.000 -0.456 
   1.3686    1.6577    1.6577  -0.180  0.456  0.681 
   0.9190   -0.7214   -0.7214   1.459 -0.180 -1.998 
  -0.8549   -0.7719   -0.7719   0.190  1.459  1.721 
  -1.2921   -0.2094   -0.2094  -0.950  0.190 -0.088 
  -1.8244   -1.1154   -1.1154  -0.817 -0.950  0.254 
  -1.9300   -0.5361   -0.5361  -1.416 -0.817  0.989 
  -0.9925    0.0687    0.0687  -1.222 -1.416  0.042 
   1.0733    1.2485    1.2485  -0.381 -1.222 -0.090 
   1.2210   -0.2458   -0.2458   1.264 -0.381 -1.204 
   0.5385    0.1434    0.1434   0.589  1.264  0.848 
  -0.9179   -1.0685   -1.0685   0.244  0.589 -0.567 
  -0.6149    0.5778    0.5778  -1.040  0.244  1.352 
   0.5032    0.3996    0.3996  -0.095 -1.040 -1.254 
   0.5752   -0.0495   -0.0495   0.551 -0.095  0.227 
   1.6063    1.3866    1.3866   0.300  0.551 -0.064 
   1.7682    0.2262    0.2262   1.456  0.300 -1.355 
   0.0558   -0.7969   -0.7969   1.040  1.456  0.451 
  -0.0013    0.7173    0.7173  -0.464  1.040  0.571 
*/
