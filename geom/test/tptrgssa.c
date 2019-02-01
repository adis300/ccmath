/*  tptrgssa.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Tests:  trgssa
    Uses:   trgsas

    input file:  tptrg2.dat
*/
#include "ccmath.h"
double rad=1.7453292519943296e-2;
void main(int na,char **av)
{ double a,b,c,aa,bb,cc,ang[6];
  int n;
  FILE *fp;
  if(na!=2){ printf("para: in_file\n"); exit(-1);}
  fp=fopen(*++av,"r");
  n=1;
  while(fscanf(fp,"%lf %lf %lf",&a,&b,&c)!=EOF){
    printf(" n=%d\n",n);
    printf("  sas_in: %f %f %f\n",a,b,c);
    b*=rad;
    trgsas(a,b,c,ang);
    aa=ang[0]/rad; bb=ang[1]; cc=ang[2]/rad;
    printf(" asa_out: %f %f %f\n",aa,bb,cc);
    printf(" ssa_in : %f %f %f\n",a,bb,b/rad);
    if(trgssa(a,bb,b,ang)) printf(" no solution\n");
    else{
      printf(" sol-1:\n");
      printf("      %f %f %f\n",ang[0],ang[1]/rad,ang[2]/rad);
      printf(" sol-2:\n");
      printf("      %f %f %f\n",ang[3],ang[4]/rad,ang[5]/rad);
     }
    ++n;
   }
}
/* Test output
 n=1
  sas_in: 2.000000 38.000000 2.000000
 asa_out: 71.000000 1.302273 71.000000
 ssa_in : 2.000000 1.302273 38.000000
 sol-1:
      2.000000 71.000000 71.000000
 sol-2:
      1.152043 33.000000 109.000000
 n=2
  sas_in: 1.000000 150.000000 1.800000
 asa_out: 10.622152 2.712506 19.377848
 ssa_in : 1.000000 2.712506 150.000000
 sol-1:
      1.800000 19.377848 10.622152
 sol-2:
      0.000000 0.000000 0.000000
*/
