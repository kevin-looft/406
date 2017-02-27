#include <stdio.h>
#include <stdlib.h>

// Problem 1
long sum(long a[], long n) {
  // implement this
  long sum = 0;
  long i;
  for (i = 0; i < n; i++) {
    sum += a[i];
  }
  return sum;
}


// Problem 2
long decode2 (long x, long y, long z) {
  long a = x;
  long b = a - z;
  long c = x * b;
  long d = b << 63;
  long e = d >> 63;
  long f = e ^ c;
  long g = f + y;
  
  return g;
}

// Problem 3
// Write here AS A COMMENT the assembly code corresponding to
// the body of the for loop you implemented in function sum
//
// Below, .L2 contains the comparison of whether to enter the loop again,
// while .L3 contains the action of adding the to the sum and also incrementing i 
//
//  .L3:
//       addq    (%rdi,%rdx,8), %rax
//       addq    $1, %rdx
//  .L2:
//       cmpq    %rsi, %rdx
//       jl      .L3
//


void main () {
  // test function sum implementation; do not modify!

  long a[8] = {10, 8, 6 , 4, 2, 0, -2, -4};
  printf("sum(a, 8) = %d\n", sum(a, 8));
}
