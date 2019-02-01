/*  tsolnl.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  solnl
*/
#include "ccmath.h"
#define NN 3
void main(void)
{ double x[NN],f[NN],(*fv[NN])(),test=1.e-28;
  double fa(double *x),fb(double *x),fc(double *);
  int i,m;
  fv[0]=fa; fv[1]=fb; fv[2]=fc;
  printf("     Test of Nonlinear System Solver\n");
  fprintf(stderr," enter initial x-vector (%d components)\n",NN);
  for(i=0; i<NN ;) scanf("%lf",x+i++);
  printf(" initial vector:\n");
  for(i=0; i<NN ;) printf(" %f",x[i++]); printf("\n");
  m=solnl(x,f,fv,NN,test);
  printf(" solution status = %d\n",m);
  printf(" solution vector:\n");
  for(i=0; i<NN ;) printf(" %f",x[i++]); printf("\n");
  printf("    final function values:\n");
  for(i=0; i<NN ;++i) printf("  %d  %9.4e\n",i+1,f[i]);
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

     Test of Nonlinear System Solver
 initial vector:
 1.000000 0.000000 1.000000
 solution status = 1
 solution vector:
 0.000000 1.414214 6.000000
    final function values:
  1  1.8028e-15
  2  1.7894e-15
  3  -2.4158e-15
*/
