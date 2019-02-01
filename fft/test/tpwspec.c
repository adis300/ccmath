/*  tpwspec.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test: pwspec
    Uses: pfac
*/
#include "ccmath.h"
#include <math.h>
#define MPT 50
double x[MPT];
void main(void)
{ double y; int kk[32],n=MPT,i;
  printf("     Test of Power Spectra Estimator\n");
  printf("       F = 1/(k+1)\n");
  for(i=0; i<n ;++i) x[i]=1./(1.+i);
  n=pfac(n,kk,'o');
  printf("      n= %d\n",n);
  pwspec(x,n,0);
  printf("  output spectra and cumulative spectra\n");
  for(i=0,y=0.; i<n ;++i){
    printf("%2d  %10.6f  %7.3f\n",i,x[i],y);
    y+=x[i]; }
  printf("%2d              %7.3f\n",i,y);
}
/* Test output

     Test of Power Spectra Estimator
       F = 1/(k+1)
      n= 50
  output spectra and cumulative spectra
 0    0.249122    0.000
 1    0.074950    0.249
 2    0.046686    0.324
 3    0.033804    0.371
 4    0.026332    0.405
 5    0.021452    0.431
 6    0.018031    0.452
 7    0.015512    0.470
 8    0.013594    0.486
 9    0.012095    0.499
10    0.010899    0.512
11    0.009931    0.522
12    0.009138    0.532
13    0.008483    0.542
14    0.007937    0.550
15    0.007481    0.558
16    0.007100    0.565
17    0.006781    0.573
18    0.006517    0.579
19    0.006299    0.586
20    0.006122    0.592
21    0.005982    0.598
22    0.005877    0.604
23    0.005803    0.610
24    0.005760    0.616
25    0.005745    0.622
26    0.005760    0.627
27    0.005803    0.633
28    0.005877    0.639
29    0.005982    0.645
30    0.006122    0.651
31    0.006299    0.657
32    0.006517    0.663
33    0.006781    0.670
34    0.007100    0.677
35    0.007481    0.684
36    0.007937    0.691
37    0.008483    0.699
38    0.009138    0.708
39    0.009931    0.717
40    0.010899    0.727
41    0.012095    0.738
42    0.013594    0.750
43    0.015512    0.763
44    0.018031    0.779
45    0.021452    0.797
46    0.026332    0.818
47    0.033804    0.845
48    0.046686    0.878
49    0.074950    0.925
50                1.000
*/
