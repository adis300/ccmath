/*  bran.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
static unsigned int s,h,sbuf[256];
static unsigned int a=1664525U,c=4098479U;
static unsigned int r=0xffff;
int bran(int n)
{ register int i,j;
  i=(int)(s>>24); s=sbuf[i];
  h=h*a+c; sbuf[i]=h;
  i=n*(s>>16); j=n*(s&r); i+=(j>>16);
  return (i>>16);
}
void setbran(unsigned int sa)
{ int c;
  for(h=sa,c=0; c<=256 ;++c){
    h=h*a+c;
    if(c<256) sbuf[c]=h; else s=h;
   }
}
