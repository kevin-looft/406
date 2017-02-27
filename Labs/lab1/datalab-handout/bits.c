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
  int a = 0x55;
  int b = a << 8;
  int c = a << 16;
  int d = a << 24;
  int base = a | b | c | d;
  int compared = base & x;
  compared = compared << 1;
  compared = compared ^ base;
  compared = 1 + compared;
  return !(compared);
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
    int x = 0x12345678;
	int n = 3; //0, 1, 2, 3
	int m = 1; //3, 2, 1, 0
	int a = 0xFF;	    //0000 0000 0000 0000 0000 0000 1111 1111	
	int b = 0xFF <<  8; //0000 0000 0000 0000 1111 1111 0000 0000
	int c = 0xFF << 16; //0000 0000 1111 1111 0000 0000 0000 0000
	int d = 0xFF << 24; //1111 1111 0000 0000 0000 0000 0000 0000
	printf("a: %p\n" , a);
	printf("b: %p\n" , b);
	printf("c: %p\n" , c);
	printf("d: %p\n" , d);
	
	//x = 0x12345678
	int x0 = x & a;// 0 0 0 0 0 0 7 8
	int x1 = x & b;// 0 0 0 0 5 6 0 0
	int x2 = x & c;// 0 0 3 4 0 0 0 0
	int x3 = x & d;// 1 2 0 0 0 0 0 0
	printf("x0: %p\n" , x0);
	printf("x1: %p\n" , x1);
	printf("x2: %p\n" , x2);
	printf("x3: %p\n" , x3);
	
	int diffNM = m + (~n + 1); // == m - n == 1, 2, 3
	printf("diffNM: %d\n" , diffNM);
	
	int nShift = n << 3; // 0=0; 1=8; 2=16; 3=24;
	printf("nShift: %d\n" , nShift);
	int nByte = (0xFF << nShift) & x;// 0 0 0 0 5 6 0 0
	printf("nByte: %p\n" , nByte);
	
	//======
	int nRightShift = 0;
	int nLeftShift = 0; //(diffNM << 3)
	int nShifted = nByte >> nRightShift;
	nShifted = nShifted << nLeftShift;
	printf("nShifted: %p\n" , nShifted);
	
	
	//======
	int mShift = m << 3;
	printf("mShift: %d\n" , mShift);
	int mByte = (0xFF << mShift) & x;// 1 2 0 0 0 0 0 0
	printf("mByte: %p\n" , mByte);
	int mShiftedDirty = mByte >> (diffNM << 3);
	int mShifted = mShiftedDirty & (0xFF << nShift);
	printf("mShifted: %p\n" , mShifted);
	
	int base = (0xFF << nShift) | (0xFF << mShift);
	printf("base: %p\n", base);
	int negBase = ~base;
	printf("negBase: %p\n", negBase);
	int xCleared = x & negBase;
	printf("xCleared: %p\n", xCleared);
	int swapped = xCleared | nShifted | mShifted;
	printf("swapped: %p\n", swapped);
	
	//===================================
	
  int nShift = n << 3; // 0=0; 1=8; 2=16; 3=24;                                                                                                                                                                                                                               
  int nByteMarker = 0xFF << nShift;
  int nByte = nByteMarker & x;// 0 0 0 0 5 6 0 0                                                                                                                                                                                                                              
  int mShift = m << 3;
  int mByteMarker = 0xFF << mShift;
  int mByte = mByteMarker & x;// 1 2 0 0 0 0 0 0                                                                                                                                                                                                                              

 int base = (0xFF) | (0xFF << 8) | (0xFF << 16);
  nByte = (nByte | (nByte >> 8)) & base;
  nByte = (nByte | (nByte >> 16));
  nByte = nByte & 0xFF;
  mByte = (mByte | (mByte >> 8)) & base;
  mByte = (mByte | (mByte >> 16));
  mByte = mByte & 0xFF;
  
  nByte = nByte << mShift;
  mByte = mByte << nShift;

  int xCleared = x & ~(nByteMarker| mByteMarker);
  return xCleared | nByte | mByte;


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
  int xShifted = x >> n;
  int base = ((!!n) << 31) ^ (~0);
  int shift = n + (~0);
  base = base >> shift;
  //  int result = base & xShifted;                                                                                                                                                                                                                                           
  return xShifted & base;
}
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
  return 2;
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
   return !!(x & (1 << 31));
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
  int intMin = 1 << 31;
  int isNeg = !!(x & intMin);// x<0 -> 1; x>=0 -> 0
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
  int bias = (x >> 31) & (!!n << n);
  int edge = !((1 << 31) ^ ~x) + ~(!((x>>31)&1))+1;
  printf("edge: %d\n", edge);
  printf("bias: %d\n", bias);
  int res = (x + bias + (~bias + 1)) >> n;
  printf("res: %d\n", res);
  //=========
  
  
  int bias = (x >> 31) & (!!n << n);
  printf("bias: %d\n", bias);
  int res = (x + bias) >> n;
