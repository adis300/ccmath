/*  tcarop2.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  cdef  crmu  cimu  ccng  cnrm  cabs

    Input file:  caop2.dat
*/
#include "ccmath.h"
char cfmt[]="(%10.6f,%10.6f)\n";
void main(int na,char **av)
{ Cpx z; double x,y,ar,ai;
  FILE *fp;
  if(na!=2){ printf("para: input_file\n"); exit(-1);}
  fp=fopen(*++av,"r");
  printf("     Test of Operations on Complex Numbers\n");
  while(fscanf(fp,"%lf %lf",&ar,&ai)!=EOF){
    x=.5; y=2.;

/* define complex number */
    z=cdef(ar,ai);
    printf("def: z= "); printf(cfmt,z.re,z.im);
/* multiply by a real nmmber */
    z=crmu(x,z);
    printf("real * "); printf(cfmt,z.re,z.im);
/* multiply by an integer */
    z=cimu(y,z);
    printf("imag * "); printf(cfmt,z.re,z.im);
/* complex conjugate */
    z=ccng(z);
    printf("ccng(z) "); printf(cfmt,z.re,z.im);
/* norm |z|^2 */
    x=cnrm(z);
    printf("norm(z)= %f  ",x);
/* absolute value |z| */  
    x=cabs(z);
    printf("abs(z)= %f\n",x);
   }
}
/* Test output

     Test of Operations on Complex Numbers
def: z= (  2.000000,  3.000000)
real * (  1.000000,  1.500000)
imag * ( -3.000000,  2.000000)
ccng(z) ( -3.000000, -2.000000)
norm(z)= 13.000000  abs(z)= 3.605551
def: z= (  1.500000, -4.300000)
real * (  0.750000, -2.150000)
imag * (  4.300000,  1.500000)
ccng(z) (  4.300000, -1.500000)
norm(z)= 20.740000  abs(z)= 4.554119
def: z= ( -1.200000,  5.300000)
real * ( -0.600000,  2.650000)
imag * ( -5.300000, -1.200000)
ccng(z) ( -5.300000,  1.200000)
norm(z)= 29.530000  abs(z)= 5.434151
def: z= ( -2.100000, -1.000000)
real * ( -1.050000, -0.500000)
imag * (  1.000000, -2.100000)
ccng(z) (  1.000000,  2.100000)
norm(z)= 5.410000  abs(z)= 2.325941
*/
