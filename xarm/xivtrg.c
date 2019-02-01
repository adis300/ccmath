/*  xivtrg.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "xpre.h"
#include <math.h>
struct xpr xatan(struct xpr z)
{ struct xpr s,f; int k,m;
  if((k=xex(&z))<k_lin) return z;
  if(k>=bias){ z=xdiv(one,z); m=1;} else m=0;
  f=dubtox(atan(xtodub(z)));
  s=xadd(one,xmul(z,z),0);
  for(k=0; k<itt_div ;++k)
    f=xadd(f,xdiv(xadd(z,xtan(f),1),s),0);
  if(m){ if(neg(&f)) return xadd(xneg(pi2),f,1);
     else return xadd(pi2,f,1); }
  else return f;
}
struct xpr xasin(struct xpr z)
{ struct xpr u,xatan();
  if(xex(&z)<k_lin) return z;
  u=xsqrt(xadd(one,xmul(z,z),1));
  if(xex(&u)== -bias){
    if(neg(&z)) return xneg(pi2); else return pi2;}
  return xatan(xdiv(z,u));
}
struct xpr xacos(struct xpr z)
{ struct xpr u,xatan();
  if(xex(&z)== -bias) return pi2;
  u=xsqrt(xadd(one,xmul(z,z),1)); u=xatan(xdiv(u,z));
  if(neg(&u)) return xadd(pi,u,0); else return u;
}
