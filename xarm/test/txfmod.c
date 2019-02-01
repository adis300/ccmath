/*  txfmod.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  xfmod  xfrex  xpr2

    Uses:  atox  prxpr

    Input parameters:  x -> extended precision: first argument
                       y -> extended precision: second argument
*/
#define XMATH 1
#include "ccmath.h"
int decd=30;
void main(int na,char **av)
{ struct xpr s,t,f; int k;
  if(na!=3){ printf("para: x y\n"); exit(-1);}
  printf("     Test of FMOD functions\n");
  s=atox(*++av); t=atox(*++av);
  printf(" inputs:\n");
  printf(" s="); prxpr(s,decd);
  printf(" t="); prxpr(t,decd);

/* extended precision modular divide */
  f=xfmod(s,t,&k);

  printf(" s mod t = "); prxpr(f,decd);
  printf("       k = %d\n",k);
  printf("\n s="); prxpr(s,decd);

/* extended precision exponent extraction */
  s=xfrex(s,&k);

  printf(" exp= %d\n",k);
  printf(" <s>="); prxpr(s,decd);

/* extended precision power of two */
  s=xpr2(s,k);
  printf("   s="); prxpr(s,decd);
}
/*  Test output

     Test of FMOD functions
 inputs:
 s=  1.250000000000000000000000000000e+1
 t=  3.000000000000000000000000000000e+0
 s mod t =   5.000000000000000000000000000000e-1
       k = 4

 s=  1.250000000000000000000000000000e+1
 exp= 4
 <s>=  7.812500000000000000000000000000e-1
   s=  1.250000000000000000000000000000e+1
*/
