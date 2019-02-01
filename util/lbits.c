/*  lbits.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
unsigned int lbset(unsigned int x,int n)
{ unsigned int t=01;
  t<<=n; return (x|t);
}
int lbget(unsigned int x,int n)
{ unsigned int t=01L;
  t<<=n; if(x&t) return 1; else return 0;
}
int lbcnt(unsigned int x)
{ int c=0;
  if(x) ++c;
  while((x=x&(x-1))!=0) ++c;
  return c;
}
