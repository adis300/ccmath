/*  thash.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  hashins  hfind  hashdel  hval

    Input file:  hash.dat
*/
#include "ccmath.h"
#define HD 11
struct tabl *hashins(),*hfind();
struct tabl *harray[HD];
struct hrec {char key[8]; int val;} vv[30];
void main(int na,char **av)
{ struct tabl **p,*ph;
  int k,j,ns,mhash=HD; char kin[8];
  FILE *fp;
  if(na!=2){ printf("para: input_file\n"); exit(-1);}
  fp=fopen(*++av,"r");
  printf("     Test of Hash Storage Functions\n");
  for(j=0,p=harray; j<mhash ;++j) *p++ =NULL;
  for(j=0; fscanf(fp,"%s",kin)!=EOF ;++j){
    strcpy(vv[j].key,kin); fscanf(fp,"%d",&k);
    vv[j].val=k;

/* insert record into hash table store */
    ph=hashins(vv[j].key,harray,mhash);
    if(ph!=NULL) ph->val=(char *)(vv+j);

   }
  for(k=0; k<2 ;++k){
    for(ns=0; ns<j ;++ns){

/* find  and print table contents */
      ph=hfind(vv[ns].key,harray,mhash);
      if(ph!=NULL)
        printf("%2d %8s %5d\n",ns,ph->key,((struct hrec *)ph->val)->val);

     }

/* delete the first three records in the table */
    for(ns=0; ns<3 ;++ns)
      if(hashdel(vv[ns].key,harray,mhash)) printf("%d deleted\n",ns);
    printf("\n");
   }
}
/*  Test output

     Test of Hash Storage Functions
 0       ab    15
 1      cat    -7
 2      dmm    13
 3       fc    99
 4       gh    23
 5      fik   123
 6      mss    37
 7      pff   -22
0 deleted
1 deleted
2 deleted

 3       fc    99
 4       gh    23
 5      fik   123
 6      mss    37
 7      pff   -22
 */
