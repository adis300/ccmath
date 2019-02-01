/*  btsort.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#define BAL 1
#include "tree.h"
static int k;
void btsort(struct tnode *hd,struct tnode **ar)
{ if(hd!=NULL){
    btsort(hd->pl,ar);
    ar[k++]=hd;
    btsort(hd->pr,ar);
   }
}
