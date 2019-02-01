/*  tcmmul.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  cmmul

    Uses:  unitary  cmcpy  cmprt

    Input parameter:  n -> size (matrices are n by n)
*/
#include "ccmath.h"
unsigned int seed=123456789;
void main(int na,char **av)
{ Cpx *u,*v,*c;
  int n,m;
  if(na!=2){ printf("para: size\n"); exit(1);}
  n=atoi(*++av); m=n*n;
  c=(Cpx *)calloc(3*m,sizeof(Cpx));
  u=c+m; v=u+m;
  setunfl(seed);
  unitary(u,n);
  printf(" size= %d :\n",n);
  cmprt(u,n,n," (%7.4f,%7.4f)");
  cmcpy(v,u,n*n);

/* multiply complex square matrices */
  cmmul(c,u,v,n);

/* check second matrix factor */
  printf(" v-out:\n");
  cmprt(v,n,n," (%7.4f,%7.4f)");
  printf(" matrix square\n");
  cmprt(c,n,n," (%7.4f,%7.4f)");
}
/* Test output

 size= 4 :
 ( 0.2956, 0.2530) (-0.2439, 0.0696) (-0.1821, 0.8027) (-0.0506, 0.3228)
 (-0.6321, 0.2510) ( 0.4965,-0.1105) ( 0.2111, 0.4394) (-0.0399,-0.1987)
 ( 0.4894, 0.3046) ( 0.3478, 0.3572) (-0.1526, 0.0178) ( 0.0184,-0.6286)
 ( 0.1045, 0.2068) ( 0.5993, 0.2630) (-0.0805,-0.2341) ( 0.0057, 0.6758)
 v-out:
 ( 0.2956, 0.2530) (-0.2439, 0.0696) (-0.1821, 0.8027) (-0.0506, 0.3228)
 (-0.6321, 0.2510) ( 0.4965,-0.1105) ( 0.2111, 0.4394) (-0.0399,-0.1987)
 ( 0.4894, 0.3046) ( 0.3478, 0.3572) (-0.1526, 0.0178) ( 0.0184,-0.6286)
 ( 0.1045, 0.2068) ( 0.5993, 0.2630) (-0.0805,-0.2341) ( 0.0057, 0.6758)
 matrix square
 (-0.2456, 0.4050) (-0.6684, 0.4147) (-0.2458,-0.0411) ( 0.2097, 0.2252)
 (-0.5301, 0.3591) ( 0.3158,-0.1163) (-0.0163,-0.3963) ( 0.3233,-0.4637)
 (-0.1901,-0.0243) ( 0.1885,-0.3215) (-0.5428, 0.6065) ( 0.3673, 0.1644)
 (-0.5736, 0.0045) ( 0.1680, 0.3175) ( 0.0000, 0.3436) (-0.6490,-0.0523)
*/
