/*  btsearch.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#define BAL 1
#include "tree.h"
struct tnode *btsearch(char *kin,struct tnode *hd)
{ int ef;
  while(hd!=NULL){
     if((ef=strcmp(kin,hd->key))==0) return hd;
     if(ef<0) hd=hd->pl; else hd=hd->pr;
   }
  return hd;
}
