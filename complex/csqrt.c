/*  csqrt.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "complex.h"
struct complex csqrt(Cpx z)
{ double r;
  r=sqrt(z.re*z.re+z.im*z.im);
  r=sqrt(ldexp(r+fabs(z.re),-1));
  if(r==0.) z.re=z.im=0.;
  else{
    if(z.re>=0.){ z.re=r; z.im=ldexp(z.im/r,-1);}
    else{ z.re=ldexp(fabs(z.im)/r,-1);
      if(z.im>=0.) z.im=r; else z.im= -r;
     }
   }
  return z;
}
