/*  tpfac.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  pfac
*/
#include "ccmath.h"
void main(int na,char **av)
{ int n,ns,j,l,m,kk[32];
  if(na<2){ printf("para: n1 n2 ... \n"); exit(-1);}
  printf("Test of Prime Factorization\n");
  for(l=1; l<na ;++l){
    ns=atoi(*++av);
    printf(" nin = %d\n",ns);
    for(m=0; m<2 ;++m){
      if(m){ printf("even case");
        n=pfac(ns,kk,'e');}
      else{ printf("general case");
        n=pfac(ns,kk,'o');}
      printf(" nout= %d\n",n);
      printf(" # factors= %d:",kk[0]);
      for(j=1; j<=kk[0] ;) printf(" %d",kk[j++]);
      printf("\n");
     }
   }
}
/* Test output

Test of Prime Factorization
 nin = 63
general case nout= 63
 # factors= 3: 3 3 7
even case nout= 62
 # factors= 2: 2 31
 nin = 120
general case nout= 120
 # factors= 5: 2 2 2 3 5
even case nout= 120
 # factors= 5: 2 2 2 3 5
 nin = 175
general case nout= 175
 # factors= 3: 5 5 7
even case nout= 174
 # factors= 3: 2 3 29
*/
