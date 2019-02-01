/*  atox.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "xpre.h"
struct xpr atox(char *q)
{ struct xpr s;
  unsigned short pc[XDIM+1],*pn,*pa,*pb;
  unsigned int n; unsigned short sfg,bex;
  int pfg,dex,j,c,m;
  pn=(unsigned short *)&s;
  for(j=0; j<=XDIM ;++j) pn[j]=pc[j]=0;
  pfg=dex=0; sfg=0; m=XDIM+1;
  if(*q=='+') ++q;
  else if(*q=='-'){ sfg=0x8000; ++q;}
  for(; *q ;++q){
    if(*q=='.'){
      if(pfg) break; else pfg=1;
      ++q;
     }
    if((c=(int)*q-48)<0 || c>9) break;
    if(pn[0]){ if(!pfg) ++dex; }
    else{
      lshift(1,pn,m);
      for(j=0; j<m ;++j) pc[j]=pn[j];
      lshift(2,pn,m);
      for(n=(unsigned int)c,pa=pn+XDIM,pb=pc+XDIM; pa>=pn ;){
        n+= *pa; n+= *pb--; *pa-- = n; n>>=16;
       }
      if(pfg) --dex;
     }
   }
  bex=bias+max_p-1;
  for(j=0; j<m && pn[j]==0 ;++j);
  if(j==m) return zero;
  if(j){ j<<=4; bex-=j; lshift(j,pn,m);}
  while(pn[0]){ rshift(1,pn,m); ++bex;}
  pn[0]=bex|sfg;
  if(*q=='e' || *q=='E'){
    ++q; sfg=0;
    if(*q=='+') ++q;
    else if(*q=='-'){ sfg=1; ++q;}
    for(j=0; *q ;++q){
      if((c=(int)*q-48)<0 || c>9) break;
      j<<=1; m=j; j<<=2; j+=c+m;
     }
    if(sfg) j= -j;
    dex+=j;
   }
  if(dex) s=xmul(s,xpwr(ten,dex));
  return s;
}
