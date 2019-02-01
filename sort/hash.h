/*  hash.h    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#ifndef NULL
#define NULL ((void *)0)
#endif
struct tabl {char *key,*val; struct tabl *pt;};
int hval(char *k,int m);
