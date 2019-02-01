/*  bpat.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*  Version for ieee format and DOS byte order */
void bitpc(unsigned char x)
{ unsigned char t; int j,m;
  m=sizeof(char)<<3; t=1<<(m-1);
  for(j=0; j<m ;++j,t>>=1){
    if(x&t) printf("1"); else printf("0");}
  printf("\n");
}

void bitps(unsigned short x)
{ unsigned short t; int j,m;
  m=sizeof(short)<<3; t=1<<(m-1);
  for(j=0; j<m ;++j,t>>=1){
    if(x&t) printf("1"); else printf("0");}
  printf("\n");
}

void bitpl(unsigned int x)
{ unsigned int t; int j,m;
  m=sizeof(int)<<3; t=1L<<(m-1);
  for(j=0; j<m ;++j,t>>=1){
    if(x&t) printf("1"); else printf("0");}
  printf("\n");
}

void bitpf(float x)
{ unsigned char t,u,*p; int j,m;
  m=sizeof(float); t=u=0x80;
  p=(unsigned char *)&x;
  p+=m-1; m<<=3;
  for(j=0; j<m ;++j){
	if(*p&t) printf("1"); else printf("0");
	if(j==8) printf("^");
	if((t>>=1)==0){ t=u; --p;}
   }
  printf("\n");
}

void bitpd(double x)
{ unsigned char t,u,*p; int j,m;
  m=sizeof(double); t=u=0x80;
  p=(unsigned char *)&x;
  p+=m-1; m<<=3;
  for(j=0; j<m ;++j){
    if(*p&t) printf("1"); else printf("0");
    if(j==11) printf("^");
    if((t>>=1)==0){ t=u; --p;}
   }
  printf("\n");
}
