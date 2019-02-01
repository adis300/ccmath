/*  chintg.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
#include <stdlib.h>
double chintg(double *a,int m,double (*func)())
{ double f,t,tf,aj,adel,*pf,*pe,*p,*ps;
  int j;
  pf=(double *)calloc(2*m,sizeof(double)); pe=pf+m;
  ++m; adel=3.1415926535897932/m;
  for(p=pf,ps=pe,j=1,aj=adel; p<pe ;aj+=adel){
    t=cos(aj); a[j++]=f=sin(aj);
    *ps++ =2.*t; *p++ =(*func)(t)*f;
   }
  for(j=m-1,ps=pe+m-2; j>0 ;--ps,--j){
    for(p=pe-1,t=tf=0.; p>=pf ;){ f= *ps*t-tf+ *p--; tf=t; t=f;}
    a[j]*=t*2./(j*m);
   }
  for(j=1,a[0]=0.; j<m ;++j){
    if(j%2==0) a[0]-=a[j]; else a[0]+=a[j]; }
  for(j=m-1,f=0.; j>m-4 ;--j) if((t=fabs(a[j]))>f) f=t;
  free(pf); return f;
}
