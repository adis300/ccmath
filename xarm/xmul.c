/*  xmul.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "xpre.h"
struct xpr xmul(struct xpr s,struct xpr t)
{ unsigned short pe[XDIM+2],*pa,*pb,*pc,*q0,*q1,h;
  unsigned int m,n,p; short k,e;
  q0=(unsigned short *)&s; q1=(unsigned short *)&t;
  e=(*q0&m_exp)-bias; k=(*q1&m_exp)+1;
  if(e>(short)m_exp-k) return x_huge; if((e+=k)<=0) return zero;
  h=(*q0 ^ *q1)&m_sgn;
  for(++q1,k=XDIM,p=n=0L,pc=pe+XDIM+1; k>0 ;--k){
    for(pa=q0+k,pb=q1; pa>q0 ;){
      m=  *pa--; m*= *pb++; n+=(m&0xffffL); p+=(m>>16); }
    *pc-- =n; n=p+(n>>16); p=0L;
   }
  *pc=n;
  if(!(*pc&m_sgn)){ --e; if(e<=0) return zero; lshift(1,pc,XDIM+1);}
  if(e==(short)m_exp) return x_huge;
  *pe=e; *pe|=h; return *(struct xpr *)pe;
}
