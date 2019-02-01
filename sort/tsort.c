/*  tsort.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "tree.h"
static int k;
void tsort(struct tnode *hd,struct tnode **ar)
{ if(hd!=NULL){
    tsort(hd->pl,ar);
    ar[k++]=hd;
    tsort(hd->pr,ar);
   }
}
