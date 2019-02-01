/*  tcminv.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  cminv

    Uses:  cmmul  cmprt  cmcpy  unitary

    Input parameter: n -> size (complex matrix is n by n)
*/
#include "ccmath.h"
char fm[]="(%8.5f,%8.5f)";
void main(int na,char **av)
{ int n,m,k; Cpx *a,*b,*c;
  unsigned int seed=123498765;
  if(na!=2){ printf("para: dim\n"); exit(1);}
  n=atoi(*++av); m=n*n;
  a=(Cpx *)calloc(3*m,sizeof(Cpx));
  b=a+m; c=b+m;
  setunfl(seed);
  unitary(a,n); cmcpy(b,a,m);
  printf(" mat a:\n");
  cmprt(a,n,n,fm);

/* invert complex matrix */
  k=cminv(a,n);

  if(k==0){
    printf(" inv a:\n");
    cmprt(a,n,n,fm);
/* check inverse matrix */
  cmmul(c,a,b,n);
  printf(" check inv(a)*a:\n");
  cmprt(c,n,n,fm);
    }
  else printf("matrix singular\n");
}
/* Test output

 mat a:
(-0.39965,-0.04599)( 0.28884, 0.75524)(-0.17199,-0.17545)(-0.18556,-0.29926)
( 0.13874, 0.08869)(-0.39158, 0.18086)(-0.58589, 0.56577)(-0.33845, 0.09446)
( 0.26285,-0.63911)( 0.22703,-0.21969)( 0.04795, 0.19192)(-0.34543,-0.51399)
( 0.24143,-0.52461)( 0.21397, 0.12063)(-0.38404,-0.29942)( 0.10946, 0.59753)
 inv a:
(-0.39965, 0.04599)( 0.13874,-0.08869)( 0.26285, 0.63911)( 0.24143, 0.52461)
( 0.28884,-0.75524)(-0.39158,-0.18086)( 0.22703, 0.21969)( 0.21397,-0.12063)
(-0.17199, 0.17545)(-0.58589,-0.56577)( 0.04795,-0.19192)(-0.38404, 0.29942)
(-0.18556, 0.29926)(-0.33845,-0.09446)(-0.34543, 0.51399)( 0.10946,-0.59753)
 check inv(a)*a:
( 1.00000,-0.00000)( 0.00000, 0.00000)(-0.00000, 0.00000)( 0.00000,-0.00000)
(-0.00000, 0.00000)( 1.00000, 0.00000)(-0.00000,-0.00000)(-0.00000,-0.00000)
(-0.00000,-0.00000)(-0.00000,-0.00000)( 1.00000,-0.00000)( 0.00000,-0.00000)
(-0.00000,-0.00000)(-0.00000,-0.00000)( 0.00000,-0.00000)( 1.00000, 0.00000)
*/
