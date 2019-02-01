/*  msort.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "merge.h"
static struct llst *merge(struct llst *a,struct llst *b,int (*comp)());
struct llst *msort(struct llst *st,int dim,int (*comp)())
{ struct llst *a,*b; int i,m=dim/2;
  if(st->pt==NULL) return st;
  a=st; for(i=1; i<m ;++i,st=st->pt);
  b=st->pt; st->pt=NULL;
  return merge(msort(a,m,comp),msort(b,dim-m,comp),comp);
}
static struct llst *merge(struct llst *a,struct llst *b,int (*comp)())
{ struct llst *t,hd;
  if(b==NULL) return a; t= &hd;
  while(1){
    if((*comp)(a->pls,b->pls)<=0){
       t->pt=a; t=a; if((a=a->pt)==NULL){ t->pt=b; break;} }
    else{ t->pt=b; t=b; if((b=b->pt)==NULL){ t->pt=a; break;} }
   }
  return hd.pt;
}
