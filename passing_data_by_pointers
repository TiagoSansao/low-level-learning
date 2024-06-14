#include <stdio.h>

void swapValuesInMemory(int *ptr1, int *ptr2)
{
  int tmp = *ptr2;
  *ptr2 = *ptr1;
  *ptr1 = tmp;
}

int main()
{
  int n1 = 42;
  int n2 = 69;

  printf("Before swap | n1 == %d | n2 == %d\n", n1, n2);

  swapValuesInMemory(&n1, &n2);

  printf("After swap | n1 == %d | n2 == %d\n", n1, n2);

  return 0;
}