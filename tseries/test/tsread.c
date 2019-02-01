/*  tsread.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Utility reads and displays values in a binary ARMA model time
    series file.

    Input parameter:  binary_in_file -> name of binary ARMA time series
                                        file [ created by garma ]

                  Test output from:  data/ts0.b
*/
#include "ccmath.h"
void main(int na,char **av)
{ FILE *fp; double y[20];
  int i,j,k,n,m; char lx[4];
  if(na!=2){ printf("para: binary_in_file\n"); exit(-1);}
  fp=fopen(*++av,"rb");
  fread((void *)&n,sizeof(int),1,fp);
  printf(" length of ARMA series = %d\n",n);

/* read and display series in blocks of 20 */
  fprintf(stderr,"enter q or Q to quit\n");
  for(m=20,j=0;;){
    k=fread((void *)y,sizeof(y[0]),m,fp);
    for(i=0; i<k ;++i) printf(" %4d %11.6f\n",++j,y[i]);
    if(k<m) break;
    gets(lx); if(lx[0]=='q' || lx[0]=='Q') break;
   }
}
/*  Test output

 length of ARMA series = 400
    1   -1.492021
    2   -1.557274
    3    1.044174
    4    1.328194
    5    1.785135
    6   -0.438948
    7   -1.613255
    8   -0.137244
    9    1.244463
   10    2.069642
   11    0.774102
   12   -1.536896
   13   -2.151043
   14   -1.508561
   15   -0.870966
   16    2.009030
   17    1.884057
   18   -1.380098
   19   -3.682623
   20   -0.694761
*/
