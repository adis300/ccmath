/*  byteord.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
 *     Code to test the byte order used by your
 *     processor.
*/
void main(void)
{ union {char cc[4]; unsigned short m[2]; unsigned u;} x;
  x.u=0x12345678;
  printf("       unsigned: %x\n",x.u);
  printf(" unsigned short: %x %x\n",x.m[0],x.m[1]);
  printf("           char: %x %x %x %x\n",x.cc[0],x.cc[1],x.cc[2],x.cc[3]);
}
/*
      output for a little-endian machine such as the INTEL processors


       unsigned: 12345678
 unsigned short: 5678 1234
           char: 78 56 34 12
*/
