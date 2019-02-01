/*  tunfl.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
     Test:  unfl()  setunfl()

     Input parameters:  s -> unsigned integer pseudorandom seed

                        n -> integer sample size
*/
#include <math.h>
#include "ccmath.h"
void main(int na,char **av)
{ double x,xm,ssq; unsigned int s;
  int n,i,p;
  if(na!=3){ printf("para: seed(hex) size\n"); exit(-1);}
  sscanf(*++av,"%x",&s); n=atoi(*++av);
  printf(" seed= %x\n",s);
  printf(" sample size= %d\n",n);
  if(n>1000) p=0; else p=1;
/* initialize pseudorandom uniform generator */
  setunfl(s);

  xm=ssq=0.;
  for(i=0; i<n ;++i){
 
/* generate a random number on [0,1] */
   x=unfl();

    if(p) printf(" %4d  %f\n",i,x);
    xm+=x; x-=.5; ssq+=x*x;
   }
  printf(" xmean= %e  mean-sq= %e\n",xm/n,ssq/n);
}
/* Test output

 seed= 378f3e50
 sample size= 20
    0  0.555578
    1  0.813145
    2  0.835393
    3  0.244674
    4  0.329031
    5  0.116658
    6  0.886474
    7  0.272177
    8  0.455835
    9  0.139337
   10  0.871178
   11  0.120802
   12  0.919480
   13  0.505610
   14  0.399121
   15  0.466545
   16  0.420749
   17  0.112918
   18  0.806191
   19  0.501699
 xmean= 4.886298e-01  mean-sq= 7.535142e-02
*/
