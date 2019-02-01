/*  teval.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  eigval

    Uses:  matprt

    Input file:  sm6.bin
*/
#include "ccmath.h"
FILE *fp;
void main(int na,char **av)
{ int n,m;
  double *a,*ev;
  if(na!=2){ printf("para: input_file\n"); exit(1);}
  fp=fopen(*++av,"rb");
  fread((void *)&n,sizeof(int),1,fp);
  m=n*n;
  a=(double *)calloc(m+n,sizeof(double)); ev=a+m;
  fread((void *)a,sizeof(double),m,fp);
  printf(" A-in:\n"); matprt(a,n,n," %8.4f");

/* compute the eigenvalues of a real symmetric matrix */
  eigval(a,ev,n);

  printf(" eigenvalues: dim= %d\n",n);
  matprt(ev,1,n," %8.4f");
  printf(" A-out:\n"); matprt(a,n,n," %8.4f");
}
/* Test output

 A-in:
   3.0048   0.3942   0.0141   0.2540   0.2453   0.1352
   0.3942   3.0668   0.1977  -0.0884  -0.0657  -0.0155
   0.0141   0.1977   1.2235  -0.1181   0.2426   0.2887
   0.2540  -0.0884  -0.1181   2.0997   0.1781   0.1238
   0.2453  -0.0657   0.2426   0.1781   2.6069   0.3627
   0.1352  -0.0155   0.2887   0.1238   0.3627   1.4983
 eigenvalues: dim= 6
   3.5000   3.0000   2.5000   1.0000   2.0000   1.5000
 A-out:
   3.0048   0.3942   0.0141   0.2540   0.2453   0.1352
   0.3942   3.0668   0.1977  -0.0884  -0.0657  -0.0155
   0.0141   0.1977   1.2235  -0.1181   0.2426   0.2887
   0.2540  -0.0884  -0.1181   2.0997   0.1781   0.1238
   0.2453  -0.0657   0.2426   0.1781   2.6069   0.3627
   0.1352  -0.0155   0.2887   0.1238   0.3627   1.4983
*/
