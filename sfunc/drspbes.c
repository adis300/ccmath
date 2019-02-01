/*  drspbes.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#ifndef NULL
#define NULL ((void *)0)
#endif
#include <math.h>
double drspbes(double x,int n,int f,double *p)
{ double y;
  double jspbes(int m,double a),yspbes(int m,double a);
  double kspbes(int m,double a);
  if(x==0.){
    if(f=='j'){ if(n==1) return 1./3.; else return 0.;}
    return HUGE_VAL;
   }
  if(p!=NULL) y= *p*n/x; else y=0.;
  switch(f){
    case 'j': if(p==NULL && n) y=jspbes(n,x)*n/x;
              return y-jspbes(++n,x);
    case 'y': if(p==NULL && n) y=yspbes(n,x)*n/x;
              return y-yspbes(++n,x);
    case 'k': if(p==NULL && n) y=kspbes(n,x)*n/x;
              y-=kspbes(++n,x);
              if(x>0.) return y; else return -y;
   }
  return 0.;
}
