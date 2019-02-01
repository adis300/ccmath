/*  complex.h    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#ifndef CPX
struct complex {double re,im;};
typedef struct complex Cpx;
#define CPX  1
#endif
#include <math.h>
struct complex cadd(),csub(),cmul(),cdiv();
struct complex crmu(),cimu(),ccng(),cdef();
double cabs(),cnrm();
struct complex csqrt(),cexp(),clog();
struct complex csin(),ccos(),ctan();
struct complex casin(),cacos(),catan();
struct complex csinh(),ccosh(),ctanh();
struct complex casinh(),cacosh(),catanh();
