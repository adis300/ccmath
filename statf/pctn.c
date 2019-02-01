/*  pctn.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
double pctn(double pc)
{ double t,z,qnorm(double),te=1.e-9; int nf;
  if(pc<te || pc>1.-te) return HUGE_VAL;
  if(pc>.5){ pc=1.-pc; nf=0;} else nf=1;
  t=sqrt(-log(pc*pc));
  z=t-(2.30753+.27061*t)/(1.+(.99229+.04481*t)*t);
  do{ if(z>37.5) break; t=pc-qnorm(z);
      z-=2.506628274631*t*exp(z*z/2.); }
  while(fabs(t)>te);
  if(nf) return z; else return -z;
}
