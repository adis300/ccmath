/*  txexp.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  xexp

    Uses:  atox  xtodub  xprcmp  xadd  prxpr
*/
#define XMATH 1
#include "ccmath.h"
int decd=30;
void main(void)
{ struct xpr z,h,f,u;
  printf("     Test of Exp Function\n");
  z=xneg(one); h=atox("0.5"); u=atox("3.01");
  for(; xprcmp(&z,&u)<0 ;z=xadd(z,h,0)){

/* compute extended precision exponential */
    f=xexp(z);

    printf(" %8.4f  ",xtodub(z)); prxpr(f,decd);
   }
}
/*  Test output

     Test of Exp Function
  -1.0000    3.678794411714423215955237701615e-1
  -0.5000    6.065306597126334236037995349912e-1
  -0.0000    1.000000000000000000000000000000e+0
   0.5000    1.648721270700128146848650787814e+0
   1.0000    2.718281828459045235360287471503e+0
   1.5000    4.481689070338064822602055460119e+0
   2.0000    7.389056098930650227230427460985e+0
   2.5000    1.218249396070347343807017595117e+1
   3.0000    2.008553692318766774092852965570e+1
*/
