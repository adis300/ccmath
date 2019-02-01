/*  tctrig.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  csin  casin
           ccos  cacos
	   ctan  catan

    interactive input with 'tctrig'	   
    input from file with 'tctrig data/ctrg.dat'
*/
#include "ccmath.h"
void main(int na,char **av)
{ Cpx z,s,c,t,u; FILE *fp;
  if(na>1) fp=fopen(*++av,"r");
  while(1){
    if(na==1){ printf(" z? ");     /* enter Ctrl-Z to terminate */    
      if(scanf("%lf %lf",&z.re,&z.im)==EOF) break;
     }
    else{
      if(fscanf(fp,"%lf %lf",&z.re,&z.im)==EOF) break;
      printf(" z= (%f, %f)\n",z.re,z.im);
     }
    s=csin(z); c=ccos(z); t=ctan(z);
    printf("  sin= (%f, %f)\n",s.re,s.im); u=casin(s);
    printf(" asin= (%f, %f)\n",u.re,u.im);
    printf("  cos= (%f, %f)\n",c.re,c.im); u=cacos(c);
    printf(" acos= (%f, %f)\n",u.re,u.im);
    printf("  tan= (%f, %f)\n",t.re,t.im); u=catan(t);
    printf(" atan= (%f, %f)\n",u.re,u.im);
   }
}
/* Test output

 z= (1.000000, 1.000000)
  sin= (1.298458, 0.634964)
 asin= (1.000000, 1.000000)
  cos= (0.833730, -0.988898)
 acos= (1.000000, 1.000000)
  tan= (0.271753, 1.083923)
 atan= (1.000000, 1.000000)
 z= (-1.000000, 2.000000)
  sin= (-3.165779, 1.959601)
 asin= (-1.000000, 2.000000)
  cos= (2.032723, 3.051898)
 acos= (1.000000, -2.000000)
  tan= (-0.033813, 1.014794)
 atan= (-1.000000, 2.000000)
 z= (-2.000000, 3.000000)
  sin= (-9.154499, -4.168907)
 asin= (-1.141593, -3.000000)
  cos= (-4.189626, 9.109228)
 acos= (2.000000, -3.000000)
  tan= (0.003764, 1.003239)
 atan= (1.141593, 3.000000)
 z= (-0.800000, -1.200000)
  sin= (-1.298885, -1.051652)
 asin= (-0.800000, -1.200000)
  cos= (1.261496, -1.082821)
 acos= (0.800000, 1.200000)
  tan= (-0.180828, -0.988871)
 atan= (-0.800000, -1.200000)
*/
