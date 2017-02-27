/* Hello World program */

#include<stdio.h>
//#include<limit.h>

int main()
{
    printf("Homework 1\n\n");

    //factorial1(10);
    //factorial2(10);
    //factorial3(10);
    //int factorial = factorial4(10);
    //printf("factorial4(%d) = %d\n\n\n", 10, factorial);

    types();
}

void ranges() {
	printf("signed char\n");
	printf("minimum value: %d\n", SCHAR_MIN);
	printf("maximum value: %d\n", SCHAR_MAX);
	
	printf("unsigned char\n");
	printf("minimum value: 0\n");
	printf("maximum value: %d\n", UCHAR_MAX);
	
	printf("signed short\n");
	printf("minimum value: %d\n", SHRT_MIN);
	printf("maximum value: %d\n", SHRT_MAX);
	
	printf("unsigned short\n");
	printf("minimum value: 0\n");
	printf("maximum value: %d\n", USHRT_MAX);
	
	printf("signed int\n");
	printf("minimum value: %d\n", INT_MIN);
	printf("maximum value: %d\n\n", INT_MAX);
	printf("unsigned int\n");
	printf("minimum value: 0\n");
	printf("maximum value: %d\n\n", UINT_MAX);
	
	printf("signed long long\n");
	printf("minimum value: %li\n", LONG_MIN);
	printf("maximum value: %li\n\n", LONG_MAX);
	printf("unsigned long\n");
	printf("minimum value: 0\n");
	printf("maximum value: %lu\n\n", ULONG_MAX);
	
	printf("signed long long\n");
	printf("minimum value: %lli\n", LLONG_MIN);
	printf("maximum value: %lli\n\n", LLONG_MAX);
	printf("unsigned long\n");
	printf("minimum value: 0\n");
	printf("maximum value: %llu\n\n", ULLONG_MAX);
	
}

int types() {
  printf("Executing funtion types\n");
  char char1 = 'A';
  char char2 = 'B';
  char char3 = 'C';
  char *a1 = &char1;
  char *a2 = &char2;
  char *a3 = &char3;
  printf("&a1 = %p, %u\n", a1);
  printf("&a2 = %p, %u\n", a2);
  printf("&a3 = %p, %u\n", a3);

  short short1 = 1;
  short short2 = 2;
  short short3 = 3;
  short *b1 = &short1;
  short *b2 = &short2;
  short *b3 = &short3;
  printf("&b1 = %p, %u\n", b1);
  printf("&b2 = %p, %u\n", b2);
  printf("&b3 = %p, %u\n", b3);

  int int1 = 1;
  int int2 = 2;
  int int3 = 3;
  int *c1 = &int1;
  int *c2 = &int2;
  int *c3 = &int3;
  printf("&c1 = %p, %u\n", c1);
  printf("&c2 = %p, %u\n", c2);
  printf("&c3 = %p, %u\n", c3);

  double double1 = 1;
  double double2 = 2;
  double double3 = 3;
  double *d1 = &double1;
  double *d2 = &double2;
  double *d3 = &double3;
  printf("&d1 = %p, %u\n", d1);
  printf("&d2 = %p, %u\n", d2);
  printf("&d3 = %p, %u\n", d3);
}

int factorial1(int input) {
  //Using for loop
  int factorial1 = 1;
  for(int i = 1; i <= input; i++){
    factorial1 *= i;
  }
  printf("factorial1(%d) = %d\n", input, factorial1);
}

int factorial2(int input) {
  //Using while loop
  int i = 1;
  int factorial2 = 1;
  while(i <= input) {
    factorial2 *= i;
    i++;
  }
  printf("factorial2(%d) = %d\n", input, factorial2);

}

int factorial3(int input) {
  //Using do-while loop
  int i = 1;
  int factorial3 = 1;
  do {
    factorial3 *= i;
    i++;
      } while (i <= input);
  printf("factorial3(%d) = %d\n", input, factorial3);

}

int factorial4(int input) {
  //Using recursion
  if(input >=1 ) {
    return input * factorial4(input - 1);
  }
  else {
    return 1;
  }
}
