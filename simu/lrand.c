/*  lrand.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
static unsigned int s;
unsigned int lrana(unsigned int);
unsigned int lrand()
{ return (s=lrana(s));
}
void setlrand(unsigned int u)
{ s=u;
}
