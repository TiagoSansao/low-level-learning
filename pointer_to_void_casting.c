#include <stdio.h>

int main()
{
  int num = 4;
  void *pv;
  pv = (double *)&num;
  float sum = 5 + *((int *)pv);

  printf("%f", sum);

  return 0;
}