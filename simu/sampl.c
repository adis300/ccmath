/*  sampl.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
sampl(void **s,int n,void **d,int m)
{ int k;
  for(k=0; k<n ;--m,++d)
    if(bran(m)<n-k) s[k++]= *d;
}