printf("res: %d\n", res);
	
	
	(-2147483647[0x80000001],2[0x2]) failed...
...Gives -536870912[0xe0000000]. Should be -536870911[0xe0000001]

	//==============================
	int div = x >> n;
  printf("div: %d\n", div);
  int isNeg = !!(x & (1 << 31));
  printf("neg: %p\n", isNeg);
  int negXAndZeroN = ((x >> 31) & 1) & (1 << n);
  printf("negXAndZeroN: %d\n", negXAndZeroN);
  int res = div + isNeg;
  printf("res: %d\n", res);
  res = res + (~negXAndZeroN + 1);
  printf("Res: %d\n", res);
  
  ERROR: Test divpwr2(-2147483648[0x80000000],1[0x1]) failed...
...Gives -1073741823[0xc0000001]. Should be -1073741824[0xc0000000]

  
  int div = x >> n;
  int xIsNeg = !!(x & (1 << 31));
  int negXAndZeroN = xIsNeg & (1 << n);
  int res = div + xIsNeg + (~negXAndZeroN + 1);
  return res;

  //==============
  (x + ((x >> 31) & ((1 << n) + ~0))) >> n;
  
  //Pos, add 0
  int xNeg = x >> 31;
  //Neg and 0, add 0
  //Neg and +, add 1
  int negXAndZeroN = !((x >> 31) & (1 << n));
  int xPos = !((x >> 31) & 1);
  int res = div + negXAndZeroN + (~xPos + 1)
  //============================
  


}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
	ERROR: Test isLessOrEqual(-2147483648[0x80000000],2147483647[0x7fffffff]) failed...
...Gives 0[0x0]. Should be 1[0x1]

	//Find most significant 1 between the two
	int mostSig1 = x ^ y;
	mostSig1 |= mostSig1 >> 1;
	mostSig1 |= mostSig1 >> 2;
	mostSig1 |= mostSig1 >> 4;
	mostSig1 |= mostSig1 >> 8;
	mostSig1 |= mostSig1 >> 16;
	//Logically shift right 1
	int rightShift1 = ~((mostSig1 >> 1) & (1 << 30));
	//Yields most significant 1
	mostSig1 = mostSig1 & rightShift1;
	mostSig1 = mostSig1 & (x ^ (1 << 31)) & (y ^ ((1 << 31)^((1<<31)>>31));
	return !mostSig1;
	
	
	int firstShifted = ~((first1 >> 1) & (1 << 30));
	first1 = first1 & (~first1 >> 1);
	int isY = !!(first1 & y); 
	int isX = !!(first1 & x);
	int res = !isX;

	
	
  //x <= y ==> 0 <= y - x                                                                                                                                                                                                                                                     
 // int diff = y + (~x + 1);
 // printf("diff: %d\n", diff);
  
 // int intMin = 1 << 31;
 // int isIntMin = !(x + (~intMin + 1));
  //diff += isIntMin;
  
  
  //Test if diff is negative                                                                                                                                                                                                                                                  
 // int isNeg = !(diff & (1 << 31));
 // printf("isNeg: %d\n", isNeg);                                                                                                                                                                                                                                                        
 // return isNeg;

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
  printf("x: %d\n", x);
  int mask = (condition + ~0);
    printf("mask: %d\n", mask);
  int result = (y & (mask)) + (z & ~(mask));
  printf("result: %d\n", result);
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
  int negIntsPosSum = xNeg & yNeg & !sumNeg;
  int posIntsNegSum = !xNeg & !yNeg & sumNeg;
  return negIntsPosSum + posIntsNegSum;  
}
