/*  batdel.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#define BAL 1
#include "tree.h"
int batdel(char *kin,struct tnode *hd)
{ struct tnode *r,*s,**f,*pstk[20]; int ef,jc,k,astk[20];
  pstk[k=0]=hd;
  while(hd!=NULL){
    if((ef=strcmp(kin,hd->key))==0) break;
    else if(ef<0){ f= &(hd->pl); astk[k]= -1;}
    else{ f= &(hd->pr); astk[k]=1;}
    pstk[++k]=hd= *f;
   }
  if(hd==NULL) return 0;
  jc=k; astk[k]=1;
  if(hd->pr==NULL){ *f=hd->pl; --k;}
  else if(hd->pl==NULL){ *f=hd->pr; --k;}
  else if((r=hd->pr)->pl==NULL){ r->pl=hd->pl; *f=r;}
  else{ pstk[++k]=r; astk[k]= -1;
    for(s=r->pl; s->pl!=NULL ;){ pstk[++k]=r=s; s=r->pl; astk[k]= -1;}
    s->pl=hd->pl; r->pl=s->pr; s->pr=hd->pr; *f=s;
   }
  if(k>=jc){ pstk[jc]= *f; (*f)->bal=hd->bal;}
  free(hd);
  while(k){ hd=pstk[k]; jc=astk[k--];
    if(hd->bal==0){ hd->bal= -jc; return 1;}
    if(hd->bal==jc) hd->bal=0;
    else{ if(jc<0){ s=r=hd->pr;
             if((ef=r->bal)==0){ hd->pr=r->pl; r->pl=hd;}
             else{ if(r->bal==jc){ s=r->pl; r->pl=s->pr; s->pr=r;}
                hd->pr=s->pl; s->pl=hd;
              }
            }
       else{ s=r=hd->pl;
          if((ef=r->bal)==0){ hd->pl=r->pr; r->pr=hd;}
          else{ if(r->bal==jc){ s=r->pl; r->pr=s->pl; s->pl=r;}
             hd->pl=s->pr; s->pr=hd;
           }
        }
       if(ef==0) hd->bal= -(r->bal=jc);
       else if(s==r || s->bal==0) hd->bal=r->bal=0;
       else if(s->bal== -jc){ hd->bal=jc; s->bal=r->bal=0;}
       else{ r->bal= -jc; s->bal=hd->bal=0;}
       if(astk[k]==1) pstk[k]->pr=s; else pstk[k]->pl=s;
       if(ef==0) return 1;
     }
   }
  return 1;
}
