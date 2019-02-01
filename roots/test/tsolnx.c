/*  tsolnx.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  solnx
*/
#include "ccmath.h"
#define NN 3
void main(void)
{ double x[NN],f[NN],(*fv[NN])(),jm[NN*NN],test=1.e-28;
  double fa(double *x),fb(double *x),fc(double *x);
  int i,m;
  fv[0]=fa; fv[1]=fb; fv[2]=fc;
  printf("     Test of Nonlinear System Solver (X-form)\n");
  fprintf(stderr," enter initial x-vector (%d components)\n",NN);
  for(i=0; i<NN ;) scanf("%lf",x+i++);
  printf(" initial vector:\n");
  for(i=0; i<NN ;) printf(" %f",x[i++]); printf("\n");
/* starting jacobian defined here */
  for(i=0; i<NN*NN ;) jm[i++]=0.;
  for(i=0; i<NN*NN ;i+=NN+1) jm[i]=1.;
  m=solnx(x,f,fv,jm,NN,test);
  printf(" solution status = %d\n",m);
  printf(" solution vector:\n");
  for(i=0; i<NN ;) printf(" %f",x[i++]); printf("\n");
  printf("    final function values:\n");
  for(i=0; i<NN ;++i) printf("  %d  %10.4e\n",i+1,f[i]);
}
/* functions of nonlinear system */
double fa(double *x)
{ return (x[0]*x[0]+2.*x[1]*x[1]-4.);
}
double fb(double *x)
{ return (x[0]*x[0]+x[1]*x[1]+x[2]-8.);
}
double fc(double *x)
{ double a,b,c,sqrt();
  a=x[0]-1.; b=2.*x[1]-sqrt(2.); c=x[2]-5.;
  return (a*a+b*b+c*c-4.);
}
/* Test output

     Test of Nonlinear System Solver (X-form)
 initial vector:
 1.000000 1.000000 1.000000
 solution status = 1
 solution vector:
 0.000000 1.414214 6.000000
    final function values:
  1  -7.0929e-16
  2  -3.5475e-16
  3  -1.1532e-15
*/
