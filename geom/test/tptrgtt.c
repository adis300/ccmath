/*  tptrgtt.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  trgsas  trgasa  trgsss  trgarea

    input file:  tptrg.dat
*/
#include "ccmath.h"
double rad=1.7453292519943296e-2;
void main(int na,char **av)
{ double a,b,c,aa,bb,cc,ar,ang[3];
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
    aa=ang[0]/rad; b=bb=ang[1]; cc=ang[2]/rad;
    printf(" asa_out: %f %f %f\n",aa,bb,cc);
    aa*=rad; cc*=rad;
    trgasa(aa,bb,cc,ang);
    aa=ang[0]; bb=ang[1]/rad; cc=ang[2];
    printf(" sas_out: %f %f %f\n",aa,bb,cc);
    ar=trgarea(aa,b,cc);
    printf(" area= %f\n",ar);
    trgsss(aa,b,cc,ang);
    aa=ang[0]/rad; bb=ang[1]/rad; cc=ang[2]/rad;
    printf(" ang_out: %f %f %f\n",aa,bb,cc);
    ++n;
   }
}
/* Test output

 n=1
  sas_in: 2.000000 38.000000 4.000000
 asa_out: 26.929477 2.718792 115.070523
 sas_out: 2.000000 38.000000 4.000000
 area= 2.462646
 ang_out: 26.929477 38.000000 115.070523
 n=2
  sas_in: 1.000000 150.000000 1.800000
 asa_out: 10.622152 2.712506 19.377848
 sas_out: 1.000000 150.000000 1.800000
 area= 0.450000
 ang_out: 10.622152 150.000000 19.377848
*/
