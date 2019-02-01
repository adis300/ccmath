/*  tgelp.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  gelp

    Input parameter:  c  order angle (in degrees)
                         with 0 < c < 90 and k=sin(c)
*/
#include "ccmath.h"
#include <math.h>
void main(int na,char **av)
{ double a,k,c,af,bf,df,g,gg,hh,zz,x;
  double rad=1.74532925199433e-2;
  if(na!=2){ printf("para: alpha(deg)\n"); exit(1);}
  printf("     Test of General Elliptic Integral\n");
  k=atof(*++av); printf("  alpha= %.2f deg.\n",k);
  c=k*rad; k=sin(c); c=cos(c);
  printf("   x/ang");
  for(a=15.; a <91. ;a+=15.) printf("  %6.2f  ",a);
  printf("\n");
  for(x=.2; x<.9 ;x+=.2){
    af=1.; df=1.-x; bf=1./df; df/=c;
    printf("  x=%4.2f",x);
    for(a=15.; a <89. ;a+=15.){

/* compute general elliptic integral */
      g=gelp(rad*a,k,af,bf,df,&gg,&hh,&zz);

      printf("  %f",g);
     }
    printf("  %f\n",gg);
   }
  printf("            H= %f   Z= %f  at x=0.80\n",hh,zz);
}
/*  Test output

     Test of General Elliptic Integral
  alpha= 60.00 deg.
   x/ang   15.00     30.00     45.00     60.00     75.00     90.00  
  x=0.20  0.265272  0.552174  0.886292  1.300034  1.826431  2.457151
  x=0.40  0.266500  0.562785  0.926702  1.410981  2.074127  2.907615
  x=0.60  0.267748  0.574145  0.974057  1.558839  2.456235  3.685091
  x=0.80  0.269018  0.586352  1.030756  1.771454  3.168447  5.512061
            H= 1.649179   Z= 2.156516  at x=0.80
*/
