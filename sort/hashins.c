/*  hashins.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "hash.h"
#include <stdlib.h>
struct tabl *hashins(char *kin,struct tabl **harr,int mh)
{ int hv,m; struct tabl *pe,*ps,*pc;
  hv=hval(kin,mh); pe=harr[hv]; ps=NULL;
  while(pe!=NULL){
    if((m=strcmp(kin,pe->key))==0) return pe;
    if(m<0) break; ps=pe; pe=pe->pt;
   }
  pc=(struct tabl *)malloc(sizeof(*pe));
  pc->key=kin; pc->pt=pe;
  if(ps==NULL) harr[hv]=pc; else ps->pt=pc;
  return pc;
}
