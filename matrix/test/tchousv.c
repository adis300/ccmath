/*  tchousv.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  chousv

    Uses:  hconj  cmmul  cmprt

    Input File:  hm4.bin
*/
#include "ccmath.h"
char fmt[]="(%7.3f,%7.3f)";
Cpx *r;
void main(int na,char **av)
{ Cpx *a,*h,*u,*h1,*p;
  double *ev,*dp; int i,j,n;
  FILE *fb;
  if(na!=2){ printf("para: input_file\n"); exit(1);}
  fb=fopen(*++av,"rb");
  fread((void *)&n,sizeof(int),1,fb);
  a=(Cpx *)calloc(4*n*n,sizeof(Cpx));
  h=a+n*n; u=h+n*n; h1=u+n*n;
  ev=(double *)calloc(2*n,sizeof(double)); dp=ev+n;
  fread((void *)a,sizeof(Cpx),n*n,fb);
  printf(" mat a-in:\n"); cmprt(a,n,n,fmt);

/* Householder rotation to tridiagonal with transformation matrix */
  chousv(a,ev,dp,n);

  printf("  evc:\n"); cmprt(a,n,n,fmt);
  for(i=0,p=h; i<n ;++i,p+=n+1){
    p->re=ev[i];
    if(i<n-1){ (p+1)->re=dp[i]; (p+n)->re=dp[i];}
   }
  printf(" td2:\n"); cmprt(h,n,n,fmt);

/* check transformation matrix */
  cmcpy(u,a,n*n); hconj(u,n);
  cmmul(h1,h,a,n); cmmul(a,u,h1,n);
  printf(" evc^*ad*evc:\n"); cmprt(a,n,n,fmt);
}
/* Test output

 mat a-in:
(  2.232, -0.000)( -0.073, -0.075)( -0.321,  0.030)(  0.379,  0.031)
( -0.073,  0.075)(  1.673,  0.000)( -0.102, -0.006)(  0.266, -0.178)
( -0.321, -0.030)( -0.102,  0.006)(  1.284,  0.000)(  0.143,  0.048)
(  0.379, -0.031)(  0.266,  0.178)(  0.143, -0.048)(  1.812,  0.000)
  evc:
(  1.000,  0.000)(  0.000,  0.000)(  0.000,  0.000)(  0.000,  0.000)
(  0.000,  0.000)( -0.143, -0.147)( -0.631,  0.059)(  0.743,  0.062)
(  0.000,  0.000)(  0.607,  0.269)(  0.474, -0.043)(  0.577, -0.019)
(  0.000,  0.000)(  0.142,  0.705)( -0.445, -0.417)( -0.153, -0.295)
 td2:
(  2.232,  0.000)(  0.509,  0.000)(  0.000,  0.000)(  0.000,  0.000)
(  0.509,  0.000)(  1.340,  0.000)(  0.335,  0.000)(  0.000,  0.000)
(  0.000,  0.000)(  0.335,  0.000)(  1.900,  0.000)(  0.132,  0.000)
(  0.000,  0.000)(  0.000,  0.000)(  0.132,  0.000)(  1.528,  0.000)
 evc^*ad*evc:
(  2.232,  0.000)( -0.073, -0.075)( -0.321,  0.030)(  0.379,  0.031)
( -0.073,  0.075)(  1.673, -0.000)( -0.102, -0.006)(  0.266, -0.178)
( -0.321, -0.030)( -0.102,  0.006)(  1.284,  0.000)(  0.143,  0.048)
(  0.379, -0.031)(  0.266,  0.178)(  0.143, -0.048)(  1.812, -0.000)
*/
