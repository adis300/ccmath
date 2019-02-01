/*  tqrlsq.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  qrlsq

    Input file:  tqr1.dat
*/
#include "ccmath.h"
void main(int na,char **av)
{ double x,dx,f,t;
  double *b,*c,*ad,*p;
  int n,m,i,j;
  FILE *fp;
  if(na!=2){ printf("para: in_file\n"); exit(-1);}
  fp=fopen(*++av,"r");
  fscanf(fp,"%d %d %lf",&n,&m,&dx);
  c=(double *)calloc(n,sizeof(double));
  b=(double *)calloc(m,sizeof(double));
  ad=(double *)calloc(m*n,sizeof(double));
  for(i=0; i<n ;++i) fscanf(fp,"%lf",c+i);
  printf(" %d meas. %d param.\n",m,n);
  printf(" cf-in:\n"); matprt(c,1,n," %9.4f");
  for(i=0,x=0.,p=ad; i<m ;++i){
    x+=dx;
    for(j=0,f=0.,t=1.; j<n ;++j){
      f+=c[j]*(*p++ =t); t*=x;
     }
    b[i]=f;
   }
  
/* compute least squares coefficients via QR reduction */  
  t=qrlsq(ad,b,m,n,&j);
  
  printf(" ssq= %.3e\n",t);
  if(j== -1) printf(" singular reduced matrix\n");
  else{ printf(" cf-out:\n"); matprt(b,1,n," %10.6f");}
}
/* Test output
  
 40 meas. 4 param.
 cf-in:
    1.5000   -3.0000    2.0000   -1.2000
 ssq= 6.691e-31
 cf-out:
   1.500000  -3.000000   2.000000  -1.200000
*/
