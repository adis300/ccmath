/*  tsdiff.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  sdiff  sintg

    Input parameters:  n_diff -> integer: order of differencing
                                          and integration
                       bin_file -> name of binary series input file
                                   [ created by garma ]
*/
#include "ccmath.h"
void main(int na,char **av)
{ double *y,*d,z;
  int j,n,nd; FILE *fp;
  if(na!=3){ printf("para: n_diff bin_file\n"); exit(-1);}
  nd=atoi(*++av); fp=fopen(*++av,"rb");
  printf("     Test of Time Series Differencing and Integration\n");
  printf("          model file: %s\n",*av);
  printf("  difference/integration order= %d\n",nd);
  fread((void *)&n,sizeof(int),1,fp);
  y=(double *)calloc(2*n,sizeof(double)); d=y+n;
  fread((void *)y,sizeof(double),n,fp);

/* difference the series */
  for(j=0; j<n ;++j) d[j]=sdiff(y[j],nd,j);

  printf("     y        dy       intg(dy)\n");
  for(j=0; j<n ;++j){

/* integrate the differenced series */
    z=sintg(d[j],nd,j);

    printf(" %7.3f  %7.3f  %7.3f\n",y[j],d[j],z);
   }
}
/*  Test output

     Test of Time Series Differencing and Integration
          model file: data/ts6.b
  difference/integration order= 2
     y        dy       intg(dy)
   0.119    0.119    0.000
  -1.193   -1.432    0.119
   0.583    3.089   -1.193
  -0.272   -2.632    0.583
   1.275    2.402   -0.272
  -0.232   -3.054    1.275
  -0.098    1.641   -0.232
   0.775    0.740   -0.098
   0.909   -0.739    0.775
   1.783    0.740    0.909
   1.295   -1.362    1.783
   0.349   -0.458    1.295
   0.046    0.644    0.349
  -0.608   -0.351    0.046
  -1.371   -0.109   -0.608
   0.719    2.854   -1.371
  -0.016   -2.826    0.719
  -1.550   -0.797   -0.016
  -2.536    0.547   -1.550
  -0.662    2.861   -2.536
  -0.920   -2.133   -0.662
  -0.026    1.153   -0.920
   0.318   -0.551   -0.026
  -0.100   -0.761    0.318
  -0.398    0.119   -0.100
*/
