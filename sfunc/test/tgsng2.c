/*  tgsng2.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Test:  gelp  g2elp  gsng  gsng2

    Input file:  gel2c.dat
*/
#include "ccmath.h"
#include <math.h>
void main(int na,char **av)
{ double ap,bp,cp,k; FILE *fp;
  double ax,bx,cx,b,ia,ib,i2;
  double s1,s2,ss,h,dd,ga,gb,g2;
  if(na!=2){ printf("para: input_file\n"); exit(-1);}
  fp=fopen(*++av,"r");
  fscanf(fp,"%lf %lf %lf %lf",&k,&ap,&bp,&cp);
  b=sqrt(1.-k*k);
  printf(" Parameters: k=%f\n",k);
  printf("  Bartky a=%f b=%f c=%f\n\n",ap,bp,cp);
  while(fscanf(fp,"%lf %lf",&s1,&s2)!=EOF){
    printf(" angles: aa=%f ab=%f\n",s1,s2);
/* evaluate first elliptic integral */
    ss=fabs(s1); ax=ap; bx=bp; cx=cp;
    ga=gelp(ss,k,ax,bx,cx,NULL,NULL,NULL);
    printf("  ga0= %12.8f\n",ga); h=ga;
/* check first integral */
    ia=gsng(&ax,&bx,&cx,b,ss);
    printf("  T-Bartky: %f %f %f  ia= %12.8f\n",ax,bx,cx,ia);
    ga=gelp(ss,k,ax,bx,cx,NULL,NULL,NULL);
    printf("     sa= %12.8f  ia+sa= %12.8f\n",ga,ia+ga);
/* evaluate second elliptic integral */
    ax=ap; bx=bp; cx=cp;
    gb=gelp(s2,k,ax,bx,cx,NULL,NULL,NULL);
    printf("  gb0= %12.8f\n",gb);

/* set dd equal to general limit integral integral */
    if(s1>0.) dd=gb-h; else dd=gb+h;

/* check second integral */
    ib=gsng(&ax,&bx,&cx,b,s2);
    printf("  T-Bartky: %f %f %f  ib= %12.8f\n",ax,bx,cx,ib);
    gb=gelp(s2,k,ax,bx,cx,NULL,NULL,NULL);
    printf("     sb= %12.8f  ib+sb= %12.8f\n",gb,ib+gb);

/* evaluate elliptic integral using general limits */
    ax=ap; bx=bp; cx=cp;
    g2=g2elp(s1,s2,k,ax,bx,cx); h=g2;
    printf("  g20= %12.8f\n",g2);

/* transform singular elliptic integral with general limits */
    i2=gsng2(&ax,&bx,&cx,b,s1,s2);
/* check general limit integral */
    printf("  T-Bartky: %f %f %f  i2= %12.8f\n",ax,bx,cx,i2);
    g2=g2elp(s1,s2,k,ax,bx,cx);
    printf("     g2= %12.8f  g2+i2= %12.8f\n",g2,i2+g2);

/* compare direct general limit integral with result obtained by
   combining single limit integrals */
    printf("  comparison: g2: %12.8f  diff: %12.8f\n",h,dd);
   }
}
/*  Test output

 Parameters: k=0.500000
  Bartky a=1.000000 b=-1.000000 c=-1.154701

 angles: aa=0.392699 ab=1.178097
  ga0=   0.44373891
  T-Bartky: 0.000000 -0.142857 1.010363  ia=   0.44624102
     sa=  -0.00250212  ia+sa=   0.44373891
  gb0=   0.38362644
  T-Bartky: 0.000000 -0.142857 1.010363  ib=   0.44368679
     sb=  -0.06006035  ib+sb=   0.38362644
  g20=  -0.06011246
  T-Bartky: 0.000000 -0.142857 1.010363  i2=  -0.00255423
     g2=  -0.05755823  g2+i2=  -0.06011246
  comparison: g2:  -0.06011246  diff:  -0.06011246
 angles: aa=-0.392699 ab=1.178097
  ga0=   0.44373891
  T-Bartky: 0.000000 -0.142857 1.010363  ia=   0.44624102
     sa=  -0.00250212  ia+sa=   0.44373891
  gb0=   0.38362644
  T-Bartky: 0.000000 -0.142857 1.010363  ib=   0.44368679
     sb=  -0.06006035  ib+sb=   0.38362644
  g20=   0.82736535
  T-Bartky: 0.000000 -0.142857 1.010363  i2=   0.88992781
     g2=  -0.06256246  g2+i2=   0.82736535
  comparison: g2:   0.82736535  diff:   0.82736535
*/
