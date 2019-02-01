/*  seqlsq.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
#include <stdlib.h>
double seqlsq(double *x,double *y,int n,double *par,double *var,int m,
		double de,double (*func)(),int kf)
{ double *pd,*pc,*pmax,*p,*q,*r,*s,*t;
  double err,ssq,f,z; int j;
  pd=(double *)calloc(2*m,sizeof(double)); pc=pd+m;
  if(kf==0){ for(p=var,pmax=p+m*m; p<pmax ;) *p++ =0.;
    for(p=var; p<pmax ;p+=m+1) *p=1.; }
  for(j=0,ssq=0.,pmax=pc+m; j<n ;++j){ z=x[j];
    f=(*func)(z,par); err=y[j]-f; ssq+=err*err;
    for(p=pd,q=par; p<pc ;){ *q+=de;
      *p++ =((*func)(z,par)-f)/de; *q++ -=de;
     }
    for(p=pc,q=pd,r=var,z=1.; p<pmax ;){ *p=0.;
      for(s=pd; s<pc ;) *p+= *r++ * *s++;
      z+= *p++ * *q++;
     }
    z=sqrt(z); err/=z;
    for(p=pc,q=par; p<pmax ;) *q++ += err*(*p++ /=z);
    for(p=pc,t=var; p<pmax ;++p,t+=m+1)
      for(q=p,r=s=t; q<pmax ;r+=m) *r=(*s++ -= *p* *q++);
   }
  free(pd); return ssq;
}
