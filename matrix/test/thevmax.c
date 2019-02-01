/*  thevmax.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  hevmax

    Uses:  unitary  hmgen  cvmul  cvnrm  cmprt

    Input parameter:  n -> dimension (matrix is n by n)
*/
#include <time.h>
#include "ccmath.h"
void main(int na,char **av)
{ Cpx *h,*u,*v,*w,c; int i,n;
  double *ev,e; void *calloc();
  unsigned int seed;
  if(na!=2){ printf("para: dim\n"); exit(1);}
  n=atoi(*++av);
  seed=123456789; setunfl(seed);
  ev=(double *)calloc(n,sizeof(double));
  h=(Cpx *)calloc(2*(n*n+n),sizeof(Cpx));
  u=h+n*n; v=u+n*n; w=v+n;
  for(i=0,e=1.; i<n ;++i,e+=.5) ev[i]=e;

/* generate a Hermitian matrix */
  unitary(u,n);
  hmgen(h,ev,u,n);
  printf(" input matrix h:\n");
  cmprt(h,n,n,"(%6.3f,%6.3f)");

/* compute eigenvalue of maximum modulus and corresponding
   eigenvector for a Hermitian matrix */
  e=hevmax(h,v,n);

  printf(" max. eigenvalue = %12.4e\n",e);
  printf(" eigenvector v:\n");
  cmprt(v,1,n,"(%6.3f,%6.3f)");
/* check eigenvalue and vector */
  cvmul(w,h,v,n);
  printf(" vector h*v:\n");
  cmprt(w,1,n,"(%6.3f,%6.3f)");
  c=cvnrm(w,v,n);
  printf(" v^*h*v= (%6.3f,%6.3f)\n",c.re,c.im);
}
/* Test output

 input matrix h:
( 1.870,-0.000)( 0.157, 0.219)(-0.294,-0.102)( 0.090,-0.000)
( 0.157,-0.219)( 1.429,-0.000)( 0.228,-0.222)(-0.187,-0.046)
(-0.294, 0.102)( 0.228, 0.222)( 1.741,-0.000)(-0.478, 0.000)
( 0.090, 0.000)(-0.187, 0.046)(-0.478,-0.000)( 1.960,-0.000)
 max. eigenvalue =   2.5000e+00
 eigenvector v:
( 0.327,-0.000)(-0.190, 0.070)(-0.624, 0.079)( 0.667,-0.110)
 vector h*v:
( 0.817,-0.000)(-0.475, 0.175)(-1.560, 0.198)( 1.667,-0.276)
 v^*h*v= ( 2.500,-0.000)
*/
