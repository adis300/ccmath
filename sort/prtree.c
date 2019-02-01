/*  prtree.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "tree.h"
static struct tnode *psp[129];
static char pstr[131];
int puts(char *c);
void prtree(struct tnode *hd,int m)
{ int n=2,i,k,ks;
  for(n<<=m,i=0; i<=n ;) psp[i++]=NULL;
  ks=n/2+1; psp[ks]=hd; pstr[n+1]='\n'; pstr[n+2]='\0';
  for(k=ks/2,m=n; m>1 ;m/=2,k/=2){
    for(i=0; i<=n ;) pstr[i++]=' ';
    for(i=ks; i<=n ;i+=m){
      if(psp[i]!=NULL){ pstr[i]= *(psp[i]->key);
         if(k){ psp[i-k]=psp[i]->pl; psp[i+k]=psp[i]->pr;}
       }
     }
    puts(pstr); ks-=k;
   }
}
