/*  txmean.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  xmean

    Input parameter:  bin_file -> name of binary ARMA series file
                                  [ created by garma ]
*/
#include "ccmath.h"
void main(int na,char **av)
{ double *x,*y,xm,x0;
  int nm,n,j; FILE *fp;
  if(na!=2){ printf("para: bin_file\n"); exit(-1);}
  fp=fopen(*++av,"rb");
  fread((void *)&nm,sizeof(int),1,fp);
  x=(double *)calloc(2*nm,sizeof(double));
  n=fread((char *)x,sizeof(double),nm,fp);
  if(n!=nm){ printf("I/O error\n"); exit(1);}
  printf("     Test of ARMA Series Mean Extraction\n");
  printf("          model file: %s\n",*av);
  for(j=0,y=x+n,x0=0.; j<n ;++j)
    x0+=(y[j]=x[j]);
  x0/=(double)n;

/* compute series mean and extract it from the series */
  xm=xmean(x,n);

  printf(" series length = %d\n",n);
  printf("   direct mean = %10.7f\n",x0);
  printf(" computed mean = %10.7f\n",xm);
  printf("    x-xm          x\n");
  for(j=0; j<n ;++j)
    printf(" %9.5f   %9.5f\n",x[j],y[j]);
}
/*  Test output

     Test of ARMA Series Mean Extraction
          model file: data/ts6.b
 series length = 25
   direct mean = -0.0723526
 computed mean = -0.0723526
    x-xm          x
   0.19159     0.11923
  -1.12099    -1.19334
   0.65564     0.58329
  -0.19952    -0.27187
   1.34778     1.27543
  -0.15936    -0.23171
  -0.02578    -0.09813
   0.84731     0.77496
   0.98150     0.90915
   1.85547     1.78312
   1.36743     1.29508
   0.42114     0.34879
   0.11846     0.04610
  -0.53548    -0.60783
  -1.29865    -1.37101
   0.79175     0.71939
   0.05598    -0.01637
  -1.47715    -1.54951
  -2.46369    -2.53604
  -0.58950    -0.66185
  -0.84793    -0.92028
   0.04674    -0.02561
   0.39010     0.31775
  -0.02723    -0.09959
  -0.32562    -0.39797
*/
