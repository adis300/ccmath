/*  prxpr.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <stdio.h>
#include "xpre.h"
static double ltn2=.3010299956639812;
static int q[5*XDIM+4];
void prxpr(struct xpr u,int lim)
{ int *p=q,k,m=0;
  unsigned short *pa=(unsigned short *)&u;
  if((*pa&m_sgn)){ *pa^=m_sgn; printf(" -");} else printf("  ");
  if(*pa==0){ printf("0."); for(k=0; k<lim ;++k) printf("0");}
  else{ *p=0;
    m=((*pa&m_exp)-bias); m=(int)((double)(m+1)*ltn2);
    if(m) u=xmul(u,xpwr(ten,-m));
    while((*pa&m_exp)<bias){ --m; u=xmul(u,ten);}
    for(k=0; k<=lim ;++k){
      u=sfmod(u,++p); if(*pa==0) break; u=xmul(ten,u); }
    for(; k<=lim ;++k) *++p=0;
    if(*pa){ u=sfmod(u,&k); if(k>=5) ++(*p);
       while(*p==10){ *p=0; ++(*--p);} }
    p=q; if(*p==0) ++p; else ++m; printf("%d.",*p++);
    for(k=0; k<lim ;++k) printf("%d",*p++);
   }
  if(m>=0) printf("e+%d\n",m); else printf("e%d\n",m);
}
void xprint(struct xpr u)
{ int i;
  printf("%04x.",u.nmm[0]);
  for(i=0; i<XDIM ;++i) printf("%04x",u.nmm[i+1]);
  printf("\n");
}
