#include <stdio.h>

int main()
{
  int x,y;
  char a;
  float	f,e;
  double d;

  x=4;
  y=7;
  a='H';
  f=-3.4;
  d=54.123456789;
  e=54.123456789;

  printf("%d %c\n",x,a);
  printf("%3d %5c\n",x,a);
  printf("%f %e\n",e,d);
  printf("%.9f %.9e\n",e,d);
  printf("%20.9f %20.9e\n",e,d);

  printf("\n\n");
  printf("%x\n", x);
  printf("%#x\n", x);
  printf("%p\n", x);

}

