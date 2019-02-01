/*  shift.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
void lshift(int n,unsigned short *pm,int m)
{ unsigned short *pa,*pc;
  pc=pm+m-1; pa=pm+n/16; m=n%16; n=16-m;
  for(; pa<pc ;){ *pm=(*pa++)<<m; *pm++ |= *pa>>n;}
  *pm++ = *pa<<m; while(pm<=pc) *pm++ =0;
}
void rshift(int n,unsigned short *pm,int m)
{ unsigned short *pa,*pc;
  pc=pm+m-1;
  if(n<16*m){ pa=pc-n/16; m=n%16; n=16-m;
    for(; pa>pm ;){ *pc=(*pa--)>>m; *pc-- |= *pa<<n;}
    *pc-- = *pa>>m;
   }
  while(pc>=pm) *pc-- =0;
}
