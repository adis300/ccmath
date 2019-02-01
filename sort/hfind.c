/*  hfind.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "hash.h"
struct tabl *hfind(char *kin,struct tabl **harr,int mh)
{ int hv,m; struct tabl *pe;
  hv=hval(kin,mh); pe=harr[hv];
  while(pe!=NULL){
    if((m=strcmp(kin,pe->key))==0) return pe;
    if(m<0) return NULL; pe=pe->pt;
   }
  return NULL;
}
