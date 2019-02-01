/*  csplp.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
#include <stdlib.h>
void csplp(double *x,double *y,double *z,int m,double tn)
{ double h,s,t,u,*pa,*pb,*pc,*a,*b,*c;
  int j;
  if(tn==0.) tn=2.;
  else{ h=sinh(tn); tn=(tn*cosh(tn)-h)/(h-tn);}
  pa=(double *)calloc(3*m,sizeof(double)); pb=pa+m; pc=pb+m;
  *pc=h=x[1]-x[0]; t=u=(y[1]-y[0])/h;
  for(j=1,a=pa,b=pb; j<m ;++j){
    *a++ =tn*((*b=x[j+1]-x[j])+h); h= *b++;
    z[j]=(s=(y[j+1]-y[j])/h)-t; t=s;
   }
  z[m]=u-t; u= *pc; *a=(u+h)*tn;
  for(j=1,a=pa,b=pb,c=pc; j<m ;++j){ h= *b/ *a;
    *++a-=h* *b++; z[j+1]-=h*z[j]; s= *c++; *c= -s*h;
    }
  z[m-1]/= *--a; *--c+= *--b; *c/= *a--;
  for(j=m-2; j>0 ;--j){ h= *--b; s= *c--;
    z[j]-=h*z[j+1]; z[j]/= *a; *c-=h*s; *c/= *a--; }
  z[m]-=u*z[1]; s= *(pb-1)+ *(pc+m-1)-u* *pc;
  h=z[0]=(z[m]/=s);
  for(j=1,c=pc; j<m ;) z[j++]-= *c++ *h;
  free(pa);
}
