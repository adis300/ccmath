/*  pwr.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
double pwr(double y,int n)
{ double s=1.; unsigned m,j; 
  if(n){ if(n<0){ m= -n; y=1./y;} else m=n;
    for(j=1; j<=m ;j<<=1){ if(j&m) s*=y; y*=y;}
   }
  return s;
}
