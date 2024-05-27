#include <stdio.h>

int beenCalled()
{
  static int n = 0;
  return ++n;
}

int main()
{
  static int n = 4;
  printf("%d\n", n);

  for (int i = 0; i < 3; ++i)
    printf("%d\n", beenCalled());

  return 0;
}