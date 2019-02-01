/*  txaop1.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  xadd  xmul  xdiv

    Uses:  atox  prxpr  xtodub

    Input file:  data/aop1.dat
*/
#define XMATH 1
#include "ccmath.h"
int decd=30;
void main(int na,char **av)
{ struct xpr s,t,f;
  char nbx[64],nby[64];
  FILE *fp;
  if(na!=2){ printf("para: input_file\n"); exit(-1);}
  fp=fopen(*++av,"r");
  printf("     Test of Elementary Operations\n");
  while(fscanf(fp,"%s %s",nbx,nby)!=EOF){
    s=atox(nbx); t=atox(nby);
    printf(" x= "); prxpr(s,decd);
    printf(" y= "); prxpr(t,decd);

/* extended precision addition */
    printf("add\n");
    f=xadd(s,t,0);
    printf(" %16.10f\n",xtodub(f)); prxpr(f,decd);

/* extended precision subtraction */
    printf("subtract\n");
    f=xadd(s,t,1);
    printf(" %16.10f\n",xtodub(f)); prxpr(f,decd);

/* extended precision multiplication */
    printf("multiply\n");
    f=xmul(s,t);
    printf(" %16.10f\n",xtodub(f)); prxpr(f,decd);

/* extended precision division */
    printf("divide\n");
    f=xdiv(s,t);
    printf(" %16.10f\n",xtodub(f)); prxpr(f,decd);
   }
}
/*  Test output

     Test of Elementary Operations
 x=   1.000000000000000000000000000000e+0
 y=   4.000000000000000000000000000000e+0
add
     5.0000000000
  5.000000000000000000000000000000e+0
subtract
    -3.0000000000
 -3.000000000000000000000000000000e+0
multiply
     4.0000000000
  4.000000000000000000000000000000e+0
divide
     0.2500000000
  2.500000000000000000000000000000e-1
 x=  -2.300000000000000000000000000000e+0
 y=   3.147159000000000000000000000000e+0
add
     0.8471590000
  8.471590000000000000000000000000e-1
subtract
    -5.4471590000
 -5.447159000000000000000000000000e+0
multiply
    -7.2384657000
 -7.238465700000000000000000000000e+0
divide
    -0.7308178583
 -7.308178582651845680501048723627e-1
 x=   2.750000000000000000000000000000e+1
 y=  -3.360000000000000000000000000000e+1
add
    -6.1000000000
 -6.100000000000000000000000000000e+0
subtract
    61.1000000000
  6.110000000000000000000000000000e+1
multiply
  -924.0000000000
 -9.240000000000000000000000000000e+2
divide
    -0.8184523810
 -8.184523809523809523809523809524e-1
 x=  -1.110000000000000000000000000000e+1
 y=  -4.000000000000000000000000000000e-1
add
   -11.5000000000
 -1.150000000000000000000000000000e+1
subtract
   -10.7000000000
 -1.070000000000000000000000000000e+1
multiply
     4.4400000000
  4.440000000000000000000000000000e+0
divide
    27.7500000000
  2.775000000000000000000000000000e+1
*/
