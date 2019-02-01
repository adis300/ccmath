/*  xpwr.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "xpre.h"
struct xpr xpwr(struct xpr s,int n)
{ struct xpr t; unsigned k,m;
  t=one;
  if(n<0){ m= -n; s=xdiv(one,s);} else m=n;
  if(m){ for(k=1; k<=m ;k<<=1){
           if((k&m)) t=xmul(s,t); s=xmul(s,s); }
   }
  return t;
}  
struct xpr xpr2(struct xpr s,int m)
{ unsigned short *p=(unsigned short *)&s;
  *p+=m; return s;
}
