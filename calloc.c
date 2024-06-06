#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *pi = calloc(2, sizeof(int));
  *pi = 72;
  *(pi + 2) = 777;

  printf("%d %d %d %d", *pi, *(pi + 1), *(pi + 2), *(pi + 1233));

  free(pi);

  return 0;
}