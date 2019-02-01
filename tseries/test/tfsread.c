/*  tfsread.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Utility reads and displays contents of a binary factor model
    time series file.

    Input parameter:  binary_in_file -> name of input file
                                        [ created by gfarma ]

     test output generated using  data/tfs0.b                                        
*/
#include "ccmath.h"
void main(int na,char **av)
{ FILE *fin; int i,j,k,n,m; char xl[4];
  struct fmod y[20];
  if(na!=2){ printf("para: binary_input_file\n"); exit(1);}
  fin=fopen(*++av,"rb");
  fread((void *)&n,sizeof(int),1,fin);

/* read and print series in blocks of 20 */
  printf(" series length = %d\n",n);
  fprintf(stderr,"enter: q or Q to quit\n");
  for(j=0,m=20;;){
    k=fread((void *)y,sizeof(struct fmod),m,fin);
    for(i=0; i<k ;++i)
      printf("%4d  %2d %10.6f\n",++j,y[i].fac,y[i].val);
    if(k<m) break;
    gets(xl); if(xl[0]=='q' || xl[0]=='Q') break;
   }
}
/*  Test output

 series length = 400
   1   0  -2.212230
   2   0  -3.280324
   3   0  -1.486362
   4   1   1.454822
   5   0   2.186266
   6   1   2.539846
   7   1   0.623113
   8   1   0.656758
   9   1   1.879724
  10   0   2.327022
  11   0   2.316440
  12   0   0.182498
  13   0  -1.916793
  14   0  -2.885694
  15   1  -2.235292
  16   0  -0.618697
  17   1   2.698323
  18   1   1.071088
  19   1  -2.372047
  20   0  -2.851726
*/
