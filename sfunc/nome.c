/*  nome.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
double nome(double k,double *pk,double *pkp)
{ double a,b,s,r,pi2=1.57079632679490;
  a=s=1.; b=sqrt(1.-k*k);
  while(a-b>4.e-15 || s-k>4.e-15){
    r=a+b; b=sqrt(a*b); a=r/2.;
    r=s+k; k=sqrt(s*k); s=r/2.;
   }
  *pk=pi2/a; a*=(*pkp=pi2/s);
  return exp(-2.*a);
}
