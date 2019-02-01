/*  drbes.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
double drbes(double x,double v,int f,double *p)
{ double y,jbes(double u,double s),nbes(double u,double s);
  double ibes(double u,double s),kbes(double u,double s);
  if(x==0.){
    switch(f){
      case 'j':
      case 'i': if(v==1.) return .5;
                if(v==0. || v>1.) return 0.;
      default : break;  }
    return HUGE_VAL;
   }
  if(p!=0L) y= *p*v/x; else y=0.;
  switch(f){
    case 'j': if(p==0L && v>0.) y=jbes(v,x)*v/x;
              return y-jbes(v+1.,x);
    case 'y': if(p==0L && v>0.) y=nbes(v,x)*v/x;
              return y-nbes(v+1.,x);
    case 'i': if(p==0L && v>0.) y=ibes(v,x)*v/x;
              return y+ibes(v+1.,x);
    case 'k': if(p==0L && v>0.) y=kbes(v,x)*v/x;
              return y-kbes(v+1.,x);
   } return 0.;
}
