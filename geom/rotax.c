/*  rotax.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
static void strig(double *p,double a,double b,double c);
void rotax(double *v,double az,double pa,double ang,int k)
{ static double ca,sa,cb,sb,cn,sn;
  double a[3],t,pi=3.14159265358979; int fg;
  if(k==0){ if(pa==0.){ ca=cb=0.; cn=ang;}
    else if(pa==pi){ ca=cb=0.; cn= -ang;}
    else{ if(ang<0.){ fg=1; ang= -ang;} else fg=0;
      strig(a,pa,ang,pa);
      if(fg==0){ ca=az-a[0]; cn=pi-az-a[0];}
      else{ a[1]= -a[1]; cn=a[0]-az; ca=az+a[0]-pi;}
     }
    sa=sin(ca); ca=cos(ca); sb=sin(a[1]); cb=cos(a[1]);
    sn=sin(cn); cn=cos(cn);
   }
  t=cn*v[0]-sn*v[1]; v[1]=cn*v[1]+sn*v[0]; v[0]=t;
  t=cb*v[0]+sb*v[2]; v[2]=cb*v[2]-sb*v[0]; v[0]=t;
  t=ca*v[0]-sa*v[1]; v[1]=ca*v[1]+sa*v[0]; v[0]=t;
}
static void strig(double *p,double a,double b,double c)
{ double as,cs,bb;
  as=sin(a); a=cos(a); cs=sin(c); c=cos(c);
  bb=c*a+cs*as*cos(b);
  if(bb>1.) bb=1.; else if(bb< -1.) bb= -1.;
  b=cs*as*sin(b);
  p[0]=atan2(b,c-a*bb);
  p[1]=acos(bb);
  p[2]=atan2(b,a-c*bb);
}
