/*  tsvalS.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*     Test for numerical instability in SVD code. The output
 *     will contain non-numeric values Inf (or possibly NaN)
 *     if the QR fix has not been installed correctly.
 *     This can be tested by piping the output into the shell
 *     command: grep -c 'Inf'.
 *
 *     input integer N = number of test cases to generate.
 *
*/
#include <time.h>
#include <stdio.h>
#include <ccmath.h>
void main(int na,char **av)
{  double d[4], a[16], u[16], v[16];
   int i,j,nn;
   unsigned int seed;
   if(na<2){ printf("para N\n"); exit(1);}
   nn=atoi(*++av);
   seed=(unsigned int)time(NULL); setunfl(seed);
   for(j=0; j<nn ;++j){
      for(i=0; i<16;++i) a[i] = 2.*unfl()-1.;
      svdval ( d, a, 4, 4 );
      printf ( "%d : %f %f %f %f\n", j, d[0], d[1], d[2], d[3] );
    }
}
