/*  xpre.h    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#define XDIM 7
struct xpr {unsigned short nmm[XDIM+1];};
extern unsigned short m_sgn,m_exp;
extern short bias;
extern int itt_div,k_tanh;
extern int ms_exp,ms_trg,ms_hyp;
extern short max_p,k_lin;
extern short d_bias,d_max,d_lex;
extern struct xpr zero,one,two,ten;
extern struct xpr x_huge;
extern struct xpr pi,pi2,pi4;
extern struct xpr ee,srt2,ln2;
struct xpr xadd(struct xpr a,struct xpr b,int k);
struct xpr xmul(struct xpr s,struct xpr t);
struct xpr xdiv(struct xpr s,struct xpr t);
struct xpr atox(char *s);
struct xpr dubtox(double y);
struct xpr inttox(int n);
int xprcmp(struct xpr *p,struct xpr *q);
int neg(struct xpr *p);
int xex(struct xpr *p);
struct xpr sfmod(struct xpr t,int *p);
struct xpr xpwr(struct xpr s,int n);
struct xpr xpr2(struct xpr s,int n);
struct xpr xneg(struct xpr s);
struct xpr xabs(struct xpr s);
struct xpr xfrex(struct xpr s,int *p);
struct xpr xfmod(struct xpr s,struct xpr t,int *p);
double xtodub(struct xpr s);
struct xpr xtan(struct xpr x);
struct xpr xsin(struct xpr x);
struct xpr xcos(struct xpr x);
struct xpr xatan(struct xpr a);
struct xpr xasin(struct xpr a);
struct xpr xacos(struct xpr a);
struct xpr xsqrt(struct xpr u);
struct xpr xexp(struct xpr u);
struct xpr xlog(struct xpr u);
struct xpr xtanh(struct xpr v);
struct xpr xsinh(struct xpr v);
struct xpr xcosh(struct xpr v);
void prxpr(struct xpr u,int m);
void xprint(struct xpr u);
void lshift(int i,unsigned short *p,int k);
void rshift(int i,unsigned short *p,int k);
