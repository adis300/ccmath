/*  hval.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
int hval(char *key,int mh)
{ int hv;
  for(hv=0; *key!='\0' ;) hv+= *key++;
  return hv%mh;
}
