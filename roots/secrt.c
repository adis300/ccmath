/*  secrt.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
double secrt(double (*func)(),double x,double dx,double test)
{ double f,fp,y; int k;
  y=x-dx; fp=(*func)(y);
  for(k=0;;++k){ f=(*func)(x);
    dx=f*(x-y)/(f-fp); fp=f; y=x; x-=dx;
    if(((dx<0.)?-dx:dx)<test || k==50)
      return x;
   }
}
