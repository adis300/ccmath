/*  timintg.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Time numerical integration for complete elliptic integrals.

    Input parameter:  n -> number of k values uniformly spaced
                           over interior of interval [0,1]
*/
#include <time.h>
#include <math.h>
#include "ccmath.h"
double k,fel(double x);
double Pi2=1.5707963267949966;
double te=1.e-10;
void main(int na,char **av)
{ double x0,x1,dk,dt,*val; int m,j,n;
  clock_t st,en;
  if(na!=2){ printf("para: num\n"); exit(1);}
  n=atoi(*++av);
  printf(" Timing Numerical Integration\n");
  printf("  %d complete elliptic integrals\n",n);
  val=(double *)calloc(n,sizeof(double));
  dk=1./(n+1);
  x0=0.; x1=Pi2; m=10; k=dk;
  st=clock();
  for(j=0; j<n ;++j,k+=dk) val[j]=fintg(x0,x1,m,te,fel);
  en=clock();
  dt=0.;
  dt=(double)(en-st)/(double)CLOCKS_PER_SEC;
  printf("  time= %.3f sec.\n",dt);
  dt*=1.e6/n;
  printf(" %.2e microsec. per integral\n",dt);
  printf("   final value: %15.10f\n",val[n-1]); 
}

double fel(double x)
{ double u;
  u=k*sin(x);
  return 1./sqrt(1.-u*u);
}
