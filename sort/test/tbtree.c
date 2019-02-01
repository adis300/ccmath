/*  tbtree.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  btins  btdel  tsearch  tsort  prtree

    Input file:  ttree.dat
*/
#include "ccmath.h"
struct trec {char key[2]; char rec[2];} tstor[128];
struct tnode head,*arp[28];
void main(int na,char **av)
{ struct tnode *hd= &head,*pt;
  int n; FILE *fp;
  if(na!=2){ printf("para: input_file\n"); exit(-1);}
  fp=fopen(*++av,"r");
  printf("     Test of Binary Tree Functions\n");

/* initialize head of binary tree */
  strcpy(tstor[0].key,"0");
  hd->key=tstor[0].key; hd->pl=hd->pr=NULL;
  for(n=1; fscanf(fp,"%s",tstor[n].key)!=EOF ;++n){

/* insert a node in the binary tree */
    pt=btins(tstor[n].key,hd);

   }

/* print the tree structure to level 5 */
  pt=hd->pr; prtree(pt,5);
/* print the left branch to level 5 */
  printf(" left branch\n"); prtree(pt->pl,5);

/* search the tree for node with key K and print subtree K */
  pt=tsearch("K",hd); printf(" K-branch\n"); prtree(pt,5);

/* delete nodes with keys H and T and print the new tree structure */
  btdel("H",hd); btdel("T",hd); pt=hd->pr; prtree(pt,5);

/* search again for node K and print the subtree starting at K */
  pt=tsearch("K",hd); printf(" K-branch\n"); prtree(pt,5);

/* sort the tree nodes */
  tsort(hd,arp);
  for(n=0; arp[n]!=NULL ;) printf("%s",arp[n++]->key); printf("\n");
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

                                                                 

                                 X                               

                 U                               Z               

         B               V               Y                       

     A       F                                                   

           C   K                                                 

            E I M                                                

 K-branch
                                 K                               

                 I                               M               

         G               J               L               Q       

                                                     P       R   

                                                   O           S 

                                                                 

0ABCDEFGIJKLMOPQRSUVXYZ
*/
