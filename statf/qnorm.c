/*  qnorm.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
double qnorm(double x)
{ double y,ro,f,t; int k,nf;
  if(x<0.){ x= -x; nf=0;} else nf=1;
  y=x*x; ro=exp(-y/2.)/2.506628274631;
  if(x<3.){ f=t=1.;
    for(k=1; t>1.e-14 ;){ t*=y/(k+=2); f+=t;}
    f=.5-x*ro*f; }
  else{ f=x; k=ceil(250./y); if(k<3) k=3;
    for(; k>0 ;) f=x+(k--)/f;
    f=ro/f; }
  if(nf) return f; else return 1.-f;
}
