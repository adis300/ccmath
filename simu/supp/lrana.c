/*  lrana.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
   C version of the routine for a multiplicative
   generator modulo 2^31-1.
*/

static unsigned int m=16807U,k=0xffffU,j=0xfffeU;
static unsigned int u=0x80000000U,v=0x7fffffffU;
unsigned int lrana(unsigned int s)
{ register unsigned int z,f;
  z=m*(s&k); f=(s>>16)*m; f+=(z>>16);
  z=(z&k)+(f<<16); f=(f>>15)&j;
  if(z&u) f|=1L;
  s=f+(z&v);
  if(s&u) s=(s+1)&v;
  return s;
}
