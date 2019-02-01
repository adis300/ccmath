/*  btins.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "tree.h"
#include <stdlib.h>
struct tnode *btins(char *kin,struct tnode *hd)
{ struct tnode **v; int ef;
  while(hd!=NULL){
    if((ef=strcmp(kin,hd->key))==0) return hd;
    else if(ef<0) v= &(hd->pl); else v= &(hd->pr);
    hd= *v;
   }
  hd= *v=(struct tnode *)malloc(sizeof(*hd));
  hd->key=kin; hd->pr=hd->pl=NULL;
  return hd;
}
