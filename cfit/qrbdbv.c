/*  qrbdbv.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
int qrbdbv(double *d,double *e,double *b,double *v,int n)
{ int i,j,k,nn,jj,nm;
  double u,x,y,f,g,c,s,t,w,*p,*q;
  for(j=1,t=fabs(d[0]); j<n ;++j)
    if((s=fabs(d[j])+fabs(e[j-1]))>t) t=s;
  t*=1.e-15; nn=100*n; nm=n;
  for(j=0; n>1 && j<nn ;++j){
    for(k=n-1; k>0 ;--k){
      if(fabs(e[k-1])<t) break;
      if(fabs(d[k-1])<t){
        for(i=k,s=1.,c=0.; i<n ;++i){
          f=s*e[i-1]; g=d[i]; e[i-1]*=c;
          d[i]=u=sqrt(f*f+g*g); s= -f/u; c=g/u;
          p=b+k-1; q=b+i;
          w=c* *p+s* *q; *q=c* *q-s* *p; *p=w;
	 }
        break;
       }
     }
    y=d[k]; x=d[n-1]; u=e[n-2];
    f=(y+x)*(y-x)-u*u; s=y*e[k]; g=s+s;
    u=sqrt(f*f+g*g);
    c=sqrt((u+f)/(u+u)); s/=(c*u);
    for(i=k; i<n-1 ;++i){
      g=e[i];
      if(i>k){
	f=s*e[i]; g*=c;
	e[i-1]=u=sqrt(x*x+f*f);
	c=x/u; s=f/u;
       }
      f=c*y+s*g; g=c*g-s*y;
      for(jj=0,p=v+i; jj<nm ;++jj,p+=nm){
        q=p+1;
        w=c* *p+s* *q; *q=c* *q-s* *p; *p=w;
       }
      s*=d[i+1]; d[i]=u=sqrt(f*f+s*s);
      y=c*d[i+1]; c=f/u; s/=u;
      x=c*g+s*y; y=c*y-s*g;
      p=b+i; q=p+1;
      w=c* *p+s* *q; *q=c* *q-s* *p; *p=w;
     }
    e[n-2]=x; d[n-1]=y;
    if(fabs(x)<t) --n;
    if(n==k+1) --n; 
   }
  return j;
}
