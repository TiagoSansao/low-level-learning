#include <stdio.h>
#include <stdlib.h>

void allocateArrayWithDefaultValue(int **vector, int value, int size)
{
  *vector = (int *)malloc(sizeof(int) * size);

  for (int i = 0; i < size; i += 1)
  {
    (*vector)[i] = value;
    // *((*vector) + i) = value;
  }
}

int main()
{
  int *pp = NULL;
  allocateArrayWithDefaultValue(&pp, 3, 21);

  for (int i = 0; i < 21; i += 1)
  {
    printf("%d %d\n", i, pp[i]);
  }

  return 0;
}