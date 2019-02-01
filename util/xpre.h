/*  xpre.h    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#define NX 7
struct xpr {unsigned short nmm[NX+1];};
struct xpr xadd(),xmul(),xdiv();
struct xpr dubtox(),inttox(),sfmod(),xpwr(),xpr2();
double xtodub();
struct xpr xneg(),xabs(),xfrex(),xfmod();
