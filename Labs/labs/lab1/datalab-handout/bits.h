/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* We do support the IEC 559 math functionality, real and complex.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
int bitAnd(int, int);
int test_bitAnd(int, int);
int bitNor(int, int);
int test_bitNor(int, int);
int upperBits(int);
int test_upperBits(int);
int allEvenBits();
int test_allEvenBits();
int byteSwap(int, int, int);
int test_byteSwap(int, int, int);
int logicalShift(int, int);
int test_logicalShift(int, int);
int bitParity(int);
int test_bitParity(int);
int tmin();
int test_tmin();
int isNegative(int);
int test_isNegative(int);
int sign(int);
int test_sign(int);
int isEqual(int, int);
int test_isEqual(int, int);
int divpwr2(int, int);
int test_divpwr2(int, int);
int isLessOrEqual(int, int);
int test_isLessOrEqual(int, int);
int conditional(int, int, int);
int test_conditional(int, int, int);
int addOK(int, int);
int test_addOK(int, int);
