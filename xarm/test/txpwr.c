/*  txpwr.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  xpwr

    Uses:  atox  prxpr

    Input parameters:  test_num -> extended precision: test number
                       max_pwr -> integer: maximum power computed
*/
#define XMATH 1
#include "ccmath.h"
int decd=30;
void main(int na,char **av)
{ struct xpr s,t;
  int i,m;
  if(na!=3){ printf("para: test_num max_pwr\n"); exit(-1);}
  printf("     Test of Extended Precision Integer Powers\n");
  s=atox(*++av); m=atoi(*++av);
  printf(" input s= "); prxpr(s,decd);
  for(i=2; i<=m ;++i){

/* compute ith power of input number */
    t=xpwr(s,i);

    printf(" s^%d = ",i); prxpr(t,decd);
   }
}
/*  Test output

     Test of Extended Precision Integer Powers
 input s=  -7.000000000000000000000000000000e-1
 s^2 =   4.900000000000000000000000000000e-1
 s^3 =  -3.430000000000000000000000000000e-1
 s^4 =   2.401000000000000000000000000000e-1
 s^5 =  -1.680700000000000000000000000000e-1
 s^6 =   1.176490000000000000000000000000e-1
*/
