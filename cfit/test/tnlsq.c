/*  tnlsq.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  seqlsq  gnlsq      non-linear least squares estimation
    Uses:  fmatprt

    The user is prompted for initial estimates of the fit function
    parameters, and for control of the estimation mode used at each
    step. To deliver output to a named file, use: 'tnlsq file'.
*/
#include "ccmath.h"
/* define number of data points and parameters */
#define ND 50
#define NP 4
/* set number of points and parameters */
int n=ND,np=NP;
/* true parameter values */
double parm[]={2.,-1.,1.5,2.};
char fnc[]="(p0+p1*x)/(1+p2*x+p3*x^2)";
FILE *fp;
void main(int na,char **av)
{ double de,z,dz,*p;
/* arrays used by estimation functions */
  double x[ND],y[ND],var[NP*NP];
  double ssq,fit(double u,double *v);
  int j; char fl[4];
  if(na==2) fp=fopen(*++av,"w");
  else fp=stdout;
  fprintf(fp,"     Test of Nonlinear Least Squares\n");
  fprintf(fp,"  fit  f(x) = %s\n\n",fnc);
/* load input arrays with values corresponding to
   the true function parameters
*/
  for(j=0,z=0.,dz=.1; j<n ;++j){
    x[j]=z; y[j]=fit(z,parm); z+=dz; }
/* loop prompts for initial parameter estimates */
  for(j=0,p=parm; j<np ;){
    fprintf(stderr,"input param %d ",j++); scanf("%lf",p++);
   }
  fprintf(fp," initial parameters:\n");
  fmatprt(fp,parm,1,np," %.3f");
  for(de=.02,j=0;;++j){
/* estimation calls */
    if(!j || *fl=='s') ssq=seqlsq(x,y,n,parm,var,np,de,fit,j);
    else ssq=gnlsq(x,y,n,parm,var,np,de,fit);

    fprintf(fp,"\n step %d  ssq= %18.12f  ",j+1,ssq);
    if(fp!=stdout) fprintf(stderr," step %d  ssq= %e  %s\n",j+1,ssq,fl);
    if(*fl!='g') fprintf(fp,"sequential\n");
    else fprintf(fp,"gauss-newton\n");
    fprintf(fp," estimated parameters:\n");
    fmatprt(fp,parm,1,np," %f");
/* prompt for mode of next estimation step
   s -> sequential  g -> batch (gauss-newton)  e -> quit
*/
    fprintf(stderr," continue ? (s,g,e) "); scanf("%s",fl);
    if(*fl=='e') break;
   }
  fprintf(fp,"\n variance matrix:\n");
  fmatprt(fp,var,np,np," %8.5f");
}
/*
   The fit function is defined by the following code. It can be altered
   to try new types of functions.
*/
double fit(double x,double *parm)
{ return (parm[0]+x*parm[1])/(1.+x*(parm[2]+parm[3]*x));
}
/* Test output

     Test of Nonlinear Least Squares
  fit  f(x) = (p0+p1*x)/(1+p2*x+p3*x^2)

 initial parameters:
 1.000 0.500 0.000 1.000

 step 1  ssq=     2.761830601907  sequential
 estimated parameters:
 1.359847 -0.411474 0.252327 1.319671

 step 2  ssq=     0.731939569820  sequential
 estimated parameters:
 1.496193 -0.601728 0.352518 1.367757

 step 3  ssq=     0.440116200041  sequential
 estimated parameters:
 1.570087 -0.688781 0.433709 1.405312

 step 4  ssq=     0.319958479902  sequential
 estimated parameters:
 1.619204 -0.739655 0.501845 1.437881

 step 5  ssq=     0.263466800420  gauss-newton
 estimated parameters:
 1.988244 -0.953015 1.536444 1.693967

 step 6  ssq=     0.004883788924  sequential
 estimated parameters:
 1.991860 -0.967221 1.531370 1.766035

 step 7  ssq=     0.002722220022  sequential
 estimated parameters:
 1.993675 -0.974577 1.526844 1.809617

 step 8  ssq=     0.002078264568  gauss-newton
 estimated parameters:
 2.000133 -0.999085 1.503270 1.992969

 step 9  ssq=     0.000001123347  sequential
 estimated parameters:
 2.000064 -0.999520 1.501720 1.996226

 step 10  ssq=     0.000000392910  sequential
 estimated parameters:
 2.000042 -0.999675 1.501166 1.997422

 step 11  ssq=     0.000000256889  gauss-newton
 estimated parameters:
 2.000000 -0.999999 1.499992 2.000015

 step 12  ssq=     0.000000000003  sequential
 estimated parameters:
 2.000000 -1.000000 1.499996 2.000007

 variance matrix:
  0.43228 -0.15611  1.65350 -0.68475
 -0.15611  0.63871  0.21467  0.19490
  1.65350  0.21467 15.01107 -14.38497
 -0.68475  0.19490 -14.38497 29.33553
*/
