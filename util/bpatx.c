/*  bpatx.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "xpre.h"
void bpatx(struct xpr x)
{ unsigned short t,u; int j,k,m;
  m=sizeof(x)<<3; t=u=0x8000;
  for(j=k=0; j<m ;++j){
    if(x.nmm[k]&t) printf("1"); else printf("0");
    if(j==15) printf("^");
    if(j==16) printf(".");
    if(j==67) printf("\n    ");
    if((t>>=1)==0){ t=u; ++k;}
   }
  printf("\n");
}
