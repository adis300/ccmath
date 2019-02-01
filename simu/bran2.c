/*  bran2.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
static unsigned int s,h,sbuf[256];
static unsigned int a=69069U,c=4098479U;
static unsigned int r=0xffff;
unsigned int lrana(unsigned int);
int bran2(int n)
{ register int i,j,k;
  unsigned int u;
  s=lrana(s); h=h*a+c; k=(h>>24);
  u=sbuf[k]; sbuf[k]=s;
  i=n*(u>>16); j=n*(u&r); i+=(j>>16);
  return (i>>15);
}
void setbran2(unsigned int sa)
{ int k;
  for(s=sa,k=0; k<=256 ;++k){
    s=lrana(s);
    if(k<256) sbuf[k]=s; else h=s;
   }
}
