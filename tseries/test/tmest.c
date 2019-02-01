/*  tmest.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  fixts  seqts     (Estimate an ARMA model of a time series.)

    Uses:  eigen  evmax  evmod

    Input parameters:  mod_fl -> name of model initialization file

                       ser_fl -> name of binary ARMA time series
                                 data file  [ created by garma ]

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
double *x,*var,*cr;
struct mcof *par,*pma; int nar,nma,np;
double *x; int nmax;
void main(int na,char **av)
{ struct mcof *pp; double ssq,sig,ev;
  int n,j,k; FILE *fm,*fs;
  char fnam[32],cs[4];
  if(na!=3){ printf("para: mod_fl ser_fl\n"); exit(-1);}
  fm=fopen(*++av,"r"); printf("  model file: %s\n",*av);
  
/*  model initialization */
  fscanf(fm," %d %d",&nar,&nma);
  np=nar+nma;
/* size model parameter and variance arrays */
  par=(struct mcof *)calloc(np,sizeof(*par)); pma=par+nar;
/* store for variance eigenvalues and vectors */
  var=(double *)calloc(np*np+np,sizeof(double));
  cr=var+np*np;
  printf(" model structure:\n");
  for(j=0,pp=par; j<nar ;++j){
    fscanf(fm,"%d",&(pp->lag));
    printf(" ar at lag %d\n",pp->lag);
    pp->lag-=1; ++pp;
   }
  for(j=0; j<nma ;++j){
    fscanf(fm,"%d",&(pp->lag));
    printf(" ma at lag %d\n",pp->lag);
    pp->lag-=1; ++pp;
   }
  fclose(fm);

/* read series file */
  strcpy(fnam,*++av); fs=fopen(fnam,"rb");
  printf("  data file: %s\n",fnam);
  fread((void *)&nmax,sizeof(int),1,fs);
  x=(double *)calloc(nmax,sizeof(double));
  n=fread((char *)x,sizeof(x[0]),nmax,fs);
  printf(" %d points input\n\n",n);

/* start interactive estimation of model parameters */
  for(j=0; ;++j){
    fprintf(stderr," (s,f) q->quit ");
    if(*gets(cs)=='q') break;

/* sequential estimation step */
    if(cs[0]=='s') ssq=seqts(x,n,var,j);
/* gauss-newton estimation step */
    else ssq=fixts(x,n,var,cr);

    printf(" step %d  ssq= %8.3f  %s\n",j,ssq,cs);
    printf(" p_vec: ");
    for(pp=par,k=0; k<np ;++k,++pp) printf(" %7.4f",pp->cf);
    printf("\n");
/* compute maximum eigenvalue and vector of parameter variance */
    ev=evmax(var,cr,np)*sqrt(ssq/(n-np));
    printf("  ev_max= %.9.6f and vector:\n",ev);
    matprt(cr,1,np," %.3f");
    printf("\n");
   }
  printf(" final state:\n");
  printf("  ssq= %8.3f\n",ssq);
  printf("  final p_vec: ");
  for(pp=par,k=0; k<np ;++k,++pp) printf(" %7.4f",pp->cf);
  printf("\n");
  sig=sqrt(ssq/(n-np)); printf("  rms e= %8.5f\n",sig);
  for(k=0; k<np*np ;) var[k++]*=sig;
  printf("  variance matrix:\n"); matprt(var,np,np," %10.7f");
/* compute all variance eigenvalues and vectors of final model */
  eigen(var,cr,np);
  printf("  var-eval:\n"); matprt(cr,1,np," %10.7f");
  printf("  var-evec:\n"); matprt(var,np,np," %10.3f");

/* save computed model residuals to file with .er extension */
  fprintf(stderr," save residuals? (y/n) "); gets(cs);
  if(cs[0]=='y'){
    for(j=0; fnam[j] && fnam[j]!='.' ;++j);
    fnam[j]=0; strcat(fnam,".er");
    fm=fopen(fnam,"wb"); setev(1);
    for(j=0; j<n ;++j) x[j]=evmod(x[j]);
/* write header specifying number of residuals to file */
    fwrite((void *)&n,sizeof(int),1,fm);
/* write residuals */
    fwrite((void *)x,sizeof(double),n,fm);
   }
}
/*  Test output

  model file: data/ts0.d
 model structure:
 ar at lag 1
 ar at lag 2
 ma at lag 1
  data file: data/ts0.b
 400 points input

 step 0  ssq=  390.162  s
 p_vec:   0.8181 -0.6456  0.2708
  ev_max= %..6f and vector:
 0.590 -0.204 0.782

 step 1  ssq=  370.635  s
 p_vec:   0.8253 -0.6499  0.2837
  ev_max= %..6f and vector:
 0.585 -0.200 0.786

 step 2  ssq=  369.781  s
 p_vec:   0.8287 -0.6518  0.2895
  ev_max= %..6f and vector:
 0.584 -0.198 0.787

 step 3  ssq=  368.638  f
 p_vec:   0.8387 -0.6568  0.3067
  ev_max= %..6f and vector:
 0.581 -0.194 0.790

 step 4  ssq=  368.585  f
 p_vec:   0.8394 -0.6569  0.3078
  ev_max= %..6f and vector:
 0.582 -0.189 0.791

 final state:
  ssq=  368.585
  final p_vec:   0.8394 -0.6569  0.3078
  rms e=  0.96355
  variance matrix:
  0.0037425 -0.0012860  0.0037688
 -0.0012860  0.0016152 -0.0008902
  0.0037688 -0.0008902  0.0063045
  var-eval:
  0.0092879  0.0006495  0.0017248
  var-evec:
      0.582     -0.709     -0.399
     -0.189     -0.595      0.781
      0.791      0.379      0.480
*/
