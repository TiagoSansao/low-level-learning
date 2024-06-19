#include <stdio.h>

float multiply(float a, float b)
{
  return a * b;
}

float divide(float a, float b)
{
  return a / b;
}

typedef float (*fptrOperation)(float, float);

float compute(fptrOperation operation, float a, float b)
{
  return operation(a, b);
}

int main()
{
  printf("%f\n", compute(&multiply, 4.0, 6.0));
  printf("%f\n", compute(&divide, 80, 5));

  return 0;
}
