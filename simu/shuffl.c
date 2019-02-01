/*  shuffl.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
shuffl(void **s,int n)
{ int i,j; void *t;
  for(j=n; j>0 ;){
    i=bran(j--);
    t=s[i]; s[i]=s[j]; s[j]=t;
   }
}
