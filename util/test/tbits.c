/*  tbits.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  bset  bget  bcnt
*/
#include "ccmath.h"
void main(void)
{ unsigned short n,x,m;
  m=sizeof(m)<<3;
/* set bits */
  for(x=n=0; n<m ;++n)
    if(n%5==0) x=bset(x,n);
  printf(" x octal = %o\n",x);
/* count bits set */
  n=bcnt(x); printf(" # of bits set = %d\n",n);
/* read specified bits */
  for(n=0; n<m ;++n)
    if(bget(x,n)) printf(" bit # %d is set\n",n);
  x=~01; printf(" x = %o has %d bits set\n",x,bcnt(x));
}
/*  Test output

 x octal = 102041
 # of bits set = 4
 bit # 0 is set
 bit # 5 is set
 bit # 10 is set
 bit # 15 is set
 x = 177776 has 15 bits set
*/
