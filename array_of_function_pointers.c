#include <stdio.h>

int sum(int x, int y)
{
  return x + y;
}

int subtraction(int x, int y)
{
  return x - y;
}

int multiplication(int x, int y)
{
  return x * y;
}

int calculate(char operation, int x, int y)
{
  typedef int (*fptrOperation)(int, int);
  fptrOperation operations[128] = {NULL};

  operations['*'] = multiplication;
  operations['+'] = sum;
  operations['-'] = subtraction;

  return operations[operation](x, y);
}

int main()
{
  int x = 5, y = 4;

  printf("%d %c %d = %d\n", x, '+', y, calculate('+', x, y));
  printf("%d %c %d = %d\n", x, '*', y, calculate('*', x, y));
  printf("%d %c %d = %d\n", x, '-', y, calculate('-', x, y));

  return 0;
}