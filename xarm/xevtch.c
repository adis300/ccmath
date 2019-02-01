/*  xevtch.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "xpre.h"
struct xpr xevtch(struct xpr z,struct xpr *a,int m)
{ struct xpr *p,f,t,tp,w;
  w=xpr2(z,1); t=zero; tp=zero;
  for(p=a+m; p>a ;){
    f=xadd(*p--,xadd(xmul(w,t),tp,1),0);
    tp=t; t=f;
   }
  return xadd(*p,xadd(xmul(z,t),tp,1),0);
}
