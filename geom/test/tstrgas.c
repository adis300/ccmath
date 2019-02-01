/*  tstrgas.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  stgsas  stgasa

    input file:  tstrg.dat
*/
#include "ccmath.h"
double rad=1.7453292519943296e-2;
void main(int na,char **av)
{ double a,b,c,aa,bb,cc,ang[3];
  int n;
  FILE *fp;
  if(na!=2){ printf("para: in_file\n"); exit(-1);}
  fp=fopen(*++av,"r");
  n=1;
  while(fscanf(fp,"%lf %lf %lf",&a,&b,&c)!=EOF){
    printf(" n=%d\n",n);
    printf("  sas_in: %f %f %f\n",a,b,c);
    a*=rad; b*=rad; c*=rad;
    stgsas(a,b,c,ang);
    aa=ang[0]/rad; bb=ang[1]/rad; cc=ang[2]/rad;
    printf(" asa_out: %f %f %f\n",aa,bb,cc);
    aa*=rad; bb*=rad; cc*=rad;
    stgasa(aa,bb,cc,ang);
    aa=ang[0]/rad; bb=ang[1]/rad; cc=ang[2]/rad;
    printf(" sas_out: %f %f %f\n",aa,bb,cc);
    ++n;
   }
}
/* Test output

 n=1
  sas_in: 20.000000 32.000000 70.000000
 asa_out: 13.019714 53.562098 141.759115
 sas_out: 20.000000 32.000000 70.000000
 n=2
  sas_in: 120.000000 125.000000 65.000000
 asa_out: 108.924709 131.414448 81.868229
 sas_out: 120.000000 125.000000 65.000000
*/
