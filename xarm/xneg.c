/*  xneg.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include "xpre.h"
struct xpr xneg(struct xpr s)
{ unsigned short *p=(unsigned short *)&s;
  *p^=m_sgn; return s;
}
struct xpr xabs(struct xpr s)
{ unsigned short *p=(unsigned short *)&s;
  *p&=m_exp; return s;
}
int xex(struct xpr *ps)
{ unsigned short *q=(unsigned short *)ps;
  return (*q&m_exp)-bias;
}
int neg(struct xpr *ps)
{ unsigned short *q=(unsigned short *)ps;
  return (*q&m_sgn);
}
