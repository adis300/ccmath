/*  tgnlsq.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  gnlsq
    Uses:  matprt
*/
#include "ccmath.h"
#define ND 50
#define NP 4
/* true function parameters */
double parm[]={2.,-1.,1.5,2.};
char fnc[]="(p0+x*p1)/(1+p2*x+p3*x^2)";
void main(void)
{ double x[ND],y[ND],var[NP*NP],de,z,dz,*p;
  double ssq,fit(double u,double *v);
  int n=ND,np=NP,j;
  char fl[4];
  printf("     Test of Gauss-Newton Least Squares\n");
  printf(" f(x) = %s\n\n",fnc);
/* define the input values by using true parameters */
  for(j=0,z=0.,dz=.1; j<n ;++j){
    x[j]=z; y[j]=fit(z,parm); z+=dz; }
/* loop of prompts for initial fit function parameters */
  for(j=0,p=parm; j<np ;){
    fprintf(stderr,"input para %d ",j++); scanf("%lf",p++); }
  printf(" initial parameters:\n");
  matprt(parm,1,np," %.3f");
  for(de=.02,j=1;;++j){
    ssq=gnlsq(x,y,n,parm,var,np,de,fit);
    printf("\n step %d  ssq= %20.16f\n",j,ssq);
    printf(" estimated parameters:\n");
    matprt(parm,1,np," %f");
/* prompt for next step */
    fprintf(stderr," continue ? (y/n) "); scanf("%s",fl);
    if(*fl=='n') break;
   }
  printf("\n variance matrix:\n");
  matprt(var,np,np," %11.4f");
}
/*
 The following code defines the fit function.  Code for new functions
 can be substituted. Be sure to alter the values for number of points
 ND and parameters NP if these are different in the new function. The
 initialization of fnc should also be altered to describe the new function.
*/
double fit(double x,double *parm)
{ return (parm[0]+x*parm[1])/(1.+x*(parm[2]+parm[3]*x));
}
/* Test output

     (7 step estimation)
     (initial parameters:  1.000 0.000 0.000 1.000)

     Test of Gauss-Newton Least Squares
 f(x) = (p0+x*p1)/(1+p2*x+p3*x^2)

 initial parameters:
 1.000 0.000 0.000 1.000

 step 1  ssq=   2.9682703373514436
 estimated parameters:
 1.950656 -0.777336 2.219134 0.297415

 step 2  ssq=   0.1757230078807573
 estimated parameters:
 2.028739 -0.952354 1.979850 1.225173

 step 3  ssq=   0.0158376950406589
 estimated parameters:
 2.002749 -0.999820 1.540071 1.909456

 step 4  ssq=   0.0001586472148594
 estimated parameters:
 2.000022 -1.000069 1.500247 1.998958

 step 5  ssq=   0.0000000274843502
 estimated parameters:
 2.000000 -1.000000 1.499998 2.000006

 step 6  ssq=   0.0000000000007077
 estimated parameters:
 2.000000 -1.000000 1.500000 2.000000

 step 7  ssq=   0.0000000000000000
 estimated parameters:
 2.000000 -1.000000 1.500000 2.000000

 step 8  ssq=   0.0000000000000000
 estimated parameters:
 2.000000 -1.000000 1.500000 2.000000

 variance matrix:
      0.8646     -0.3123      3.3072     -1.3699
     -0.3123      1.2781      0.4294      0.3909
      3.3072      0.4294     30.0277    -28.7837
     -1.3699      0.3909    -28.7837     58.7157
*/
