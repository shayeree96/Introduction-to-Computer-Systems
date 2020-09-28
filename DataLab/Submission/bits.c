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
 
  long Funct(long arg1, long arg2, ...) {
      /* brief description of how your implementation works */
      long var1 = Expr1;
      ...
      long varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. (Long) integer constants 0 through 255 (0xFFL), inclusive. You are
      not allowed to use big constants such as 0xffffffffL.
  3. Function arguments and local variables (no global variables).
  4. Local variables of type int and long
  5. Unary integer operations ! ~
     - Their arguments can have types int or long
     - Note that ! always returns int, even if the argument is long
  6. Binary integer operations & ^ | + << >>
     - Their arguments can have types int or long
  7. Casting from int to long and from long to int
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting other than between int and long.
  7. Use any data type other than int or long.  This implies that you
     cannot use arrays, structs, or unions.
 
  You may assume that your machine:
  1. Uses 2s complement representations for int and long.
  2. Data type int is 32 bits, long is 64.
  3. Performs right shifts arithmetically.
  4. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31 (int) or 63 (long)

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 63
   */
  long pow2plus1(long x) {
     /* exploit ability of shifts to compute powers of 2 */
     /* Note that the 'L' indicates a long constant */
     return (1L << x) + 1L;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 63
   */
  long pow2plus4(long x) {
     /* exploit ability of shifts to compute powers of 2 */
     long result = (1L << x);
     result += 4L;
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
//1
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(
 L, 5L) = 7L
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
long bitOr(long x, long y) 
{ 
  long z=(~(~x&~y));
  return z;
}
/* 
 * specialBits - return bit pattern 0xffffffca3fffffffL
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 3
 *   Rating: 1
 */
long specialBits(void) {
  
  long A=0xd7;  
  return ~(A<<30);

}
//2
/*
 * isZero - returns 1 if x == 0, and 0 otherwise 
 *   Examples: isZero(5L) = 0L, isZero(0L) = 1L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
long isZero(long x) 
{
  return !x;
}
/* 
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   where bits are numbered from 0 (least significant) to 63 (most significant)
 *   Examples anyEvenBit(0xAL) = 0L, anyEvenBit(0xEL) = 1L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 14
 *   Rating: 2
 */
long anyEvenBit(long x) {

  long A=0x55L;
  long B=A<<24|A<<16|A<<8|A;
  long C=B<<32;
  long D=C|B;
  
  return !(!(D&x)) ;

}
/* 
 * negate - return -x 
 *   Example: negate(1L) = -1L.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
long negate(long x) {
  return ~x+1;
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96L) = 0x20L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */
long leastBitPos(long x) {
  return (~x+1)&x;
}
//3
/* 
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 63
 *   Examples:
 *      rotateLeft(0x8765432187654321L,4L) = 0x7654321876543217L
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
long rotateLeft(long x, long n) {
  return (x<<n)+((x>>(64+(~n+1)))&((0x1L<<n)+(~0x0L)));
}
/* 
 * dividePower2 - Compute x/(2^n), for 0 <= n <= 62
 *  Round toward zero
 *   Examples: dividePower2(15L,1L) = 7L, dividePower2(-33L,4L) = -2L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
long dividePower2(long x, long n) {
   return (x + ((x >> 63L) & ((1L << n) + ~0L))) >> n;
}
/* 
 * isLess - if x < y  then return 1, else return 0 
 *   Example: isLess(4L,5L) = 1L.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
long isLess(long x, long y) {
 long check1=x&~y;//Checks for MSBs mismatch
 long check2=(x^y);//Compares and filters the off positions
 long check3=(y+~x); 
 
 return( (check1|~(check2|check3))>>63) & 1;
}
//4
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5L) = 0L, isPower2(8L) = 1L, isPower2(0) = 0L
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
long isPower2(long x) {
  return !(((((~x+1)&x)^x)|((x>>63)&1L))|(!(~x^(~0x0L))));
}
/*
 * bitReverse - Reverse bits in a 64-bit word
 *   Examples: bitReverse(0x8000000200000000L) = 0x0000000040000001L
 *             bitReverse(0x0000000089ABCDEFL) = 0xF7D3D59100000000L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 80
 *   Rating: 4
 */
long bitReverse(long x) {
    long mask1,mask3_l,mask3_r,mask2_l,mask2_r,mask1_r,mask1_l,mask4_r,mask4_l,mask5_r,mask5_l,mask6_r,mask6_l;
	mask1=0xffL;
	mask3_l=(mask1<<8)<<16|mask1<<8;
    	mask3_l=mask3_l<<32|mask3_l;
    	mask3_r=~mask3_l;
	mask1=mask1<<8|mask1;
     
     mask2_l=(mask1<<16);
     mask2_l=mask2_l<<32|mask2_l;
     mask2_r=~mask2_l;
     mask1=mask1<<16|mask1;
     mask1_r=mask1;
     mask1_l=~mask1_r;

     mask4_l=0xf0;
     mask4_l=mask4_l<<8|mask4_l;
     mask4_l=mask4_l<<16|mask4_l;
     mask4_l=mask4_l<<32|mask4_l;
     mask4_r=~mask4_l;
     
     mask5_l=0xCC;
     mask5_l=mask5_l<<8|mask5_l;
     mask5_l=mask5_l<<16|mask5_l;
     mask5_l=mask5_l<<32|mask5_l;
     mask5_r=~mask5_l;

     mask6_l=0XAA;
     mask6_l=mask6_l<<8|mask6_l;
     mask6_l=mask6_l<<16|mask6_l;
     mask6_l=mask6_l<<32|mask6_l;
     mask6_r=~mask6_l;

     //Now first reverse
     x=((x&mask1_l)>>32L&mask1_r)|(x&mask1_r)<<32L;
     x=((x&mask2_l)>>16L&mask2_r)|(x&mask2_r)<<16L;
     x=((x&mask3_l)>>8L&mask3_r)|(x&mask3_r)<<8L;
     x=((x&mask4_l)>>4L&mask4_r)|(x&mask4_r)<<4L;
     x=((x&mask5_l)>>2L&mask5_r)|(x&mask5_r)<<2L;
     x=((x&mask6_l)>>1L&mask6_r)|(x&mask6_r)<<1L;
     //printf("Switched 32 bits:%lx\n ",x);
     return x;
    
}
//float
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
  *   for floating point argument f.    

 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
    
}
/* 
 * floatInt2Float - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatInt2Float(int x) {
	unsigned int sign_bit,exp,frac,bias,E,comp,V,V_final,LSB,M,count;

	sign_bit=x>>31;
	exp=(x&0x7f800000)>>23;
	bias=127;
        frac=x<<9;
	if (exp==0xff ||exp>bias+31)
		return 0;
        else if(exp==0 )
        {
	E=1-bias;
        if (E >= 31)
	   return 0;
        else
	{
        M=frac>>1;
	LSB=(~M+1)&M;

	count=0;
            while(LSB>>1L!=0x1L)
            {
              LSB=LSB>>1L;
              count++;
	    }
 	comp=count-31+1;
	V=(M>>31+comp);
            if (sign_bit!=0)
                 V=~V+1;
	V_final=(V>>(E+comp));
        }
        }
    else
    {
     E=exp-bias;
        if (E >= 31)
            return 0;
        else
        {
        M=frac>>1|0x80000000;
        comp=~E+1;
        V=(M>>31+comp);
        if (sign_bit!=0)
            V=~V+1;
     V_final=(V>>(E+comp));
     }
    }
    return V_final;
  }
/*
* floatIsEqual - Compute f == g for floating point arguments f and g.
*   Both the arguments are passed as unsigned int's, but
*   they are to be interpreted as the bit-level representations of
*   single-precision floating point values.
*   If either argument is NaN, return 0.
*   +0 and -0 are considered equal.
*   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
*   Max ops: 25
*   Rating: 2
*/
int floatIsEqual(unsigned uf, unsigned ug) {
    
  
  if(!(uf&0x7fffffff) && !(ug&0x7fffffff))//Checks exponent and frac part without MSB
	return 1;
  if((uf&0x7fffffff) > 0x7f800000)//Check for Nan for uf
	return 0;
  if((ug&0x7fffffff) > 0x7f800000) //Check for Nan for ug
	return 0;
  return uf == ug;
}
