/*  fitval.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
#include <stdlib.h>
static double *h,dl=1.e-8;
double fitval(double x,double *s,double *par,double (*fun)(),
	  double *v,int n)
{ double f,r,d; int i,j;
  f=(*fun)(x,par);
  for(i=0; i<n ;++i){
    par[i]+=dl; h[i]=((*fun)(x,par)-f)/dl;
    par[i]-=dl;
   }
  for(i=0,r=0.; i<n ;){
    for(j=0,d=0.; j<n ;) d+= *v++ *h[j++];
    r+=d*h[i++];
   }
  *s=sqrt(r); return f;
}
void setfval(int i,int n)
{ if(i==0) h=(double *)calloc(n,sizeof(*h));
  else free(h);
}
