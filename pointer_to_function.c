#include <stdio.h>

int sum(int a, int b)
{
  return a + b;
}

int main()
{
  int a = 5;
  int b = 7;

  int (*ptrToSum)(int, int) = sum;

  printf("Sum is %d\n", ptrToSum(a, b));

  return 0;
}