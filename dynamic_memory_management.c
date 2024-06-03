#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *pi = (int *)malloc(sizeof(int));

  *pi = 123;

  printf("Number stored in the heap: %d", *pi);

  free(pi);

  return 0;
}