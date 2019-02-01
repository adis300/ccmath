/*  batins.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#define BAL 1
#include "tree.h"
#include <stdlib.h>
struct tnode *batins(char *kin,struct tnode *hd)
{ struct tnode *r,*s,*t,**v,*pt; int ef,avl;
  t=hd; v= &(hd->pr); s=hd=hd->pr;
  if(hd!=NULL){
    while(1){
      if((ef=strcmp(kin,hd->key))==0) return hd;
      else if(ef<0) v= &(hd->pl); else v= &(hd->pr);
      if(*v==NULL) break;
      if((*v)->bal!=0){ t=hd; s= *v;}
      hd= *v;
     }
   }
  pt= *v=(struct tnode *)malloc(sizeof(*hd));
  pt->key=kin; pt->bal=0; pt->pr=pt->pl=NULL;
  if(s==NULL) return *v;
  if(strcmp(kin,s->key)<0){ r=hd=s->pl; avl= -1;}
  else{ r=hd=s->pr; avl=1;}
  while(hd!= *v){ if(strcmp(kin,hd->key)<0){ hd->bal= -1; hd=hd->pl;}
    else{ hd->bal=1; hd=hd->pr;}
   }
  if(s->bal!=avl){ s->bal+=avl; return *v;} hd=r;
  if(avl<0){ if(r->bal== -avl){ hd=r->pr; r->pr=hd->pl; hd->pl=r;}
    s->pl=hd->pr; hd->pr=s;
   }
  else{ if(r->bal== -avl){ hd=r->pl; r->pl=hd->pr; hd->pr=r;}
    s->pr=hd->pl; hd->pl=s;
   }
  if(hd==r || hd->bal==0) s->bal=r->bal=0;
  else if(hd->bal==avl){ s->bal= -avl; r->bal=hd->bal=0;}
  else{ r->bal=avl; s->bal=hd->bal=0;}
  if(s==t->pr) t->pr=hd; else t->pl=hd;
  return pt;
}
