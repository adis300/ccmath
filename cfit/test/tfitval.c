/*  tfitval.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  fitval  setfval

    Variance matrix array for 3-parameter test function 'frat'.
*/    
double v[]={1.2e-2,2.1e-3,4.0e-3,2.1e-3,5.3e-3,
 9.0e-4,4.0e-3,9.0e-4,8.5e-3};
/*
    Test function 'frat' used in variance analysis test.
*/    
double frat(double x,double *p)
{ return p[0]*x/(p[1]+p[2]*x*x);
}

#include "ccmath.h"
void main(void)
{ double par[3],f,s,x,dx;
  int i,n,m;
  printf("     Test of Fit-Confidence Bound\n");
  m=3;
  par[0]=2.; par[1]=1.; par[2]=.5;
  setfval(0,m);
  x=0.2; dx=.2; n=20;
  printf("    x      value           sigma\n");
  for(i=0; i<n ;++i,x+=dx){
    f=fitval(x,&s,par,frat,v,m);
    printf(" %6.2f  %12.8f   %9.4f\n",x,f,s);
   }
}
/* Test output

     Test of Fit-Confidence Bound
    x      value           sigma
   0.20    0.39215686      0.0303
   0.40    0.74074074      0.0546
   0.60    1.01694915      0.0724
   0.80    1.21212121      0.0872
   1.00    1.33333333      0.1021
   1.20    1.39534884      0.1172
   1.40    1.41414141      0.1308
   1.60    1.40350877      0.1418
   1.80    1.37404580      0.1497
   2.00    1.33333333      0.1547
   2.20    1.28654971      0.1573
   2.40    1.23711340      0.1579
   2.60    1.18721461      0.1571
   2.80    1.13821138      0.1552
   3.00    1.09090909      0.1525
   3.20    1.04575163      0.1493
   3.40    1.00294985      0.1459
   3.60    0.96256684      0.1422
   3.80    0.92457421      0.1384
   4.00    0.88888889      0.1346
*/
