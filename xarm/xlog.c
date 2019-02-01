/*  xlog.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "xpre.h"
struct xpr xlog(struct xpr z)
{ struct xpr f,h; int k,m;
  if(neg(&z) || xex(&z)== -bias){
    printf("xlog range error\n"); return zero;}
  if(xprcmp(&z,&one)==0) return zero;
  z=xfrex(z,&m); z=xmul(z,srt2);
  z=xdiv(xadd(z,one,1),xadd(z,one,0));
  h=xpr2(z,1); z=xmul(z,z);
  for(f=h,k=1; xex(&h)> -max_p ;){
    h=xmul(h,z); f=xadd(f,xdiv(h,inttox(k+=2)),0);
   }
  return xadd(f,xmul(ln2,dubtox(m-.5)),0);
}
