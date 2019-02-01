/*  lran1.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
static unsigned int s,h,sbuf[256];
static unsigned int a=1664525U,c=244045795;
unsigned int lran1()
{ register int i;
  i=(int)(s>>24); s=sbuf[i];  
  h=h*a+c; sbuf[i]=h;
  return s;
}
void setlran1(unsigned int sa)
{ int k;
  for(h=sa,k=0; k<=256 ;++k){
    h=h*a+c;
    if(k<256) sbuf[k]=h; else s=h;
   }
}
