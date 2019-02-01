/*  tsvduvS.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
     This code tests the QR fix to ensure that it correctly generates
     both singular values and transformation matrices.

     inputs:  name of input file containing binary data
              number of test cases

              data/tdatS1.bin 1 or
              data/tdatS23.bin 23
*/
#include "ccmath.h"
#include <math.h>
char fma[]=" %11.6f",fme[]=" %14.7f",fmf[]=" %9.6f";
void main(int na,char **av)
{ int i,j,k,m,n,nn;
  double *a,*d,*u,*v;
  double *a1;
  double *p,*q;
  FILE *fin;
  if(na<3){ printf("para: file_in #cases\n"); exit(-1);}
  fin=fopen(*++av,"rb"); nn=atoi(*++av);
  m=n=4;
  a=(double *)calloc(m*n,sizeof(double));
  a1=(double *)calloc(m*n,sizeof(double));
  u=(double *)calloc(m*m,sizeof(double));
  v=(double *)calloc(n*n,sizeof(double));
  d=(double *)calloc(n,sizeof(double));
  for(k=0; k<nn; ++k){
    for(i=0,p=a; i<m ;++i){
      for(j=0; j<n ;++j,++p) fread(p,sizeof(double),1,fin);
     }
    mcopy(a1,a,m*n);
    printf(" dim: %d x %d\n",m,n);
    printf(" a-in:\n");
    matprt(a,m,n,fma);

/* singular value decomposition  d = u'*a*v  (best for m near n) */
    i=svduv(d,a,u,m,v,n);

    if(i== -1){ printf("error: m<n\n"); exit(-1);}
    printf(" mat-u:\n");
    matprt(u,m,m,fmf);
    printf(" mat-v:\n");
    matprt(v,n,n,fmf);
    printf(" sval:\n");
    matprt(d,1,n,fme);
/* check decomposition by computing d */
    rmmult(a,a1,v,m,n,n);
    trnm(u,m); rmmult(a1,u,a,m,m,n);
    printf(" mat u'*a*v:\n");
    matprt(a1,m,n,fme);
   }
}
