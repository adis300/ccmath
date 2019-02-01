/*  tfmest.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  seqtsf  fixtsf

    Uses:  sdiff  evfmod  setevf  evmax  eigen

    Input parameters:  mod_fl -> name of file of model initialization data

                       ser_fl -> name of binary factor model time series
                                 data file [ created by gfarma ]

    Prompted input:  at prompt  ' (s,f) q->quit '
                          enter  s  for a sequential parameter update
                                 f  for a gauss-newton parameter update
                                 q  to terminate estimation

                     at prompt  ' save residuals? (y/n) '
                          enter  y  to save residuals to a file
                                 n  to exit without saving residuals
*/
#include "ccmath.h"
#include <math.h>
struct mcof *pfc,*par,*pma;
int nfc,nar,nma,np,ndif;
struct fmod *x; int nmax;
void main(int na,char **av)
{ double *var,*cr;
  struct mcof *pp;
  double ssq,sig,ev,*pe;
  int n,j,k; FILE *fm,*fs;
  char fnam[32],cs[4];
  if(na!=3){ printf("para: mod_fl ser_fl\n"); exit(-1);}
  fm=fopen(*++av,"r");
  printf("     model file: %s\n",*av);

/* enter model initialization data */
  fscanf(fm,"%d %d %d %d",&nfc,&nar,&nma,&ndif);
  np=nfc+nar+nma;

/* allocate store for madel parameters and variance */
  pfc=(struct mcof *)calloc(np,sizeof(*pfc));
  par=pfc+nfc; pma=par+nar;
  var=(double *)calloc(np*np+np,sizeof(*var));
  cr=var+np*np;
  for(j=0,pp=pfc; j<nfc ;++j,++pp){
    fscanf(fm,"%lf",&pp->cf);
   }
  for(; j<nfc+nar ;++j,++pp){
    fscanf(fm,"%d",&pp->lag); pp->lag-=1;
   }
  for(; j<np ;++j,++pp){
    fscanf(fm,"%d",&pp->lag); pp->lag-=1;
   }
  fclose(fm);
  printf(" Model Structure\n");
  printf(" %d initial factor parameters\n",nfc);
  for(j=0,pp=pfc; j<nfc ;++j) printf(" %.2f",(pp++)->cf);
  printf("\n");
  if(nar){
    printf(" %d ar para. at lags",nar);
    for(j=0,pp=par; j<nar ;++j) printf(" %d",(pp++)->lag+1);
    printf("\n");
   }
  if(nma){
    printf(" %d ma para. at lags",nma);
    for(j=0,pp=pma; j<nma ;++j) printf(" %d",(pp++)->lag+1);
    printf("\n");
   }
  printf("  difference order = %d\n",ndif);

/* read factor model time series data */
  strcpy(fnam,*++av); fs=fopen(fnam,"rb");
  printf("     data file: %s\n",fnam);
  fread((void *)&nmax,sizeof(int),1,fs);
  x=(struct fmod *)calloc(nmax,sizeof(*x));
  n=fread((char *)x,sizeof(x[0]),nmax,fs);

/* difference input series if required */
  if(ndif){
     for(j=k=0; j<n ;++j){
       ev=sdiff(x[j].val,ndif,j);
       if(j-ndif>=0){ x[k].val=ev; x[k++].fac=x[j].fac;}
      }
     n-=ndif;
   }
  printf(" %d points used in fit\n\n",n);

/* start interactive estimation sequence */
  for(j=0; ;++j){
    fprintf(stderr," (s/f) q->quit ");
    if(*gets(cs)=='q') break;

/* sequential estimation step */
    if(cs[0]=='s') ssq=seqtsf(x,n,var,j);

/* gauss-newton estimation step */
    else ssq=fixtsf(x,n,var,cr);

    printf("%d  ssq= %8.3f  ",j,ssq);
    if(cs[0]=='s') printf("seq.\n"); else printf("fix\n");
    printf(" p_vec: ");
    for(pp=pfc,k=0; k<np ;++k,++pp) printf("  %7.4f",pp->cf);
/* compute maximum eigenvalue and vector of parameter variance */
    ev=evmax(var,cr,np)*sqrt(ssq/(n-np));
    printf("\n max ev and vector : %9.6f\n",ev);
    matprt(cr,1,np," %.3f");
    printf("\n");
   }
  printf(" final state:\n");
  printf("  ssq = %8.3f\n",ssq);
  printf("  p_vec: ");
  for(pp=pfc,k=0; k<np ;++k,++pp) printf("  %7.4f",pp->cf);
  printf("\n");  
  sig=sqrt(ssq/(n-np)); printf("  rms e = %8.5f\n",sig);
  for(k=0; k<np*np ;) var[k++]*=sig;
  printf("  variance matrix:\n"); matprt(var,np,np," %10.7f");

/* compute all eigenvalues and vectors of final variance estimate */
  eigen(var,cr,np);
  printf("  eigenvalues:\n"); matprt(cr,1,np," %10.7f");
  printf("  vectors:\n"); matprt(var,np,np," %10.3f");

/* compute and save the model residuals in a file with .er extension */
  fprintf(stderr," save model residuals? (y/n) "); gets(cs);
  if(cs[0]=='y'){
    for(j=0; fnam[j] && fnam[j]!='.' ;++j);
    fnam[j]=0; strcat(fnam,".er");
    fm=fopen(fnam,"wb");
    pe=(double *)calloc(n,sizeof(*pe));
    setevf(1);
    for(j=0; j<n ;++j) pe[j]=evfmod(x[j]);
/* write header specifing number of residuals to file */
    fwrite((void *)&n,sizeof(int),1,fm);
/* write residuals */
    fwrite((char *)pe,sizeof(double),n,fm);
   }
}
/*  Test output

     model file: data/tfs0.d
 Model Structure
 2 initial factor parameters
 0.48 0.48
 2 ar para. at lags 1 2
 1 ma para. at lags 1
  difference order = 0
     data file: data/tfs0.b
 400 points used in fit

0  ssq=  404.842  seq.
 p_vec:   -0.2561   0.7800   0.8560  -0.4883  -0.4139
 max ev and vector :  0.022466
 0.706 0.708 0.001 -0.010 0.008

1  ssq=  367.338  seq.
 p_vec:   -0.2520   0.7859   0.8541  -0.4915  -0.4384
 max ev and vector :  0.011396
 0.707 0.708 0.001 -0.007 0.006

2  ssq=  365.777  seq.
 p_vec:   -0.2504   0.7879   0.8531  -0.4924  -0.4483
 max ev and vector :  0.007779
 0.707 0.708 0.000 -0.005 0.005

3  ssq=  364.058  fix
 p_vec:   -0.2463   0.7912   0.8472  -0.4919  -0.4793
 max ev and vector :  0.024584
 0.707 0.708 -0.000 -0.001 0.001

 final state:
  ssq =  364.058
  p_vec:   -0.2463   0.7912   0.8472  -0.4919  -0.4793
  rms e =  0.96003
  variance matrix:
  0.0128710  0.0116984  0.0000696 -0.0000756  0.0001102
  0.0116984  0.0128999 -0.0000844  0.0000451 -0.0000749
  0.0000696 -0.0000844  0.0035962 -0.0024481  0.0026019
 -0.0000756  0.0000451 -0.0024481  0.0030263 -0.0021005
  0.0001102 -0.0000749  0.0026019 -0.0021005  0.0041369
  eigenvalues:
  0.0245840  0.0084018  0.0011812  0.0015415  0.0008221
  vectors:
      0.707      0.018      0.706     -0.036      0.005
      0.708     -0.019     -0.705      0.037     -0.006
     -0.000      0.596      0.008      0.336     -0.729
     -0.001     -0.513     -0.009     -0.539     -0.668
      0.001      0.617     -0.057     -0.770      0.149
*/
