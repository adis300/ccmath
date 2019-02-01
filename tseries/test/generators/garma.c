/*  garma.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  sarma  setsim     (generates an ARMA model test series)

    Uses:  nrml  setnrml

    Input parameters:  n -> integer: length of series

                       control_file -> name of model definition file

                               [ ts?.dat -> time series model ]

                       outfile -> name of output file
                                  [binary data -> a series size header
                                   and the values of the series]
*/
#include "ccmath.h"
double *y;
struct mcof *par,*pma; int nar,nma,np;
void main(int na,char **av)
{ double z; FILE *fp,*fo;
  int n,i,j,k; unsigned int seed;
  struct mcof *pa; char cfl[32],ofl[32];
  if(na!=4){ printf("para: n control_file outfile\n"); exit(-1);}
  n=atoi(*++av);
  y=(double *)calloc(n,sizeof(*y));
  fp=fopen(*++av,"r"); strcpy(cfl,*av);
  fo=fopen(*++av,"wb"); strcpy(ofl,*av);
  fscanf(fp,"%d %d",&nar,&nma); np=nar+nma;
  par=(struct mcof *)calloc(np,sizeof(*pa)); pma=par+nar;
  for(j=0,pa=par; j<np ;++j,++pa){
    fscanf(fp,"%lf %d",&(pa->cf),&(pa->lag));
    pa->lag-=1;
   }
  fscanf(fp,"%u",&seed);
  setnrml(seed);

/* initialize series simulation */
  setsim(1); n+=25;
  for(j=k=0; j<n ;++j){

/* generate time series values (skip first 25) */
    z=sarma(nrml()); if(j>=25) y[k++]=z;

   }

/* write series to output file with size as a header record */
  n-=25; fwrite((void *)&n,sizeof(int),1,fo);
  k=fwrite((void *)y,sizeof(double),n,fo);
  if(k!=n){ printf("I/O error\n"); exit(1);}

/* write model specification */
  printf("  control file = %s\n",cfl);
  printf("  output file  = %s\n",ofl);
  printf("  %d points generated\n",n);
  printf("    random seed= %u\n",seed);
  if(nar){
    printf(" autoregressive parameters and lags\n");
    for(j=0,pa=par; j<nar ;j++,pa++)
      printf("%f  %d\n",pa->cf,pa->lag+1);
   }
  if(nma){
    printf(" moving average paramerers and lags\n");
    for(j=0,pa=pma; j<nma ;j++,pa++)
      printf("%f  %d\n",pa->cf,pa->lag+1);
   }
}
