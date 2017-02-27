/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
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
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
       return ~(~x | ~y);
}
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
  return (~x & ~y);
}
/* 
 * upperBits - pads n upper bits with 1's
 *  You may assume 0 <= n <= 32
 *  Example: upperBits(4) = 0xF0000000
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 1
 */
int upperBits(int n) {
  //Start with 0x1000...0000
  int base = (!!n) << 31;
  //Shift by n-1; special case for n=0
  int shift = n + (~0) + (!n);
  int padded = base >> shift;
  return padded;
}
/* 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) {
  //Start with 1 at all even bits
  int base = 0x55;
  base = base | (base << 8);
  base = base | (base << 16);  
  int compared = base & x;
  compared = compared << 1;
  compared = compared ^ base;
  compared = 1 + compared;
  return !compared;
  
  //====
  //Start with 1 at all even bits; 0x55555555                                                                                                                                     
  int base = 0x55;
  int compared;
  base |= (base << 8);
  base |= (base << 16);
  compared = base & x;
  //If all even bits, we should be left with the base, meaning subtraction = 0.                                                                                                   
  return !(compared + (~base + 1));


}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
  //Get bytes at n&m; clear the rest.
  int nShift = n << 3;
  int mShift = m << 3;
  int nByteMarker = 0xFF << nShift;
  int nByte = x & nByteMarker;
  int mByteMarker = 0xFF << mShift;
  int mByte = x & mByteMarker;

  //Move n&m to byte position 0
  nByte = (nByte >> nShift) & 0xFF;
  mByte = (mByte >> mShift) & 0xFF;

  //Shift byte n to postion m; m to position n
  nByte = nByte << mShift;
  mByte = mByte << nShift;
  
  //Clear original x at bytes n and m
  int xCleared = x & ~(nByteMarker | mByteMarker);
  return (xCleared | nByte | mByte);
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  //Shift arithmatically and remove padded 1s                                                                                                                                     
  int shifted = x >> n;
  int base = (!!n) << 31 ^ (~0);
  int shift = n +(~0);
  base = base >> shift;
  return shifted & base;
}
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
  //Shift down to the last bit for comparison
  int res = x ^ (x >> 16);
  res = res ^ (res >> 8);
  res = res ^ (res >> 4);
  res = res ^ (res >> 2);
  res = res ^ (res >> 1);
  //Now the last bit contains the correct parity
  res = res & 1;
  return res;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1 << 31;
}
/* 
 * isNegative - return 1 if x < 0, return 0 otherwise 
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNegative(int x) {
  return (x >> 31) & 1;
}
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
  int isNeg = (x >> 31) & 1;// x<0 -> 1; x>=0 -> 0
  isNeg = ~isNeg + 1;
  isNeg += isNeg;
  return (!!x) + isNeg;
}
/* 
 * isEqual - return 1 if x == y, and 0 otherwise 
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
  return !(x ^ y);
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
  //Handle case of x<0 and n=0
  int buffer = (x >> 31) & (!!n << n);
  buffer = !!buffer;
  //  int res = (x + buffer) >> n;
  int xNeg = (x >> 31) & 1;
  if (xNeg) res = res -1;
  return 2;
  //Class
  //(x+2^k-1)/2^k
  
  
  
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int base = 0xFF << 16;
  base = base | (base << 15);
  printf("base: %d\n", base);
  int xFirst1 = x ^ ((x >> 1) & base);
  int yFirst1 = y ^ ((y >> 1) & base);
	
	
  int first1 = x ^ y;
  first1 |= first1 >> 1;
  first1 |= first1 >> 2;
  first1 |= first1 >> 4;
  first1 |= first1 >> 8;
  first1 |= first1 >> 16;
  int isY = !!(first1 & y); 
  int isX = !!(first1 & x);
  int xyEqual = !!(isY + (~isX + 1));
  
  //  int shifted = ~((first1 >> 1) & (1 << 30));
  //first1 = first1 & shifted;
  
  //int res = !isX;
  // int rightShift1 = ~((first1 >> 1) | (1 << 30));
  //Yields most significant 1
  //first1 = first1 & rightShift1;
  //first1 = first1 & (x ^ (1 << 31)) & (y ^ ((1 << 31)^((1<<31)>>31)));
  //===============================
  
  int help = ~(1 << 31);
  int leftMostIsNeg, yIsLeftMost, xIsLeftMost, isBoth, result;
  int leftMost = x ^ y;
  leftMost = leftMost | (leftMost >> 1);
  leftMost = (leftMost | (leftMost >> 2));
  leftMost = (leftMost | (leftMost >> 4));
  leftMost = (leftMost | (leftMost >> 8));
  leftMost = (leftMost | (leftMost >> 16));
  leftMost = leftMost ^ ((leftMost >> 1) & help);

  leftMostIsNeg = (leftMost >> 31) & 1;
  yIsLeftMost = !(leftMost & x);//--> 0                                                                                                                                           
  xIsLeftMost = !(leftMost & y);//--> 1                                                                                                                                           
  isBoth = !(leftMost);//--> 1                                                                                                                                                    
  result = isBoth | (yIsLeftMost & !leftMostIsNeg) | (xIsLeftMost & leftMostIsNeg);
  return result;
  
  
  //=========
  int areEqual = !(x ^ y);
  printf("areEqual: %d\n", areEqual);
  int signX = (x >> 31) & 1;
  printf("signX: %d\n", signX);
  int signY = (y >> 31) & 1;
  printf("signY: %d\n", signY);
  int sameSign = !(signX ^ signY);
  printf("sameSign: %d\n", sameSign);
  int sameSignMask = (sameSign << 31) >> 31;
  printf("sameSignMask: %p\n", sameSignMask);
  //For same sign:
  //y - x >= 0; return 1
  //y - x < 0; return 0
  int diff = y + (~x + 1);
  printf("diff: %d\n", diff);
  //int diffWeCareAbout = sameSignMask & diff;
  //int diffWeCareAboutSign = diffWeCareAbout >> 31;
  int diffNegWhenSignsSame = sameSignMask & ((diff >> 31) & 1);
  printf("diffNegWhenSignsSame: %d\n", diffNegWhenSignsSame);
  //For opposite signs, is Y positive or negative?
  int diffSignMask = ~sameSignMask;
  printf("diffSignMask: %p\n", diffSignMask);
  int xNegWhenSignsDif = diffSignMask & (!sameSign ^ signX);
  printf("xNegWhenSignsDif: %d\n", xNegWhenSignsDif);
  
  int res =  areEqual | xNegWhenSignsDif | diffNegWhenSignsSame;
  printf("res: %d\n", res);
  
  //==========
  int x = 0x80000000;
  int y = 0x7FFFFFFF;

  //  int help = ~(1 << 31);                                                                                                                                                                                                                                                  
  //int leftMostIsNeg, yIsLeftMost, xIsLeftMost, isBoth, result;                                                                                                                                                                                                              
  //int leftMost = x ^ y;                                                                                                                                                                                                                                                     
  //leftMost = leftMost | (leftMost >> 1);                                                                                                                                                                                                                                    
  //leftMost = (leftMost | (leftMost >> 2));                                                                                                                                                                                                                                  
  //leftMost = (leftMost | (leftMost >> 4));                                                                                                                                                                                                                                  
  //leftMost = (leftMost | (leftMost >> 8));                                                                                                                                                                                                                                  
  //leftMost = (leftMost | (leftMost >> 16));                                                                                                                                                                                                                                 
  //leftMost = leftMost ^ ((leftMost >> 1) & help);                                                                                                                                                                                                                           
  //leftMostIsNeg = (leftMost >> 31) & 1;                                                                                                                                                                                                                                     
  //yIsLeftMost = !(leftMost & x);//--> 0                                                                                                                                                                                                                                     
  //xIsLeftMost = !(leftMost & y);//--> 1                                                                                                                                                                                                                                     
  //isBoth = !(leftMost);//--> 1                                                                                                                                                                                                                                              
  //result = isBoth | (yIsLeftMost & !leftMostIsNeg) | (xIsLeftMost & leftMostIsNeg);                                                                                                                                                                                         
  //return result;                                                                                                                                                                                                                                                            

  int equal = !(x ^ y);
  int signX = (x >> 31) ;
  int signY = (y >> 31) ;
  int sameSign = !(signX ^ signY);
  int sameSignMask = (sameSign << 31) >> 31;

  int diff = y + (~x +1);
  int diffNegWhenSignsSame = sameSignMask & !((diff >> 31) & 1);

  int diffSignMask = ~sameSignMask;
  int xNegWhenSignsDif = diffSignMask & ((!sameSign) & signX);
  return equal | diffNegWhenSignsSame | xNegWhenSignsDif;


}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int condition = !x;
  int mask = condition + ~0;
  int result = (y & mask) + (z & ~mask);
  return result;
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
  int sum = x + y;
  //Pos, 0 --> 0; Neg --> 1
  int xNeg = (x >> 31) & 1;
  int yNeg = (y >> 31) & 1;
  int sumNeg = (sum >> 31) & 1;
  int res = (xNeg & yNeg) + (~sumNeg + 1);
  
  int negIntsPosSum = xNeg & yNeg & !sumNeg;
  int posIntsNegSum = !xNeg & !yNeg & sumNeg;
  return !(negIntsPosSum + posIntsNegSum);
}
