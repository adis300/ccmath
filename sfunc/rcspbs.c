/*  rcspbs.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
static double f,h,v,x;
static int d,ty;
double rcspbs(void)
{ double t;
  if(d=='u'){
    switch(ty){
      case 'j':
      case 'y': t=f*v/x-h; break;
      case 'k': t=h+f*v/x; break;
     }
    h=f; f=t; v+=1.;
   }
  else{
    switch(ty){
      case 'j':
      case 'y': t=h*v/x-f; break;
      case 'k': t=f-h*v/x; break;
     }
    f=h; h=t; v-=1.;
   }
  return t;
}
setrcsb(int n,double y,int fl,int dr,double *pf,double *ph)
{ double jspbes(int i,double a),yspbes(int i,double a);
  double kspbes(int i,double a);
  if(dr=='d') --n;
  switch(fl){
    case 'j': h=jspbes(n,y); f=jspbes(n+1,y); break;
    case 'y': h=yspbes(n,y); f=yspbes(n+1,y); break;
    case 'k': h=kspbes(n,y); f=kspbes(n+1,y); break;
   }
  x=y/2.; ty=fl; d=dr;
  if(dr=='u'){ v=n+1.5; *pf=h; *ph=f;}
  else{ v=n+.5; *pf=f; *ph=h;}
}
