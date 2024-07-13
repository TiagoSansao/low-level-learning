// a union store different data types, but they all share the same memory address
// the union size will be defined by the member's largest size

#include <stdio.h>
#include <string.h>

typedef union _someRandomData
{
  int x;
  float y;
  char z[30];
} SomeRandomData;

int main()
{
  SomeRandomData data;

  data.x = 4;
  data.y = 5.32f;
  strcpy(data.z, "josé");

  printf("%d - %f - %s\n", data.x, data.y, data.z);

  data.y = 7.77f;

  printf("%f\n", data.y);

  return 0;
}