/*  timbes.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Time execution of Bessel function evaluation.

    Input parameter:  n -> evaluation on n by n grid (n^2 evaluations)
*/
#include <math.h>
#include <time.h>
#include "ccmath.h"
void main(int na,char **av)
{ double x,v,f,dx,dv,*s,*p;
  int i,j,n; clock_t st,en;
  if(na!=2){ printf("para: loop_sz\n"); exit(1);}
  n=atoi(*++av);
  printf(" %d evaluations of Jbessel\n",n*n);
  st=clock();
  dx=20./n; dv=10./n;
  for(i=0,x=0.,p=s; i<n ;++i,x+=dx){
    for(j=0,v=0.; j<n ;++j,v+=dv){
      f=jbes(v,x);
     }
   }
  en=clock();
  printf(" time = %.2f sec.\n",(v=(en-st)/(double)CLOCKS_PER_SEC));
  v*=1.e6/(n*n);
  printf(" %.2e microsec. per evaluation\n",v);
  printf(" final Jb= %.9e\n",f);
}
