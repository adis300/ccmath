/*  unfl2dis.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
     Test:  unfl2()  setunfl2()  autcor()  hist()

     Input parameters:  n -> integer: sample size
                        s -> unsigned integer: pseudorandom seed
*/
#include "ccmath.h"
int lag=20,nbin=20;
double xmin=0.,xmax=1.;
void main(int na,char **av)
{ double *x,*p,xm,bin,dsq,c,*ac;
  int n,i,k,*hs; unsigned int s;
  if(na!=3){ printf("para: siz seed(hex)\n"); exit(-1);}
  n=atoi(*++av); sscanf(*++av,"%x",&s);
  printf(" sample size= %d\n",n);
  printf(" seed= %x\n",s);
  x=(double *)calloc(sizeof(double),n);

/* initialize pseudorandom generator */
  setunfl2(s); xm=0.;
/* generate sample of pseudorandom numbers uniform on [0,1] */
  for(p=x,i=0; i<n ;++i){
    *p=unfl2(); xm+= *p++;
   }
  printf("  mean= %e\n",xm/n);
  for(i=0,p=x; i<n ;++i) *p++ -=0.5;

/* compute autocorrelations of sample */
  ac=autcor(x,n,lag); dsq=ac[0]/n;
  for(i=0,p=x; i<n ;++i) *p++ +=0.5;
  printf("  variance= %e\n",dsq);
  printf("  autocorrelations\n");
  for(i=1,c=0.; i<=lag ;++i){
    c+=ac[i]*ac[i];
    printf("    %2d  %10.2e   %5.2f\n",i,ac[i],c*n);
   }

/* compute histogram of sample distribution */
  hs=hist(x,n,xmin,xmax,nbin,&bin);
  printf(" histogram bin= %.2f\n",bin);
  printf("  %d < %4.1f  %d > %4.1f\n",hs[-1],xmin,hs[nbin],xmax);
  for(i=0,xm=xmin,k=hs[-1],dsq=n; i<nbin ;++i,xm+=bin){
    k+=hs[i]; c=k/dsq;
    printf("   %5.2f to %5.2f  %5d    %5.3f\n",xm,xm+bin,hs[i],c);
   }
}
