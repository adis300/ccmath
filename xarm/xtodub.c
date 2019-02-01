/*  xtodub.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "xpre.h"
#include <math.h>
double xtodub(struct xpr s)
{ unsigned short pe[4],*pc,u; short i,e;
  pc=(unsigned short *)&s;
  u= *pc&m_sgn; e=(*pc&m_exp)-d_bias;
  if(e>=d_max) return HUGE_VAL; if(e<=0) return 0.;
  for(i=0; i<4 ;) pe[i++]= *++pc;
  pe[0]&=m_exp; rshift(d_lex-1,pe,4);
  pe[0]|=(e<<(16-d_lex)); pe[0]|=u;
  u=pe[3]; pe[3]=pe[0]; pe[0]=u;
  u=pe[2]; pe[2]=pe[1]; pe[1]=u;
  return *(double *)pe;
}
struct xpr dubtox(double y)
{ unsigned short pe[XDIM+1],*pc,u; short i,e;
  pc=(unsigned short *)&y; pc+=3;
  u= *pc&m_sgn; e=d_bias+((*pc&m_exp)>>(16-d_lex));
  for(i=1; i<5 ;) pe[i++]= *pc--; while(i<=XDIM) pe[i++]=0;
  pc=pe+1; lshift(d_lex-1,pc,4); *pc|=m_sgn;
  *pe=e; *pe|=u; return *(struct xpr *)pe;
}
struct xpr inttox(int n)
{ unsigned short pe[XDIM+1],*pc; short e;
  unsigned k,h;
  pc=(unsigned short *)&k;
  for(e=0; e<=XDIM ;) pe[e++]=0;
  if(n==0) return *(struct xpr *)pe;
  k=abs(n); *(pe+1)= *(pc+1); *(pe+2)= *pc;
  for(e=0,h=1; h<=k ;h<<=1,++e);
  *pe=bias+e-1; if(n<0) *pe|=m_sgn;
  lshift(32-e,pe+1,XDIM); return *(struct xpr *)pe;
}
