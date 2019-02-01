/*  ttheta.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  theta  stheta

    Uses:  amelp  felp

    Prompted input:  at prompt  'amplitude(deg.) '
                                 enter  am  {elliptic modulus parameter
                                             in degrees, with 90 > am > 0 }
*/
#include "ccmath.h"
#include <math.h>
void main(void)
{ double sn,cn,dn,dd,k,kp,kf,u,am,du; int j;
  double rad=1.74532925199433e-2;
  printf("    Test of Theta Functions\n");
  fprintf(stderr,"amplitude(deg.) "); scanf("%lf",&am);
  k=sin(am*rad); kp=cos(am*rad);
  u=felp(0.,k,&kf,0L,0L); du=kf/5.;
  printf(" alpha= %.2f  K= %f\n",am,kf);

/* initialize theta function with modulus k */
  stheta(k);

  for(u=du,j=0; j<5 ;u+=du,++j){

/* use theta functions to compute Jacobian elliptic functions */
    am=amelp(u,k); dd=theta(u,0);
    sn=theta(u,1)/(dd*sqrt(k));
    cn=sqrt(kp/k)*theta(u,2)/dd;
    dn=sqrt(kp)*theta(u,3)/dd;

    printf(" u:%f  sn:%f  cn:%f  dn:%f\n",u,sn,cn,dn);
    kf=k*sin(am); kf=sqrt(1.-kf*kf);
    printf("       check:   %f     %f     %f\n",sin(am),cos(am),kf);
   }
}
/*  Test output

Test of Theta Functions
 alpha= 30.00  K= 1.685750
 u:0.337150  sn:0.329327  cn:0.944216  dn:0.986350
       check:   0.329327     0.944216     0.986350
 u:0.674300  sn:0.615232  cn:0.788346  dn:0.951511
       check:   0.615232     0.788346     0.951511
 u:1.011450  sn:0.828520  cn:0.559959  dn:0.910158
       check:   0.828520     0.559959     0.910158
 u:1.348600  sn:0.957283  cn:0.289153  dn:0.878010
       check:   0.957283     0.289153     0.878010
 u:1.685750  sn:1.000000  cn:0.000000  dn:0.866025
       check:   1.000000     0.000000     0.866025
*/
