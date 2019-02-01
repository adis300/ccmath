/*  theta.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
static double q,qq,kf;
double theta(double u,int n)
{ double c,s,c0,s0,f,r,z;
  u*=kf; c0=cos(2.*u); s0=sin(2.*u);
  switch(n){
    case 0:
    case 3: f=1.; r=2.*q; z=q;
            c=c0; s=s0; break;
    case 1:
    case 2: f=0.; r=2.*pow(q,.25); z=1.;
            c=cos(u); s=sin(u);
   }
  if(n==0){ r= -r; z= -z;} if(n==1) z= -z;
  while(fabs(r)>1.e-16){
    if(n==1) f+=r*s; else f+=r*c;
    u=c*c0-s*s0; s=s*c0+c*s0; c=u;
    z*=qq; r*=z;
   }
  return f;
}
void stheta(double k)
{ double nome(double k,double *pk,double *pkp);
  double pi2=1.57079632679490;
  q=nome(k,&kf,&qq); qq=q*q; kf=pi2/kf;
}
