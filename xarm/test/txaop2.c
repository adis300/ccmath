/*  txaop2.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  neg  xex  xabs  xneg  xpr2

    Uses:  atox  prxpr

    Input parameter:  x -> extended precision: test number
*/
#define XMATH 1
#include "ccmath.h"
int decd=30;
void main(int na,char **av)
{ struct xpr s,t; int k;
  if(na!=2){ printf("para: test_num\n"); exit(-1);}
  printf("     Test of Utility Operations\n");
  s=atox(*++av);
  printf("   input x= "); prxpr(s,decd);

/* t= -s */
  t=xneg(s);
  printf(" t=xneg(x)= "); prxpr(t,decd);

/* s -> -s */
  neg(&s);
  printf("   neg(x) = "); prxpr(s,decd);

/* extract exponent */
  k=xex(&s); printf(" x-exp= k = %d\n",k);
  s=xpr2(s,-k);
  printf("      <s> = "); prxpr(s,decd);

/* restore exponent */
  s=xpr2(s,k);
  printf("  <s>*2^k = "); prxpr(s,decd);

/* s -> |s| */
  t=xabs(s);
  printf(" t=abs(s) = "); prxpr(t,decd);
}
/*  Test output


     Test of Utility Operations
   input x=  -1.240000000000000000000000000000e-3
 t=xneg(x)=   1.240000000000000000000000000000e-3
   neg(x) =  -1.240000000000000000000000000000e-3
 x-exp= k = -10
      <s> =  -1.269760000000000000000000000000e+0
  <s>*2^k =  -1.240000000000000000000000000000e-3
 t=abs(s) =   1.240000000000000000000000000000e-3
*/
