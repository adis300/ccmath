/*  tcasin.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  casin  csin
*/
#include "ccmath.h"
void main(void)
{ Cpx z,f;
  while(1){
    printf("z ? ");
/*  enter Ctrl-Z to terminate */    
    if(scanf("%lf %lf",&z.re,&z.im)==EOF) break;
    f=casin(z); z=csin(f);
    printf("asin(z)=(%e, %e) sin(f)=(%e, %e)\n",f.re,f.im,z.re,z.im);
   }
} 
