/*  gfarma.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  sarma  setsim  sintg     (generate an ARIMA factor model)

    Uses:  nrml  setnrml  bran  setbran

    Input parameters:  n -> integer: length of generated series

                       control_file -> name of input file specifing model

                             [ tsf?.dat -> time series factor model ]

                       outfile -> name of file for series output
                                  [binary data -> a series size header
                                   and the values of the generated
                                   series]

*/
#include "ccmath.h"
struct mcof *pfc,*par,*pma;
int nfc,nar,nma,np,ndif;
struct fmod *y;
void main(int na,char **av)
{ struct mcof *pa; int n,np,i,j,k,m;
  double sm,z; unsigned int seed;
  FILE *fp,*fout;
  char cfl[32],ofl[32];
  if(na!=4){ printf("para: n control_file outfile\n"); exit(-1);}
  n=atoi(*++av);
  y=(struct fmod *)calloc(n,sizeof(*y));
  fp=fopen(*++av,"r"); strcpy(cfl,*av);
  fout=fopen(*++av,"wb"); strcpy(ofl,*av);
/* read model parameters from control file */
  fscanf(fp,"%d %d %d %d",&nfc,&nar,&nma,&ndif);
  np=nma+nar+nfc;
  pfc=(struct mcof *)calloc(np,sizeof(*pa));
  par=pfc+nfc; pma=par+nar;
  for(j=0,pa=pfc; j<np ;j++,++pa){
     fscanf(fp,"%lf %d",&(pa->cf),&(pa->lag));
     pa->lag-=1;
    }
  fscanf(fp,"%u",&seed);
  setnrml(seed); setbran(seed);

/* initialize series simulation */
  setsim(1); n+=25;

  for(j=0,k=0,sm=0.; j<n ;j++){

/* generate series values */
      z=sarma(nrml());

/* integrate series values if difference is nonzero */
      if(ndif) z=sintg(z,ndif,j);


/* generate factors and add factor levels to integrated series */
      if(j>=25){ y[k].fac=m=bran(nfc);
           sm+=( y[k++].val=z+(pfc+m)->cf);}
    }

/* write series size header and series values to output file */
  n-=25; fwrite((void *)&n,sizeof(int),1,fout);
  k=fwrite((void *)y,sizeof(y[0]),n,fout);
  if(k!=n){ printf("I/O error\n"); exit(1);}

/* write model specification */
  printf("  control file = %s\n",cfl);
  printf("  output file  = %s\n",ofl);
  printf("  %d points generated\n",n);
  printf("  random seed= %u\n",seed);
  printf(" factor parameters:\n");
  for(j=0,pa=pfc; j<nfc ;j++,pa++)
      printf("%f\n",pa->cf);
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
  printf("  difference order = %d\n",ndif);
  printf("  series mean = %.4f\n",sm/n);
}
