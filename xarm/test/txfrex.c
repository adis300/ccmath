/*  txfrex.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  xfrex  xpr2

    Uses:  atox  prxpr

    Input file: xfrex.dat
*/
#define XMATH 1
#include "ccmath.h"
int decd=30;
void main(int na,char **av)
{ struct xpr s; int e;
  char str[64]; FILE *fp;
  if(na!=2){ printf("para: data_file\n"); exit(-1);}
  fp=fopen(*++av,"r");
  while(fscanf(fp,"%s",str)!=EOF){
    s=atox(str);
    printf(" s-in="); prxpr(s,decd);

/* extract exponent of extended precision number */
    s=xfrex(s,&e);

    printf(" exp= %d\n",e);
    printf(" <s>= "); prxpr(s,decd);

/* restore exponent of extended precision number */
    s=xpr2(s,e);

    printf("  s1= "); prxpr(s,decd);
   }
}
/*  Test output

 s-in=  1.234500000000000000000000000000e+0
 exp= 1
 <s>=   6.172500000000000000000000000000e-1
  s1=   1.234500000000000000000000000000e+0
 s-in= -2.123450987654321000000000000000e+0
 exp= 2
 <s>=  -5.308627469135802500000000000000e-1
  s1=  -2.123450987654321000000000000000e+0
*/
