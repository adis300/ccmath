/*  thtrgss.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test: htgsas  htgsss  htgaaa  htgarea

    input file: thtrg.dat
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
    b*=rad;
    htgsas(a,b,c,ang);
    aa=ang[0]/rad; bb=ang[1]; cc=ang[2]/rad;
    printf(" asa_out: %f %f %f\n",aa,bb,cc);
    b=ang[1];
    htgsss(a,b,c,ang);
    aa=ang[0]/rad; bb=ang[1]/rad; cc=ang[2]/rad;
    printf(" ang_out: %f %f %f\n",aa,bb,cc);
    a=ang[0]; b=ang[1]; c=ang[2];
    cc=htgarea(a,b,c);
    printf(" area= %f\n",cc);
    htgaaa(a,b,c,ang);
    aa=ang[0]; bb=ang[1]; cc=ang[2];
    printf("side_out: %f %f %f\n",aa,bb,cc);
    ++n;
   }
}
/* Test output

 n=1
  sas_in: 2.000000 40.000000 3.000000
 asa_out: 13.490245 2.997584 40.116968
 ang_out: 13.490245 40.000000 40.116968
 area= 1.507839
side_out: 2.000000 2.997584 3.000000
 n=2
  sas_in: 1.300000 135.000000 0.800000
 asa_out: 19.686630 1.983407 10.145969
 ang_out: 19.686630 135.000000 10.145969
 area= 0.264721
side_out: 1.300000 1.983407 0.800000
*/
