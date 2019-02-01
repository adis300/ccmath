/*  cspl.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
#include <stdlib.h>
void cspl(double *x,double *y,double *z,int m,double tn)
{ double h,s,t,*pa,*pb,*a,*b; int j;
  if(tn==0.) tn=2.;
  else{ h=sinh(tn); tn=(tn*cosh(tn)-h)/(h-tn);}
  pa=(double *)calloc(2*m,sizeof(double)); pb=pa+m;
  h=x[1]-x[0]; t=(y[1]-y[0])/h;
  for(j=1,a=pa,b=pb; j<m ;++j){
    *a++ =tn*((*b=x[j+1]-x[j])+h); h= *b++;
    z[j]=(s=(y[j+1]-y[j])/h)-t; t=s;
   }
  for(j=2,a=pa,b=pb; j<m ;++j){ h= *b/ *a;
    *++a-=h* *b++; z[j]-=h*z[j-1]; }
  z[0]=z[m]=0.;
  for(j=m-1; j>0 ;--j){ z[j]-= *b-- *z[j+1]; z[j]/= *a--;}
  free(pa);
}
