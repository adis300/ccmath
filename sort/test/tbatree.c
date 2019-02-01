/*  tbatree.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  batins  batdel  btsearch  btsort  prbtree

    Input file:  ttree.dat
*/
#define BAL 1
#include "ccmath.h"
struct trec {char key[2]; char rec[2];} tstor[128];
struct tnode head,*arp[28];
void main(int na,char **av)
{ struct tnode *hd= &head,*pt;
  int n; FILE *fp;
  if(na!=2){ printf("para: input_file\n"); exit(-1);}
  fp=fopen(*++av,"r");
  printf("     Test of Balanced Tree Functions\n");

/* initialize tree head record */
  strcpy(tstor[0].key,"0");
  hd->key=tstor[0].key; hd->pl=hd->pr=NULL;
  for(n=1; fscanf(fp,"%s",tstor[n].key)!=EOF ;++n){

/* insert node in balanced AVL tree */
    pt=batins(tstor[n].key,hd);

   }
/* print tree structure to level 5 */
  pt=hd->pr; prbtree(pt,5);

/* delete nodes with keys I and T and print new tree */
  batdel("I",hd); batdel("T",hd);
  pt=hd->pr; prbtree(pt,5);

/* search tree for node with key P */
  pt=btsearch("P",hd); prbtree(pt,5);

/* sort tree nodes */
  btsort(hd,arp);
  for(n=0; arp[n]!=NULL ;) printf("%s",arp[n++]->key); printf("\n");
}
/*  Test output

     Test of Balanced Tree Functions
                                 K                               

                 F                               T               

         B               I               P               X       

     A       D       H       J       M       R       U       Z   

           C   E   G               L   O   Q   S       V   Y     

                                                                 

                                 K                               

                 F                               U               

         B               H               P               X       

     A       D       G       J       M       R       V       Z   

           C   E                   L   O   Q   S           Y     

                                                                 

                                 P                               

                 M                               R               

         L               O               Q               S       

                                                                 

                                                                 

                                                                 

0ABCDEFGHJKLMOPQRSUVXYZ
*/
