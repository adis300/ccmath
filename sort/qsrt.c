/*  qsrt.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#define Swap(x,y) (tmp=(x),(x)=(y),(y)=tmp)
void qsrt(void **v,int i,int j,int (*comp)())
{ int up=j,lw=i; char *tmp,*pa;
  if(i>=j) return;
  --i; pa=v[up];
  while(i<j){
     for(++i; (*comp)(v[i],pa)<0 ;++i);
     for(--j; j>i && (*comp)(v[j],pa)>0 ;--j);
     if(i<j) Swap(v[i],v[j]);
    }
  Swap(v[i],v[up]);
  if(i-lw>up-i){ qsrt(v,i+1,up,comp); qsrt(v,lw,i-1,comp);}
  else{ qsrt(v,lw,i-1,comp); qsrt(v,i+1,up,comp);}
}
