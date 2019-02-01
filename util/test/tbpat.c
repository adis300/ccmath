/*  tbpat.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  bitpc  bitps  bitpl  bitpd  (print bit patterns)
*/
#include "ccmath.h"
void main(void)
{ char c; short n; int l;
  float f; double d;
  c='0'; n=519; l= -1;
  f=1.5; d=.333333333333333333;
  printf(" char c= %c\n",c);
  printf("c: "); bitpc(c);
  printf(" short int n= %d\n",n);
  printf("n: "); bitps(n);
  printf(" int m= %d\n",l);
  printf("m: "); bitpl(l);
  printf(" float f= %13.8f\n",f);
  printf("f: "); bitpf(f);
  printf(" double d= %18.14f\n",d);
  printf("d: "); bitpd(d);
}
/* Test output

 char c= 0
c: 00110000
 short int n= 519
n: 0000001000000111
 int m= -1
m: 11111111111111111111111111111111
 float f=    1.50000000
f: 001111111^10000000000000000000000
 double d=   0.33333333333333
d: 001111111101^0101010101010101010101010101010101010101010101010101
*/
