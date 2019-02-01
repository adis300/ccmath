/*  pfac.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
static int kpf[26]={2,3,5,7,11,13,17,19,23,29,31,37,
  41,43,47,53,59,61,67,71,73,79,83,89,97,101};
int pfac(int n,int *kk,int fe)
{ int num,j,k,dc=1;
  if(fe=='e'){ n-=(n%2); dc=2;}
  for(;;n-=dc){ num=n; j=k=0;
    while(j<31){
      if(num%kpf[k]!=0){ if(k==25) break; ++k;}
      else{ kk[++j]=kpf[k]; num=num/kpf[k];
	if(num==1){ kk[0]=j; return n; } }
     }
   }
}
