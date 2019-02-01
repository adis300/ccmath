/*  timnrml.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Time the generation of pseudorandom normals

    Input parameter:  n -> number of normals generated
*/
#include <time.h>
#include "ccmath.h"
void main(int na,char **av)
{ unsigned int i,n; double x;
  clock_t st,en; double dt;
  if(na!=2){ printf("para: count\n"); exit(1);}
  n=atoi(*++av);
  i=123456789; setnrml(i);
  printf("    Timing Random Normal Generator nrml()\n");
  printf("  number generated= %ld\n",n);
  st=clock();
  for(i=0; i<n ;++i) x=nrml();
  en=clock();
  dt=(double)(en-st)/(double)CLOCKS_PER_SEC;
  printf(" time= %7.3f sec.\n",dt);
  dt*=1.e6/(double)n;
  printf("   %6.3f usec. per evaluation\n",dt); 
}
