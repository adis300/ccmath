/*  tcmmult.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  cmmult

    Uses:  cminv  cmprt  nrml

    Input parameters:  n1 n2 n3 -> size with
                                   matrix A n1 by n2
                                   matrix B n2 by n3
                                   product C n1 by n3
*/
#include "ccmath.h"
char fmt[]="(%7.3f,%7.3f)";
void main(int na,char **av)
{ int n,m,k,i; Cpx *a,*b,*c,*d;
  unsigned int seed;
  if(na!=4){ printf("para: dim1 dim2 dim3\n"); exit(1);}
  n=atoi(*++av); m=atoi(*++av); k=atoi(*++av);
  a=(Cpx *)calloc(n*m,sizeof(Cpx));
  b=(Cpx *)calloc(m*k,sizeof(Cpx));
  c=(Cpx *)calloc(n*k,sizeof(Cpx));
  d=(Cpx *)calloc(n*k,sizeof(Cpx));
  seed=123456789; setnrml(seed);
  for(i=0; i<n*m ;++i){ a[i].re=nrml(); a[i].im=nrml();}
  for(i=0; i<m*k ;++i){ b[i].re=nrml(); b[i].im=nrml();}
/* print matrix inputs */
  printf(" matrix a:\n");
  cmprt(a,n,m,fmt);
  printf(" matrix b:\n");
  cmprt(b,m,k,fmt);

/* general complex matrix multiply */
  cmmult(c,a,b,n,m,k);

  printf(" product matrix c=a*b:\n");
  cmprt(c,n,k,fmt);
/* check for first matrix factor a square matrix */
  if(n==m){
    cminv(a,n); cmmult(d,a,c,n,m,k);
    printf(" matrix b?:\n");
    cmprt(d,n,k,fmt);
   }
}
/* Test output

 matrix a:
(  0.456, -0.453)(  1.658, -0.721)( -0.772, -0.209)( -1.115, -0.536)
(  0.069,  1.248)( -0.246,  0.143)( -1.068,  0.578)(  0.400, -0.050)
(  1.387,  0.226)( -0.797,  0.717)(  1.812, -0.485)(  0.062,  1.092)
( -1.547, -0.627)( -1.427,  0.967)( -0.152,  1.304)( -0.679, -0.395)
 matrix b:
(  0.772,  0.618)(  1.177,  0.218)
( -0.849, -0.712)( -0.923, -1.232)
(  1.431,  0.184)( -1.627, -1.936)
(  0.842,  0.303)(  0.842,  0.772)
 product matrix c=a*b:
( -3.133, -1.867)( -1.459, -1.287)
( -1.691,  1.769)(  3.444,  3.051)
(  4.521,  1.567)( -1.476, -0.863)
(  0.184,  0.055)(  3.328, -2.894)
 matrix b?:
(  0.772,  0.618)(  1.177,  0.218)
( -0.849, -0.712)( -0.923, -1.232)
(  1.431,  0.184)( -1.627, -1.936)
(  0.842,  0.303)(  0.842,  0.772)
*/
