/*  xfmod.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "xpre.h"
struct xpr xfmod(struct xpr s,struct xpr t,int *p)
{ struct xpr h; unsigned short *q,*ph; short k;
  h=xdiv(s,t); ph=(unsigned short *)&h; k=(*ph&m_exp)-bias;
  if(k>=0){ rshift(31-k,ph+1,2);
    q=(unsigned short *)p;
    *(q+1)= *(ph+1); *q= *(ph+2);
   }
  else *p=0;
  if(*p){ if(*ph&m_sgn) s=xadd(s,xmul(t,inttox(*p)),0);
          else s=xadd(s,xmul(t,inttox(*p)),1);
   }
  return s;
}
struct xpr xfrex(struct xpr s,int *p)
{ unsigned short *ps=(unsigned short *)&s,u;
  *p=(*ps&m_exp)-bias+1; u= *ps&m_sgn;
  *ps=bias-1; *ps|=u; return s;
}
