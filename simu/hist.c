/*  hist.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <stdlib.h>
int *hist(double *x,int n,double xmin,double xmax,int kbin,double *bin)
{ int k,*p; double *pm,u;
  p=(int *)calloc(kbin+2,sizeof(int)); ++p;
  *bin=(xmax-xmin)/kbin;
  for(pm=x+n; x<pm ;++x){
    if(*x > xmax) k=kbin;
    else if ((u=(*x-xmin))<0.) k= -1;
    else k=u / *bin;
    *(p+k)+=1;
   }
  return p;
}
