/*  tunitar.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  unitary  hconj

    Uses:  cmmul  cmcpy  cmprt

    Input parameter: n -> size of unitary matrix is n by n
*/
#include "ccmath.h"
unsigned int seed=123456789;
void main(int na,char **av)
{ Cpx *u,*v,*e;
  int i,j,k,n;
  if(na!=2){ printf("para: size\n"); exit(1);}
  n=atoi(*++av);
  u=(Cpx *)calloc(n*n,sizeof(Cpx));
  v=(Cpx *)calloc(n*n,sizeof(Cpx));
  e=(Cpx *)calloc(n*n,sizeof(Cpx));
  setunfl(seed);

/* generate a unitary matrix */
  unitary(u,n);

  printf(" size= %d :\n",n);
  cmprt(u,n,n," (%7.4f,%7.4f)");

/* compute the hermitian conjugate matrix */
  cmcpy(v,u,n*n); hconj(v,n);

  printf(" hconj:\n");
  cmprt(v,n,n," (%7.4f,%7.4f)");
/* check the unitary propery of the matrix */
  cmmul(e,u,v,n);
  printf(" test unitary property\n");
  cmprt(e,n,n," (%6.3f,%6.3f)");
}
/* Test output

 size= 4 :
 ( 0.2956, 0.2530) (-0.2439, 0.0696) (-0.1821, 0.8027) (-0.0506, 0.3228)
 (-0.6321, 0.2510) ( 0.4965,-0.1105) ( 0.2111, 0.4394) (-0.0399,-0.1987)
 ( 0.4894, 0.3046) ( 0.3478, 0.3572) (-0.1526, 0.0178) ( 0.0184,-0.6286)
 ( 0.1045, 0.2068) ( 0.5993, 0.2630) (-0.0805,-0.2341) ( 0.0057, 0.6758)
 hconj:
 ( 0.2956,-0.2530) (-0.6321,-0.2510) ( 0.4894,-0.3046) ( 0.1045,-0.2068)
 (-0.2439,-0.0696) ( 0.4965, 0.1105) ( 0.3478,-0.3572) ( 0.5993,-0.2630)
 (-0.1821,-0.8027) ( 0.2111,-0.4394) (-0.1526,-0.0178) (-0.0805, 0.2341)
 (-0.0506,-0.3228) (-0.0399, 0.1987) ( 0.0184, 0.6286) ( 0.0057,-0.6758)
 test unitary property
 ( 1.000, 0.000) ( 0.000, 0.000) (-0.000, 0.000) ( 0.000, 0.000)
 ( 0.000,-0.000) ( 1.000, 0.000) ( 0.000,-0.000) ( 0.000,-0.000)
 (-0.000,-0.000) ( 0.000, 0.000) ( 1.000, 0.000) (-0.000, 0.000)
 ( 0.000,-0.000) ( 0.000, 0.000) (-0.000,-0.000) ( 1.000, 0.000)
*/
