/*  txconv.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  dubtox  xtodub  inttox

    Uses:  prxpr

    Input file:  xcvt.dat
*/
#define XMATH 1
#include "ccmath.h"
int decd=30;
void main(int na,char **av)
{ char f[4]; double x,z; int k;
  struct xpr s;
  FILE *fp;
  if(na!=2){ printf("para: input_file\n"); exit(-1);}
  fp=fopen(*++av,"r");
  printf("     Test of Conversion Functions\n");
  while(fscanf(fp,"%s",f)!=EOF){
    switch(*f){

/* convert between double and extended precision */
      case 'd': fscanf(fp,"%lf",&x); s=dubtox(x); z=xtodub(s);
		printf(" in: x= %.15e  out: z= %.15e\n",x,z);
		prxpr(s,decd);
		break;

/* convert integer to extended precision */
      case 'i': fscanf(fp,"%d",&k); s=inttox(k);
		printf(" k= %d\n",k);
		prxpr(s,decd);
		break;
     }
   }
}
/*  Test output

     Test of Conversion Functions
 in: x= 1.375000000000000e+00  out: z= 1.375000000000000e+00
  1.375000000000000000000000000000e+0
 in: x= 1.570796326794897e+00  out: z= 1.570796326794897e+00
  1.570796326794896557998981734272e+0
 in: x= 2.000000000000000e+00  out: z= 2.000000000000000e+00
  2.000000000000000000000000000000e+0
 in: x= 1.537000000000000e+25  out: z= 1.537000000000000e+25
  1.536999999999999915694489600000e+25
 k= 1
  1.000000000000000000000000000000e+0
 k= 123
  1.230000000000000000000000000000e+2
 k= 214675321
  2.146753210000000000000000000000e+8
*/
