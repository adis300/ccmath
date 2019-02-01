/*  xadd.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "xpre.h"
struct xpr xadd(struct xpr s,struct xpr t,int f)
{ unsigned short pe[XDIM+1],*pa,*pb,*pc,*pf=pe,h,u;
  unsigned int n=0; short e,k;
  pa=(unsigned short *)&s; pb=(unsigned short *)&t;
  e= *pa&m_exp; k= *pb&m_exp; if(f) *pb^=m_sgn;
  u=(*pb ^ *pa)&m_sgn; f=0;
  if(e>k){ if((k=e-k)>=max_p) return s; rshift(k,pb+1,XDIM);}
  else if(e<k){ if((e=k-e)>=max_p) return t;
    rshift(e,pa+1,XDIM); e=k; pc=pa; pa=pb; pb=pc;}
  else if(u){ for(pc=pa,pf=pb; *++pc== *++pf && f<XDIM ;++f);
    if(f>=XDIM) return zero; if(*pc<*pf){ pc=pa; pa=pb; pb=pc;}
    pf=pe+f; }
  h= *pa&m_sgn;
  if(u){ for(pc=pb+XDIM; pc>pb ;--pc) *pc= ~(*pc); n=1L;}
  for(pc=pe+XDIM,pa+=XDIM,pb+=XDIM; pc>pf ;){
    n+= *pa--;  n+= *pb--; *pc-- =n; n>>=16;
   }
  if(u){ for(; *++pc==0 ;++f);
    for(k=0; !((*pc<<k)&m_sgn) ;++k);
    if(k+=16*f){ if((e-=k)<=0) return zero; lshift(k,pe+1,XDIM);}
   }
  else{ if(n){ if((++e)==(short)m_exp) return x_huge;
    rshift(1,++pf,XDIM); *pf|=m_sgn; }
   }
  *pe=e; *pe|=h; return *(struct xpr *)pe;
}
