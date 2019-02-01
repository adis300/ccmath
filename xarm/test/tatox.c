/*  tatox.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  atox  prxpr  xprint

    Input file:  atox.dat
*/
#define XMATH 1
#include "ccmath.h"
int decd=30;
void main(int na,char **av)
{ struct xpr f;
  FILE *fp;
  char num[64];
  if(na!=2){ printf("para: input_file\n"); exit(-1);}
  fp=fopen(*++av,"r");
  while(fscanf(fp,"%s",num)!=EOF){
    printf(" string in : %s\n",num);

/* convert ascii string to extended precision */
    f=atox(num);

    printf(" f =       "); prxpr(f,decd);
    printf(" hex =       "); xprint(f);
   }
}
/*  Test output

 string in : 1.25
 f =         1.250000000000000000000000000000e+0
 hex =       3fff.9ffffffffffffffffffffffffffa
 string in : 1.234567890123456789012345678901
 f =         1.234567890123456789012345678901e+0
 hex =       3fff.9e06521462cfdb8d3df0b5b5b3dc
 string in : 1.326457891245678800213456789012e+512
 f =         1.326457891245678800213456789011e+512
 hex =       46a4.969e8eb82353816d4739377f0d6f
 string in : -9.876543210123456789098765432108e-70
 f =        -9.876543210123456789098765432107e-70
 hex =       bf19.da2117a8c6ec0619ba34035d5f84
 string in : 0.3333333333333333333333333333333
 f =         3.333333333333333333333333333333e-1
 hex =       3ffd.aaaaaaaaaaaaaaaaaaaaaaaaa8d5
 string in : 1.10e-3
 f =         1.100000000000000000000000000000e-3
 hex =       3ff5.902de00d1b71758e219652bd3c27
*/
