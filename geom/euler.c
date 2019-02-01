/*  euler.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
void euler(double *pv,int m,double a,double b,double c)
{ double t,cn,sn,*p,*q; int j,k;
  for(k=0; k<3 ;++k){
    switch(k){
       case 0: cn=cos(c); sn=sin(c); p=pv; q=p+1; break;
       case 1: cn=cos(b); sn= -sin(b); p=pv; q=p+2; break;
       case 2: cn=cos(a); sn=sin(a); p=pv; q=p+1;
     }
    for(j=0; j<m ;++j,p+=3,q+=3){
      t=cn* *p-sn* *q; *q=cn* *q+sn* *p; *p=t; }
   }
}
