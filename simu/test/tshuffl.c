/*  tshuffl.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  shuffl

    Uses:  bran  setbran

    Input parameters:  s -> unsigned integer: pseudorandom seed
                       m -> integer: number of shuffles
*/
#include "ccmath.h"
void main(int na,char **av)
{ int base[12],*sh[12]; unsigned int s;
  int n,m,i,j;
  if(na!=3){ printf("para: seed msz\n"); exit(-1);}
  printf("     Test of Shuffle\n");
/* initialize pseudorandom generator */
  sscanf(*++av,"%x",&s); printf(" seed= %x\n",s);
  setbran(s);
  m=atoi(*++av);
  for(i=0,n=12; i<n ;++i){
    base[i]=i+1; sh[i]=base+i;
   }
  for(i=0; i<m ;++i){

/* shuffle input array */
    shuffl((void *)sh,n);

    for(j=0; j<n ;++j) printf(" %2d",*sh[j]);
    printf("\n");
   }
}
/*  Test output

     Test of Shuffle
 seed= 571a5e98
  5  4 11  1  3 12  9  7  2 10  8  6
  8  3  6 12  5  9  7  1 10 11  4  2
 11  8 12  4  6  9  3  5 10  1  7  2
  6 10  1  4  3  5  8 11 12  7  2  9
  8  2 10  7 12  6  9  4  5  3 11  1
  1  4  3  8 12  6  9  2  5  7 10 11
  3 12  4  5 11  1  7 10  6  9  8  2
 10  1  8  7  4  3  5 11  2  9 12  6
  4  8  5  1  7 11  3  6  2 10 12  9
  6 12  7  9  8 10  1  3  4  2  5 11
  7  8  4 10  3 11  5  6  2 12  9  1
  9  8  5  1  2  4 10 11  3  7 12  6
  1 10  3  2 11  6  4 12  5  7  9  8
  6 10  4  9 11  3  8  2  5  1  7 12
 10  6  8  5 11  9  7  4  2 12  3  1
  2 12  8  6  4  5  9 10 11  7  1  3
  7  4 10  3  9 11  6  8  5 12  1  2
  8  9  6  5 10  7  3 12  4 11  1  2
  9  1 11  7  4  3 12 10  6  2  5  8
 12  3  5  4  2  7 11 10  8  9  1  6
*/
