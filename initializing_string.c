#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char str1[] = "nice string bro";

  char str2[16];
  strcpy(str2, "nice string bro");

  char *str3 = (char *)malloc(strlen("nice string bro") + 1);
  strcpy(str3, "nice string bro");

  printf("1: %s | Address: %p\n", str1, &str1);
  printf("2: %s | Address: %p\n", str2, &str2);
  printf("3: %s | Address: %p\n", str3, &str3);

  return 0;
}