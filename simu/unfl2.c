/*  unfl2.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
static unsigned int s,h,ss[256];
unsigned int lranb(unsigned int);
double unfl2()
{ register int i; unsigned int c;
  s=lranb(s);
  h=h*69069U+4098479U;
  i=(h>>24); c=ss[i]; ss[i]=s;
  return (double)c*4.656612875245797e-10;
}
void setunfl2(unsigned int sa)
{ int k;
  for(s=sa,k=0; k<=256 ;++k){
    s=lranb(s);
    if(k<256) ss[k]=s; else h=s;
   }
}
