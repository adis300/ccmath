/*  tlbits.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  lbset  lbget  lbcnt
*/
#include "ccmath.h"
void main(void)
{ unsigned int x; int n,m;
  m=sizeof(x)<<3;
/* set bits in long */
  for(x=0L,n=0; n<m ;++n)
    if(n%5==0) x=lbset(x,n);
  printf(" x hex = %x\n",x);
/* count set bits in long */
  n=lbcnt(x); printf(" # of bits set = %d\n",n);
/* set specified bits in long */
  for(n=0; n<m ;++n)
    if(lbget(x,n)) printf(" bit # %d is set\n",n);
  x=~01; printf(" x = %x has %d bits set\n",x,lbcnt(x));
}
/*  Test output

 x hex = 42108421
 # of bits set = 7
 bit # 0 is set
 bit # 5 is set
 bit # 10 is set
 bit # 15 is set
 bit # 20 is set
 bit # 25 is set
 bit # 30 is set
 x = fffffffe has 31 bits set
*/
