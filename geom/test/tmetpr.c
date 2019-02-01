/*  tmetpr.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  metpr

    Uses:  vmul  dotp  matprt

    Input file:  metp.dat
*/
#include "ccmath.h"
char fmt[]=" %8.4f";
void main(int na,char **av)
{ double s,*a,*u,*v;
  int i,n,m; FILE *fp;
  if(na!=2){ printf("para: input_file\n"); exit(-1);}
  fp=fopen(*++av,"r");
  fscanf(fp,"%d",&n); m=n*n;
  printf("     Metric Product Test: dimension= %d\n",n);
  a=(double *)calloc(m+2*n,sizeof(double));
  u=a+m; v=u+n;
  for(i=0; i<m ;++i) fscanf(fp,"%lf",a+i);
  for(i=0; i<n ;++i) fscanf(fp,"%lf",u+i);
  printf(" metric matrix A:\n");
  matprt(a,n,n,fmt);
  printf("  vector u:\n");
  matprt(u,1,n,fmt);

/* compute metric product u'Au */
  s=metpr(u,a,u,n);

  printf(" metric prod. u'Au = %10.7f\n",s);
  vmul(v,a,u,n);
/* check product */
  s=dotp(v,u,n);
  printf(" check (Au)'u = %10.7f\n",s);
}
/* Test output

     Metric Product Test: dimension= 4
 metric matrix A:
   6.0000   2.0000   1.0000   2.0000
   2.0000   4.0000   3.0000   1.0000
   1.0000   3.0000   3.5000  -3.0000
   2.0000   1.0000  -3.0000   4.0000
  vector u:
   2.0000  -0.5000   0.5000  -1.0000
 metric prod. u'Au = 22.3750000
 check (Au)'u = 22.3750000
*/
