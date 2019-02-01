/*  optsch.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
double optsch(double (*func)(),double a,double b,double test)
{ double x,y,f1,f2,r=.61803399,s;
  s=b-a; x=a+r*s; y=b-r*s;
  f1=(*func)(x); f2=(*func)(y);
  while(1){ s*=r;
    if(f2>f1){ if(s<test) return x;
        a=y; y=x; x=a+r*s; f2=f1; f1=(*func)(x);}
    else{ if(s<test) return y;
        b=x; x=y; y=b-r*s; f1=f2; f2=(*func)(y);}
   }
}
