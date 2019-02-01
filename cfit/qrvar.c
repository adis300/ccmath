/*  qrvar.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
int ruinv(double *v,int n);
double qrvar(double *v,int m,int n,double ssq)
{ int j,k;
  double z,*p,*q,*r,*s,*t;
  if(m>n) ssq/=(double)(m-n);
  ruinv(v,n);
  for(j=0,p=v; j<n ;++j,p+=n+1){
    for(q=v+j,t=p-j; q<=p ;q+=n){
      for(k=j,r=p,s=q,z=0.; k<n ;++k) z += *r++ * *s++;
      *t++ =(*q=z);
     }
   }
  for(j=0,k=n*n,p=v; j<k ;++j) *p++ *=ssq;
  return ssq;
}


