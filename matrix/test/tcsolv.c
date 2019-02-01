/*  tcsolv.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  csolv

    Uses:  cmprt  cvmul  unitary

    Input parameter:  n -> size  matrix is n by n and solution
                                 is an n-vector
*/
#include "ccmath.h"
void main(int na,char **av)
{ int n,k; Cpx *a,*u,*v;
  unsigned int seed;
  if(na!=2){ printf("para: dim\n"); exit(1);}
  n=atoi(*++av);
  u=(Cpx *)calloc(n*n+2*n,sizeof(Cpx));
  v=u+n*n; a=v+n;
  seed=543216789; setunfl(seed);
  for(k=0; k<n ;++k){ a[k].re=unfl(); a[k].im=unfl();}
  unitary(u,n);
  printf(" true solution:\n"); cmprt(a,1,n,"(%8.5f,%8.5f)");
/* generate right hand side */
  cvmul(v,u,a,n);
  printf(" matrix:\n"); cmprt(u,n,n,"(%8.5f,%8.5f)");
  printf(" vector:\n"); cmprt(v,1,n,"(%8.5f,%8.5f)");

/* solve complex linear system */
  k=csolv(u,v,n);

  if(k) printf(" singular\n");
  else{
    printf(" solution:\n"); cmprt(v,1,n,"(%8.5f,%8.5f)");
   }
}
/* Test output

 true solution:
( 0.81157, 0.36618)( 0.40349, 0.87236)( 0.33222, 0.75337)( 0.47570, 0.28618)
 matrix:
( 0.15971, 0.34017)( 0.62179, 0.50586)( 0.15040, 0.24687)(-0.18230,-0.31537)
(-0.37703, 0.33174)( 0.17199, 0.09581)( 0.52298,-0.39916)( 0.34247, 0.39864)
( 0.39613,-0.10197)( 0.19946, 0.23492)(-0.33267, 0.22341)( 0.35652, 0.67084)
(-0.29003,-0.59594)( 0.34363, 0.32507)(-0.27529,-0.49723)(-0.10751,-0.04912)
 vector:
(-0.31784, 1.07422)( 0.08164, 0.86890)(-0.06685, 0.57583)( 0.08398,-0.58564)
 solution:
( 0.81157, 0.36618)( 0.40349, 0.87236)( 0.33222, 0.75337)( 0.47570, 0.28618)
*/
