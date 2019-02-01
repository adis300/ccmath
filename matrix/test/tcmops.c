/*  tcmops.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  cmattr  trncm

    Uses:  cmmult  cmprt

    Input file:  cm42.dat
*/
#include "ccmath.h"
char cfmt[]="(%7.3f,%7.3f)";
void main(int na,char **av)
{ Cpx *a,*b,*c,*p;
  int i,j,n,m; FILE *fp;
  if(na!=2){ printf("para: input_file\n"); exit(-1);}
  fp=fopen(*++av,"r");
  fscanf(fp,"%d %d",&n,&m);
  b=(Cpx *)calloc(2*n*m,sizeof(Cpx)); c=b+n*m;
  a=(Cpx *)calloc(n*n,sizeof(Cpx));
  for(i=0,p=b; i<n ;++i){
    for(j=0; j<m ;++j,++p) fscanf(fp,"%lf %lf",&(p->re),&(p->im));
   }

  printf(" Mat b:\n"); cmprt(b,n,m,cfmt);

/* general complex transpose */
  cmattr(c,b,n,m);

  printf(" Mat b':\n"); cmprt(c,m,n,cfmt);
  for(i=0,p=c; i<n*m ;++i,++p) p->im= -(p->im);
  cmmult(a,b,c,n,m,n);
  printf(" Mat a=b*b^:\n"); cmprt(a,n,n,cfmt);

/* square matrix transpose */
  trncm(a,n);

  printf(" Mat a':\n"); cmprt(a,n,n,cfmt);
}
/* Test output

 Mat b:
( -0.542,  1.345)( -0.830, -1.434)
( -2.256,  0.567)( -1.018, -0.849)
( -0.832,  0.843)( -0.999, -1.059)
(  0.147,  0.758)(  0.673, -0.536)
 Mat b':
( -0.542,  1.345)( -2.256,  0.567)( -0.832,  0.843)(  0.147,  0.758)
( -0.830, -1.434)( -1.018, -0.849)( -0.999, -1.059)(  0.673, -0.536)
 Mat a=b*b^:
(  4.848,  0.000)(  4.048, -1.972)(  3.933, -0.109)(  1.150, -0.801)
(  4.048,  1.972)(  7.168,  0.000)(  4.271,  1.200)( -0.132,  0.676)
(  3.933,  0.109)(  4.271, -1.200)(  3.522,  0.000)(  0.412, -0.494)
(  1.150,  0.801)( -0.132, -0.676)(  0.412,  0.494)(  1.336,  0.000)
 Mat a':
(  4.848,  0.000)(  4.048,  1.972)(  3.933,  0.109)(  1.150,  0.801)
(  4.048, -1.972)(  7.168,  0.000)(  4.271, -1.200)( -0.132, -0.676)
(  3.933, -0.109)(  4.271,  1.200)(  3.522,  0.000)(  0.412,  0.494)
(  1.150, -0.801)( -0.132,  0.676)(  0.412, -0.494)(  1.336,  0.000)
*/
