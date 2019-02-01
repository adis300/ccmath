/*  hashdel.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "hash.h"
int hashdel(char *kin,struct tabl **harr,int mh)
{ int hv,m; struct tabl *pe,*ps;
  hv=hval(kin,mh); pe=harr[hv]; ps=NULL;
  while(pe!=NULL){
    if((m=strcmp(kin,pe->key))==0) break;
    if(m<0) return 0;
	ps=pe; pe=pe->pt;
   }
  if(pe==NULL) return 0;
  if(ps!=NULL) ps->pt=pe->pt; else harr[hv]=pe->pt;
  free(pe); return 1;
}
