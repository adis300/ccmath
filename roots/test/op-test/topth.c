/*  topth.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <stdio.h>
#define ND 20
double x[ND];
int count,dim;
void main(int na,char **av)
{ double de,test,atof(),*pp,cc;
  double frb(double *x),fchqad(double *x);
  double f4d(double *x),fhv(double *x);
  double (*func[4])();
  int n,max,it,kf,j;
  func[0]=frb; func[1]=fhv; func[2]=f4d; func[3]=fchqad;
  printf("     Test of Optimizer\n");
  if(na<2){ fprintf(stderr,"para func_flag range 0 to 3\n"); exit(1);}
  max=60; de=1.e-9; test=1.e-14;
  printf(" max= %d  de= %8.2e\n",max,de);
  printf(" convergence threshold = %8.2e\n",test);
  kf=atoi(*++av);
  if(kf==0){ n=2; printf("Rosenbrock\n\n");}
  else if(kf==1){ n=3; printf("Helical Valley\n\n");}
  else if(kf==2){ n=4; printf("4 Dimensional\n\n");}
  else{
    fprintf(stderr," enter dimension "); scanf("%d",&dim); n=dim;
    printf("Tchebycheff {dimension=%d}\n\n",dim);
   }
  if(kf<3){
    fprintf(stderr," enter %d components of initial vector\n",n);
    for(j=0,pp=x; j<n ;j++) scanf("%lf",pp++);
   }
  else for(j=0,cc=dim+1; j<n ;j++) x[j]=(j+1)/cc;
  printf(" initial x-vector :\n");
  matprt(x,1,n,"%f ");
  count=0;
  if((it=optmiz(x,n,func[kf],de,test,max))==0)
     printf("\n convergence failure with\n");
  else{
    printf("     optimal solution\n");
    printf(" number of iterations = %d\n",it);
    printf(" function evaluations = %d\n",count);
    printf(" x-vector :\n");
    matprt(x,1,n,"%f ");
    printf("   F(x) = %e\n",(*func[kf])(x));
   }
}
