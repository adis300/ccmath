/*  tg2elps.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  g2elp

    Uses:  gelp  (implicit)  gsng  gsng2

    Input file:  gel2?.dat
*/
#include "ccmath.h"
#include <math.h>
void main(int na,char **av)
{ double ap,bp,cp,k; FILE *fp;
  double s1,s2,ga,gb,g2,cf;
  if(na!=2){ printf("para: input_file\n"); exit(1);}
  fp=fopen(*++av,"r");
  fscanf(fp,"%lf %lf %lf %lf",&k,&ap,&bp,&cp);
  printf(" Parameters: k=%f\n",k);
  printf("  Bartky a=%f b=%f c=%f\n\n",ap,bp,cp);
  while(fscanf(fp,"%lf %lf",&s1,&s2)!=EOF){
    printf(" angles: s1=%f s2=%f\n",s1,s2);

/* general elliptic integral with general limits */
    g2=g2elp(s1,s2,k,ap,bp,cp);
    printf("   g2= %12.8f\n",g2);

/* check using general elliptic integrals with zero lower limit */
    ga=gelp(s1,k,ap,bp,cp,&cf,NULL,NULL);
    gb=gelp(s2,k,ap,bp,cp,&cf,NULL,NULL);
    printf("   i1= %12.8f  i2= %12.8f  i2-i1= %12.8f\n",ga,gb,gb-ga);
   }
}
/*  Test output

 Parameters: k=0.500000
  Bartky a=1.000000 b=1.000000 c=1.000000

 angles: s1=0.392699 s2=1.178097
   g2=   0.84079870
   i1=   0.39518719  i2=   1.23598590  i2-i1=   0.84079870
 angles: s1=-0.392699 s2=1.178097
   g2=   1.63117309
   i1=  -0.39518719  i2=   1.23598590  i2-i1=   1.63117309
*/
