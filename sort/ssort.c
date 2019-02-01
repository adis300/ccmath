/*  ssort.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
void ssort(void **v,int n,int (*comp)())
{ int gap,i,j; char *tem;
  for(gap=1; gap<=n ; gap=3*gap+1);
  for(gap/=3; gap>0 ;gap/=3){
    for(i=gap; i<n ;++i){
      for(tem=v[i],j=i-gap; j>=0 && (*comp)(v[j],tem)>0 ;j-=gap)
        v[j+gap]=v[j];
      v[j+gap]=tem;
     }
   }
}
