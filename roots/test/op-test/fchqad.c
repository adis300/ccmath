/*  fchqad.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
double fchqad(double *x)
{ extern int count,dim;
  double y[50],tf[50],tfm[50];
  int j,k; double t,del,f;
  ++count;
  for(j=0,del=0.0; j<dim ;j++){
     y[j]=2.*x[j]-1.0; del+=y[j];
     tf[j]=y[j]; tfm[j]=1.0; }
  f=del*del;
  for(j=2; j<=dim ;j++){
     for(k=0,del=0.0; k<dim ;k++){
        t=2.*y[k]*tf[k]-tfm[k];
        del+=t; tfm[k]=tf[k];
        tf[k]=t; }
     del/=dim; if(j%2==0) del+=1./(j*j-1);
     f+=del*del; }
  return f;
}
