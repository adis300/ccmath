/*  tbtree0.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  btins  tsearch  tsort

    Uses:  prtree

    Input file:  ttree.dat
*/
#include "ccmath.h"
struct trec {char key[2]; char rec[2];} tstor[128];
struct tnode head,*arp[28];
void main(int na,char **av)
{ struct tnode *hd= &head,*pt;
  int n; char sky[2]; FILE *fp;
  if(na!=2){ printf("para: input_file\n"); exit(-1);}
  fp=fopen(*++av,"r");
  printf("     Test of Binary Tree Functions\n");
/* initialize tree head */
  strcpy(tstor[0].key,"0");
  hd->key=tstor[0].key; hd->pl=hd->pr=NULL;

/* insert tree nodes */
  for(n=1; fscanf(fp,"%s",tstor[n].key)!=EOF ;++n){
    pt=btins(tstor[n].key,hd);
   }

  pt=hd->pr; prtree(pt,5);
  printf(" left branch\n"); prtree(pt->pl,5);

/* search for node with key K */
  pt=tsearch("K",hd); printf(" K-branch\n"); prtree(pt,5);

/* search for keys and report success or failure */
  for(n=0; n<2 ;++n){
    if(n) strcpy(sky,"a"); else strcpy(sky,"A");
    pt=tsearch(sky,hd); printf(" %s : ",sky);
    if(pt!=NULL) printf("%s found\n",pt->key); else printf("absent\n");
   } 
}
/*  Test output

     Test of Binary Tree Functions
                                 X                               

                 T                               Z               

         B               U               Y                       

     A       F               V                                   

           C   K                                                 

            E H M                                                

 left branch
                                 T                               

                 B                               U               

         A               F                               V       

                     C       K                                   

                       E   H   M                                 

                      D   G J L Q                                

 K-branch
                                 K                               

                 H                               M               

         G               J               L               Q       

                     I                               P       R   

                                                   O           S 

                                                                 

 A : A found
 a : absent
*/
