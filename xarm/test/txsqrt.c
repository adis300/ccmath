/*  txsqrt.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  xsqrt

    Uses:  atox  xprcmp  xadd  xtodub  prxpr
*/
#define XMATH 1
#include "ccmath.h"
int decd=30;
void main(void)
{ struct xpr z,w,f,u;
  printf("     Test of Sqrt Function\n");
  z=zero; w=atox("0.2"); u=atox("4.01");
  for(; xprcmp(&z,&u)<0 ;z=xadd(z,w,0)){

/* compute extended precision square root */
    f=xsqrt(z);

    printf(" %8.4f  ",xtodub(z)); prxpr(f,decd);
   }
}
/*  Test output

     Test of Sqrt Function
   0.0000    0.000000000000000000000000000000e+0
   0.2000    4.472135954999579392818347337463e-1
   0.4000    6.324555320336758663997787088865e-1
   0.6000    7.745966692414833770358530799565e-1
   0.8000    8.944271909999158785636694674925e-1
   1.0000    1.000000000000000000000000000000e+0
   1.2000    1.095445115010332226913939565602e+0
   1.4000    1.183215956619923208513465658312e+0
   1.6000    1.264911064067351732799557417773e+0
   1.8000    1.341640786499873817845504201239e+0
   2.0000    1.414213562373095048801688724210e+0
   2.2000    1.483239697419132589742279488160e+0
   2.4000    1.549193338482966754071706159913e+0
   2.6000    1.612451549659709930473322646061e+0
   2.8000    1.673320053068151095956344051570e+0
   3.0000    1.732050807568877293527446341506e+0
   3.2000    1.788854381999831757127338934985e+0
   3.4000    1.843908891458577462000454856353e+0
   3.6000    1.897366596101027599199336126660e+0
   3.8000    1.949358868961792781367682639980e+0
   4.0000    2.000000000000000000000000000000e+0
*/
