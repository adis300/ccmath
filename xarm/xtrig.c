/*  xtrig.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "xpre.h"
static struct xpr ctan(struct xpr u);
static struct xpr rred(struct xpr u,int i,int *p);
struct xpr xtan(struct xpr z)
{ int k,m;
  z=rred(z,'t',&k);
  if(xprcmp(&z,&pi4)==1){ m=1; z=xadd(pi2,z,1);} else m=0;
  if(k&1) z=xneg(ctan(z)); else z=ctan(z);
  if(m) return xdiv(one,z); else return z;
}
struct xpr xcos(struct xpr z)
{ int k;
  z=rred(z,'c',&k);
  if(xex(&z)<k_lin){
    if(k&1) return xneg(one); else return one;}
  z=ctan(xpr2(z,-1)); z=xmul(z,z);
  z=xdiv(xadd(one,z,1),xadd(one,z,0));
  if(k&1) return xneg(z); else return z;
}
struct xpr xsin(struct xpr z)
{ int k;
  z=rred(z,'s',&k); if(xex(&z)<k_lin) return z;
  z=ctan(xpr2(z,-1)); z=xdiv(xpr2(z,1),xadd(one,xmul(z,z),0));
  if(k&1) return xneg(z); else return z;
}
static struct xpr ctan(struct xpr z)
{ struct xpr s,f,d; int m;
  if(xex(&z)<k_lin) return z;
  s=xneg(xmul(z,z)); f=zero;
  for(d=inttox(m=ms_trg); m>1 ;){
    f=xdiv(s,xadd(d,f,0)); d=inttox(m-=2); }
  return xdiv(z,xadd(d,f,0));
}
static struct xpr rred(struct xpr z,int kf,int *ps)
{ int is;
  if(neg(&z)){ z=xneg(z); is=1;} else is=0;
  z=xfmod(z,pi,ps);
  if(kf=='t') *ps=is; else if(kf=='s') *ps+=is;
  if(xprcmp(&z,&pi2)==1){
    z=xadd(pi,z,1);
    if(kf=='c' || kf=='t') ++(*ps);
   }
  return z;
}
