/*  tcspl.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  cspl  csfit  dcspl (when tn=0) or  tnsfit (when tn!=0)

    To set a nonzero tension call: 'tcspl tn'  0 <= tn < 1 is assumed.
    A user specified point set can be stored as x-y pairs in a file
    and specified with the call: 'tcspl tn file'.

    The file cspin.dat is a sample file specifing the same points as
    the test arrays initialized in this code.
*/
#include "ccmath.h"
#include <stdio.h>
#define MD 20
/* number of splines = interpolation points - 1 */
int n=7;
/* x values */
double x[MD]={
 0.0, 0.2, 0.4, 0.6, 0.8, 1.0, 1.2, 1.4};
/* y values */
double y[MD]={
 0.0, 1.5, 1.8, 0.5, -1.0, -1.2, -0.3, 0.5};
main(int na,char **av)
{ double p[MD],s,ds,tn; int i,j;
  double atof(); FILE *fp;
  if(na==2){
    fp=fopen(*++av,"r");
    for(n=0; fscanf(fp,"%lf %lf",x+n,y+n)!=EOF ;++n);
    --n;
   }
/* ds is the x-interval used in spline evaluation */
  ds=.04;
/* initial spline tension */
  tn=0.;      
  printf("     Test of Cubic Spline Interpolation\n");
  for(i=0; i<2 ;++i){
    printf("\n  tension= %f\n",tn);
    cspl(x,y,p,n,tn);
    printf("  spline coefficients\n");
    for(j=0; j<=n ;++j)
      printf(" %d x=%10.6f y=%10.6f z=%12.8f\n",j,x[j],y[j],p[j]);
    if(tn==0.) printf("  evaluation of spline and derivative\n");
    else printf("  evaluation of spline with tension\n");
    for(s=0.; s<=1.4 ;s+=ds){
      if(tn==0.){ printf(" x= %8.3f  F= %14.10f",s,csfit(s,x,y,p,n));
        printf("  F'= %14.10f\n",dcspl(s,x,y,p,n));
       }
      else printf(" x= %8.3f  F= %14.10f\n",s,tnsfit(s,x,y,p,n,tn));
     }
	tn=0.6;
   }
}
/* Test output

     Test of Cubic Spline Interpolation

  tension= 0.000000
  spline coefficients
 0 x=  0.000000 y=  0.000000 z=  0.00000000
 1 x=  0.200000 y=  1.500000 z= -5.39161800
 2 x=  0.400000 y=  1.800000 z= -8.43352800
 3 x=  0.600000 y=  0.500000 z= -0.87427001
 4 x=  0.800000 y= -1.000000 z=  6.93060804
 5 x=  1.000000 y= -1.200000 z=  5.65183786
 6 x=  1.200000 y= -0.300000 z= -2.03795946
 7 x=  1.400000 y=  0.500000 z=  0.00000000
  evaluation of spline and derivative
 x=    0.000  F=   0.0000000000  F'=   8.5783236001
 x=    0.040  F=   0.3414076262  F'=   8.4489247681
 x=    0.080  F=   0.6724633459  F'=   8.0607282721
 x=    0.120  F=   0.9828152525  F'=   7.4137341120
 x=    0.160  F=   1.2621114394  F'=   6.5079422879
 x=    0.200  F=   1.5000000000  F'=   5.3433527997
 x=    0.240  F=   1.6868809344  F'=   3.9763586396
 x=    0.280  F=   1.8161618688  F'=   2.4633527997
 x=    0.320  F=   1.8820023360  F'=   0.8043352800
 x=    0.360  F=   1.8785618688  F'=  -1.0006939196
 x=    0.400  F=   1.8000000000  F'=  -2.9517347990
 x=    0.440  F=   1.6438686362  F'=  -4.7943593267
 x=    0.480  F=   1.4212891790  F'=  -6.2741394710
 x=    0.520  F=   1.1467754036  F'=  -7.3910752319
 x=    0.560  F=   0.8348410855  F'=  -8.1451666094
 x=    0.600  F=   0.5000000000  F'=  -8.5364136036
 x=    0.640  F=   0.1568445208  F'=  -8.5589213329
 x=    0.680  F=  -0.1797185847  F'=  -8.2067949158
 x=    0.720  F=  -0.4947039505  F'=  -7.4800343525
 x=    0.760  F=  -0.7731262109  F'=  -6.3786396427
 x=    0.800  F=  -1.0000000000  F'=  -4.9026107867
 x=    0.840  F=  -1.1632467193  F'=  -3.2699553418
 x=    0.880  F=  -1.2624148403  F'=  -1.6986808657
 x=    0.920  F=  -1.2999596015  F'=  -0.1887873583
 x=    0.960  F=  -1.2783362418  F'=   1.2597251804
 x=    1.000  F=  -1.2000000000  F'=   2.6468567503
 x=    1.040  F=  -1.0694576434  F'=   3.8187427001
 x=    1.080  F=  -0.8994220543  F'=   4.6215183786
 x=    1.120  F=  -0.7046576434  F'=   5.0551837856
 x=    1.160  F=  -0.4999288217  F'=   5.1197389213
 x=    1.200  F=  -0.3000000000  F'=   4.8151837856
 x=    1.240  F=  -0.1165227070  F'=   4.3749845414
 x=    1.280  F=   0.0513030574  F'=   4.0326073514
 x=    1.320  F=   0.2073901752  F'=   3.7880522157
 x=    1.360  F=   0.3556515287  F'=   3.6413191343

  tension= 0.600000
  spline coefficients
 0 x=  0.000000 y=  0.000000 z=  0.00000000
 1 x=  0.200000 y=  1.500000 z= -5.32865356
 2 x=  0.400000 y=  1.800000 z= -8.30205545
 3 x=  0.600000 y=  0.500000 z= -0.86589508
 4 x=  0.800000 y= -1.000000 z=  6.82792615
 5 x=  1.000000 y= -1.200000 z=  5.56300619
 6 x=  1.200000 y= -0.300000 z= -1.98013994
 7 x=  1.400000 y=  0.500000 z=  0.00000000
  evaluation of spline with tension
 x=    0.000  F=   0.0000000000
 x=    0.040  F=   0.3409532586
 x=    0.080  F=   0.6718217079
 x=    0.120  F=   0.9823751430
 x=    0.160  F=   1.2620904718
 x=    0.200  F=   1.5000000000
 x=    0.240  F=   1.6858957501
 x=    0.280  F=   1.8142735418
 x=    0.320  F=   1.8801623847
 x=    0.360  F=   1.8776903674
 x=    0.400  F=   1.8000000000
 x=    0.440  F=   1.6433919279
 x=    0.480  F=   1.4200115545
 x=    0.520  F=   1.1452841875
 x=    0.560  F=   0.8338948503
 x=    0.600  F=   0.5000000000
 x=    0.640  F=   0.1576136845
 x=    0.680  F=  -0.1786437101
 x=    0.720  F=  -0.4938813762
 x=    0.760  F=  -0.7729054584
 x=    0.800  F=  -1.0000000000
 x=    0.840  F=  -1.1623146483
 x=    0.880  F=  -1.2605326593
 x=    0.920  F=  -1.2980274766
 x=    0.960  F=  -1.2772970801
 x=    1.000  F=  -1.2000000000
 x=    1.040  F=  -1.0696028673
 x=    1.080  F=  -0.8993088656
 x=    1.120  F=  -0.7043696126
 x=    1.160  F=  -0.4996814085
 x=    1.200  F=  -0.3000000000
 x=    1.240  F=  -0.1169270376
 x=    1.280  F=   0.0506107929
 x=    1.320  F=   0.2066891121
 x=    1.360  F=   0.3552183252
*/
