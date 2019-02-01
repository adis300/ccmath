/*  tg2elp.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  g2elp

    Uses:  gelp

    Input: Data File  g2elp.dat

*/
#include "ccmath.h"
#include <math.h>
void main(int na,char **av)
{ double a,b,k,af,bf,df,g,h,q;
  FILE *fp;
  double rad=1.74532925199433e-2;
  if(na!=2){ printf("para: input_file\n"); exit(-1);}
  fp=fopen(*++av,"r");
  printf("     Test of Elliptic Integral with General Limits\n");
  fscanf(fp,"%lf",&k);
  fscanf(fp,"%lf %lf %lf",&a,&b,&q);
  printf(" k=%.2f l-lim= %.2f u-lim= %.2f q= %.2f\n",k,a,b,q);
  af=1.; df=1.-q; bf=1./df; df/=sqrt(1.-k*k);
  printf(" Bartky parameters: %f %f %f\n",af,bf,df);
  a*=rad; b*=rad;
  printf(" integrals:\n");

/* compute general elliptic integral with general limits */
  g=g2elp(a,b,k,af,bf,df);
  printf(" a to b = %12.7f\n",g);

/* check using elliptic integrals with zero lower limit */
  g=gelp(fabs(a),k,af,bf,df,&h,NULL,NULL);
  printf("     0 to |a| = %12.7f",g);
  g=gelp(b,k,af,bf,df,&h,NULL,NULL); printf("   0 to b = %12.7f\n",g);
  printf("     0 to pi/2 = %12.7f\n",h);
}
/*  Test output

     Test of Elliptic Integral with General Limits
 k=0.70 l-lim= 20.00 u-lim= 80.00 q= 0.60
 Bartky parameters: 1.000000 2.500000 0.560112
 integrals:
 a to b =    2.0709474
     0 to |a| =    0.3613756   0 to b =    2.4323230
     0 to pi/2 =    3.0314573
*/
