/*  polyc.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "complex.h"
Cpx polyc(Cpx z,double *cof,int n)
{ int i; Cpx py; double s;
  for(i=n-1,py.re=cof[n],py.im=0.; i>=0 ;--i){
    s=py.re*z.re-py.im*z.im;
    py.im=py.im*z.re+py.re*z.im; py.re=s+cof[i];
   }
  return py;
}
