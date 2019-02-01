/*  parma.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "arma.h"
extern struct mcof *par,*pma;
extern int nar,nma;
double parma(double *x,double *e)
{ struct mcof *p,*q; double y;
  for(y=0.,p=par,q=p+nar; p<q ;++p)
    y+= p->cf * *(x-(p->lag+1));
  for(p=pma,q=p+nma; p<q ;++p)
    y-= p->cf * *(e-(p->lag+1));
  *x=y; *e=0.;
  return y;
}
