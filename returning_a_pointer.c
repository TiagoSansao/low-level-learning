#include <stdio.h>
#include <stdlib.h>

int *allocateArrayWithDefaultValue(int value, int size)
{
  int *pi = (int *)malloc(value * sizeof(int));
  for (int i = 0; i < size; i += 1)
  {
    //*(pi + i) = value;
    pi[i] = value;
  }
  return pi;
}

int main()
{

  int size = 42;
  int *arr = allocateArrayWithDefaultValue(777, size);

  for (int i = 0; i < size; i += 1)
  {
    printf("Index: %d | value: %d\n", i, arr[i]);
  }

  free(arr);

  return 0;
}