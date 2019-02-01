/*  txprcmp.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  xprcmp

    Uses:  atox  prxpr

    Input file:  data/xcmp.dat
*/
#define XMATH 1
#include "ccmath.h"
int decd=30;
void main(int na,char **av)
{ struct xpr s,t; int c;
  char nbx[64],nby[64];
  FILE *fp;
  if(na!=2){ printf("para: input_file\n"); exit(-1);}
  fp=fopen(*++av,"r");
  printf("     Test of Extended Precision Comparison\n");
  while(fscanf(fp,"%s %s",nbx,nby)!=EOF){
    s=atox(nbx); t=atox(nby);
    printf(" x= "); prxpr(s,decd);
    printf(" y= "); prxpr(t,decd);

    printf("compare x and y\n");

/* extended precision comparison */
    c=xprcmp(&s,&t);

    if(c==1) printf(" x > y\n");
    else if(c== -1) printf(" x < y\n");
    else printf(" x = y\n");
   }
}
/*  Test output

     Test of Extended Precision Comparison
 x=   1.250000000000000000000000000000e+0
 y=   2.730000000000000000000000000000e+1
compare x and y
 x < y
 x=  -1.210000000000000000000000000000e-1
 y=   5.431000000000000000000000000000e-2
compare x and y
 x < y
 x=   1.110000000000000000000000000000e+1
 y=  -2.765400000000000000000000000000e+1
compare x and y
 x > y
 x=  -1.030000000000000000000000000000e-3
 y=  -1.030000000000000000000000000000e-3
compare x and y
 x = y
*/
