/*  nrmldis.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
     Test:  nrml()  setnrml()  autcor()  hist()

     Input parameters:  n -> integer: sample size
                        s -> unsigned integer: pseudorandom seed
*/
#include "ccmath.h"
int lag=20,nbin=18;
double xmin= -4.5,xmax=4.5;
void main(int na,char **av)
{ double *x,*p,xm,bin,dsq,c,*ac;
  int n,i,k,*hs; unsigned int s;
  if(na!=3){ printf("para: siz seed(hex)\n"); exit(-1);}
  n=atoi(*++av); sscanf(*++av,"%x",&s);
  printf(" sample size= %d\n",n);
  printf(" seed= %x\n",s);
  x=(double *)calloc(sizeof(double),n);
/* initialize random normal generator */
  setnrml(s); xm=0.;
/* generate random normal sample */
  for(p=x,i=0; i<n ;++i){
    *p=nrml(); xm+= *p++;
   }
  printf("  mean= %e\n",xm/n);

/* compute autocorrelations */
  ac=autcor(x,n,lag); dsq=ac[0]/n;

  printf("  variance= %e\n",dsq);
  printf("  autocorrelations\n");
  for(i=1,c=0.; i<=lag ;++i){
    c+=ac[i]*ac[i];
    printf("    %2d  %10.2e   %5.2f\n",i,ac[i],c*n);
   }

/* compute distribution histogram of random normals */
  hs=hist(x,n,xmin,xmax,nbin,&bin);

  printf(" histogram bin= %.2f\n",bin);
  printf("  %d < %4.1f  %d > %4.1f\n",hs[-1],xmin,hs[nbin],xmax);
  for(i=0,xm=xmin,k=hs[-1],dsq=n; i<nbin ;++i,xm+=bin){
    k+=hs[i]; c=k/dsq;
    printf("   %4.1f to %4.1f  %5d    %5.3f\n",xm,xm+bin,hs[i],c);
   }
}
