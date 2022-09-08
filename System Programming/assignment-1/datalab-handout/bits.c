/*
 * CS:APP Data Lab
 *
 * <Azizbek Umidjonov ID: 20202043>
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
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


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

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

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
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
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
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
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
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/*
//1
#include "bitXor.c"
#include "tmin.c"

//2
#include "isTmax.c"
#include "allOddBits.c"
#include "negate.c"

//3
#include "isAsciiDigit.c"
#include "conditional.c"
#include "isLessOrEqual.c"

//4
#include "logicalNeg.c"
#include "howManyBits.c"

//float
#include "floatScale2.c"
#include "floatFloat2Int.c"
#include "floatPower2.c"

//
#include "bitCount.c"
*/
/*
 * floatAbsVal - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */

// TODO: Replace lorem
unsigned floatAbsVal(unsigned uf)
{
  /*
   * Lorem ipsum dolor sit amet consectetur adipisicing elit.Dolorum est
   * commodi ducimus repellendus eos sint beatae praesentium libero
   * deserunt, architecto incidunt.Earum alias dolorem non quibusdam modi
   * perferendis repellendus.Totam.
   */
  unsigned expo = (uf >> 23) & 0xFF;
  unsigned fracc = uf << 9;
  if (expo == 0xFF && fracc != 0x00)
    return uf;

  return uf & ~(1 << 31);
}

/*
 * floatNegate - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */

// TODO: !
unsigned floatNegate(unsigned uf)
{
  /*
   * Since it's two's complement we can negate
   * with the help of leading 1
   * which is uf^10000000000000000000000000000000 (32)
   */
  unsigned e = 0xFF & (uf >> 23);
  unsigned f = uf << 9;
  if (e == 0xFF && f != 0x00)
    return uf;

  return (1 << 31) ^ uf;
}
/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */

// TODO:!

unsigned floatPower2(int x)
{
  /*
   * The maximum range that a floating point number can represent is
   * <2 * 2 ^ (254 - 127)-><2 ^* 128, so X> 127, directly overflowing the minimum range represented
   * by a floating point number X >= 2 ^ (1 - 127) * 2 ^ (-23)is
   * equivalent to X >= 2 ^ -149, so X<-149 directly becomes 0
   * Considering the 2 cases of EXP> 0 and = 0. When EXP> 0, the answer
   * is EXP << 23. Because FRAC is all 0, it represents the range of 1 -
   * 2 ^ 127 EXP = 0, the range of X is[-127, -149], 149, just move 1U to
   * the left by the displacement of FRAC.to the power of 2 ^ -(23 - FRAC)
   */

  int frac = x + 149;
  if (x > 127)
    return 0x7f800000u;
  if (x < -149)
    return 0u;
  if (x >= -126)
  {
    unsigned exp = x + 127;
    return exp << 23;
  }
  return 1u << frac;
}
//#include "floatScale2.c"
//#include "isLess.c"
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */

// TODO:!
int isPower2(int x)
{
  /*
   * If we subtract 1 from the power of 2 what we get is 1s at all the
   * places from the end of the binary number till we will not get 1 set
   * bit. And, if we apply Bitwise AND operator we should only get zeros.
   */
  int a = x & (x - 1);

  //! Honestly I don't know why this works
  //! x <= 0? 0:!(x & (x - 1)); would be much simpler version
  //! if we were allowed to use if statements
  int b = ((!(x >> 31)) & (~(!x)));
  return (!a) & b;
}
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */

// TODO:!
int logicalNeg(int x)
{
  /*
   * In most implementations, a right shift on a signed integer is
   * usually an arithmetical shift(e.g.the sign bit is copied over).As a
   * result, right shift x and its negation by 31. One of those two will
   * be a negative value, resulting in 0xFFFFFFFFFF when right shifted by
   * 31(of course, if x = 0, the right shift will result in 0x0, which is
   * what we want).Because we don't know whether x or its negation is
   * a negative integer, we simply OR them together to achieve what we
   * want. Then we can add 1.
   */

  return ((x >> 31) | ((~x + 1) >> 31)) + 1;
}
/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */

//* TODO: !
int logicalShift(int x, int n)
{
  /*
   *   First we need to convert it to unsigned int to make sure that
   *   the left most interger is 0 since it's two's complement.
   *   After that we can safely shift it by n and type case again
   */
  int m = ~(-1 << n) << (32 - n);
  return ~m & ((x >> n) | m);
}
/*
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */

// TODO: !
int replaceByte(int x, int n, int c)
{
  /*
   * Mask out current byte value and OR in replacement
   */
  //* Store whole byte n in a by shifting by 3
  int byte = n << 3;

  //* Mask of 1's that shifts by a byte
  int mask = 0xFF << byte;

  //* Shift bytes
  int shift = c << byte;

  //* replace with the byte c that you wanted to add by using mask and OR
  return shift | (~mask & x);
}
/*
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x187654321
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3
 */
// TODO:!
int rotateRight(int x, int n)
{
/*
 * n % 32: prevent from right shifting more than int width
 * >>: right shift by n bits
 * (32-n) % 32: prevent from left shifting more than int width
 * <<: shift the bits to rotate all the way to the left
 * |: combine left and right shifted results
 */
#include <limits.h>

  unsigned unsigned_x = x;
  unsigned unsigned_n = n;
  unsigned_n %= (sizeof(int) * CHAR_BIT);
  unsigned y = unsigned_x >> unsigned_n;
  if (unsigned_n > 0)
    y |= unsigned_x << ((sizeof(int) * CHAR_BIT) - unsigned_n);

  return y;
}
/*
 * satMul2 - multiplies by 2, saturating to Tmin or Tmax if overflow
 *   Examples: satMul2(0x30000000) = 0x60000000
 *             satMul2(0x40000000) = 0x7FFFFFFF (saturate to TMax)
 *             satMul2(0x80000001) = 0x80000000 (saturate to TMin)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
// TODO: !satMul2
int satMul2(int x)
{
  //! I give up on this one.
  return 0;
}
/*
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */

// TODO: !
int sign(int x)
{
  /*
   * The signed shift n>>31 converts every negative number into -1 and
   * every other into 0.
   * When we do a -n>>31, if it is a positive number then it will return * -1 as we are doing -n>>31 and the vice versa when we do for a
   * negative number.
   * But when we do for 0 then n>>31 and -n>>31 both returns 0
   */
  return (x >> 31) - (-x >> 31);
}
//#include "subtractionOK.c"
/*
 * thirdBits - return word with every third bit (starting from the LSB) set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
// TODO: !
int thirdBits(void)
{
  //! Didn't get a thing why we're doing it
  int temp1 = 0x49;          //* 0000 0000 0000 0000 0000 0000 0100 1001
  int shift = temp1 << 9;    //* 0000 0000 0000 0000 1001 0010 0000 0000
  int temp2 = shift | temp1; //* 0000 0000 0000 0000 1001 0010 0100 1001
  //! shift by (4*3+6)
  int shift2 = temp2 << 18; //* 0100 1001 0010 0100 0000 0000 0000 0000

  return temp2 | shift2; //* 0100 1001 0010 0100 1001 0010 0100 1001
}
/*
 * upperBits - pads n upper bits with 1's
 *  You may assume 0 <= n <= 32
 *  Example: upperBits(4) = 0xF0000000
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 1
 */
// TODO:!
int upperBits(int n)
{
  /*
   * If there is a leading one, push one over to the most essential bit, * because it's arythmetic >>, it'll be full with ones. n&1 - unless
   * in the case of 0. (first number determined)
   */
  return ((!!n & 1) << 31) >> (n + ~0);
}
