/*  btdel.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "tree.h"
int btdel(char *kin,struct tnode *hd)
{ struct tnode *r,*s,**f; int ef;
  while(hd!=NULL){
    if((ef=strcmp(kin,hd->key))==0) break;
    else if(ef<0) f= &(hd->pl); else f= &(hd->pr);
    hd= *f;
   }
  if(hd==NULL) return 0;
  if(hd->pr==NULL) *f=hd->pl;
  else if(hd->pl==NULL) *f=hd->pr;
  else if((r=hd->pr)->pl==NULL){ r->pl=hd->pl; *f=r;}
  else{ for(s=r->pl; s->pl!=NULL ;){ r=s; s=r->pl;}
        s->pl=hd->pl; r->pl=s->pr; s->pr=hd->pr; *f=s;
   }
  free(hd); return 1;
}
