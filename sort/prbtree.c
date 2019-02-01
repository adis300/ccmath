/*  prbtree.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#define BAL 1
#include "tree.h"
static struct tnode *pspb[129];
static char pstrb[131];
int puts(char *s);
void prbtree(struct tnode *hd,int m)
{ int n=2,i,k,ks;
  for(n<<=m,i=0; i<=n ;) pspb[i++]=NULL;
  ks=n/2+1; pspb[ks]=hd; pstrb[n+1]='\n'; pstrb[n+2]='\0';
  for(k=ks/2,m=n; m>1 ;m/=2,k/=2){
    for(i=0; i<=n ;) pstrb[i++]=' ';
    for(i=ks; i<=n ;i+=m){
      if(pspb[i]!=NULL){ pstrb[i]= *(pspb[i]->key);
	 if(k){ pspb[i-k]=pspb[i]->pl; pspb[i+k]=pspb[i]->pr;}
       }
     }
    puts(pstrb); ks-=k;
   }
}
