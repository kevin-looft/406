#include <stdio.h>

/*  
#1. 0xFEBADC98 = 1111 1110 1011 1010 1101 1100 1001 1000

#2. 1010 1111 0101 0011 1011 1001 1000 1010 = 0xAF53B98A

#3. 0x0000AB = 10*(16^1) + 11*(16^0) = 171

#4. 1111 1110 = 128 + 64 + 32 + 16 + 8 + 4 + 2 = 254
*/
int prob259(int x, int y){
  int leastSigX = 0xFF & x;
  int remainingY = 0xFFFFFF00 & y;
  return leastSigX | remainingY;
}

unsigned replace_byte(unsigned x, int i, unsigned char b) {
  int shift = i * 8;
  printf("shift: %d\n", shift);
  int replace = b << shift;
  printf("replace: %d\p", replace);
  int a = (0xFF << shift) ^ (0xFFFFFFFF);
  int xByteRemoved = (a) & x;
  printf("xByteRemoved: %d\n", xByteRemoved);
  int xByteReplaced = xByteRemoved | replace;
  printf("xByteReplaced: %d\n", xByteReplaced);
  return xByteReplaced;
   
}

int prob261A(int x){
  return !!(x & ~0);
  //Class
  //return !!x;
}

int prob261B(int x){
  return !(x == ~0);
  //Class
  //return !!(~x);
}

int prob261C(int x){
  int leastSigByte = 0xFF;
  return !!(x & leastSigByte);
  
}

int leftmost_one(unsigned x){
  //Assuming w=32 max
  x = x | (x >> 1);
  x = x | (x >> 2);
  x = x | (x >> 4);
  x = x | (x >> 8);
  x = x | (x >> 16);
  //x should now have all 1s following it's leftmost 1
  int leftMost = x ^ (x >> 1);
  return leftMost;
}

int lower_one_mask(int n){
  //Using 32, assming n is of type int.
  //Cannot shift by n == w all at once.
  int buffer = (n == 32)
  int start = ~0;
  int shift = n - buffer; 
  int mask = start << shift;
  mask = mask << buffer;
  return ~mask;
  //Class
  //(2 << (n-1))-1; 
} 

int main() {
  // problem 2.59
  printf("\nProblem 2.59:\n");
  int x = 0x89ABCDEF;
  int y = 0x76543210;
  printf("0x%X\n", prob259(x, y));

  // problem 2.60
  printf("\nProblem 2.60:\n");
  printf("0x%X\n", replace_byte(0x12345678, 2, 0xAB));
  printf("0x%X\n", replace_byte(0x12345678, 0, 0xAB));

  // problem 2.61
  printf("\nProblem 2.61:\n");
  printf("%d\n", prob261A(0x8));             // returns 1
  printf("%d\n", prob261B(-1));              // returns 0 
  printf("%d\n", prob261C(0x100));           // returns 0 

  // problem 2.66
  printf("\nProblem 2.66:\n");
  printf("0x%X\n", leftmost_one(0xFF00));
  printf("0x%X\n", leftmost_one(0x6600));

  // problem 2.68
  printf("\nProblem 2.68:\n");
  printf("0x%X\n", lower_one_mask(6));
  printf("0x%X\n", lower_one_mask(17));
  printf("0x%X\n", lower_one_mask(32));
}
