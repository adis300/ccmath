/*  pplsq.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <stdlib.h>
#include "orpol.h"
void plsq(double *x,double *y,int n,Opol *c,double *ss,int m);
void psqcf(double *pc,Opol *cf,int m);
double pplsq(double *x,double *y,int n,double *bc,int m)
{ Opol *c; double *ss,sq;
  c=(Opol *)calloc(m,sizeof(Opol));
  ss=(double *)calloc(m,sizeof(double));
  plsq(x,y,n,c,ss,m);
  psqcf(bc,c,m);
  sq=ss[m-1];
  free(c); free(ss);
  return sq;
}
