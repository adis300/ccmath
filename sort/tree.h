/*  tree.h    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#ifndef NULL
#define NULL 0L
#endif
#ifdef BAL
struct tnode {char *key,*rec; int bal; struct tnode *pr,*pl;};
#else
struct tnode {char *key,*rec; struct tnode *pr,*pl;};
#endif
