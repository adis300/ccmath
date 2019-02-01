/*  rcbes.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
static double f,h,v,x;
static int d,ty;
double rcbes(void)
{ double t;
  if(d=='u'){
    switch(ty){
      case 'j':
      case 'y': t=f*v/x-h; break;
      case 'i': t=h-f*v/x; break;
      case 'k': t=h+f*v/x; break; }
    h=f; f=t; v+=1.;
   }
  else{
    switch(ty){
      case 'j':
      case 'y': t=h*v/x-f; break;
      case 'i': t=f+h*v/x; break;
      case 'k': t=f-h*v/x; break; }
    f=h; h=t; v-=1.;
   }
  return t;
}
void setrcb(double u,double y,int fl,int dr,double *pf,double *ph)
{ double jbes(double u,double x),ibes(double u,double x);
  double nbes(double u,double x),kbes(double u,double x);
  if(dr=='d') u-=1.;
  switch(fl){
    case 'j': h=jbes(u,y); f=jbes(u+1.,y); break;
    case 'y': h=nbes(u,y); f=nbes(u+1.,y); break;
    case 'i': h=ibes(u,y); f=ibes(u+1.,y); break;
    case 'k': h=kbes(u,y); f=kbes(u+1.,y); break;
   }
  x=y/2.; ty=fl; d=dr;
  if(dr=='u'){ v=u+1.; *pf=h; *ph=f;}
  else{ v=u; *pf=f; *ph=h;}
}
