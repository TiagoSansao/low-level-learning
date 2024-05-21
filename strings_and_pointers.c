#include <stdio.h>

int main()
{
  char str[] = "Eae rapaziadaaa";
  char *ps = &str[0];

  while (*ps != '\0') // \0 is the null character, the compiler adds it to the end of every occurrence between double quotes ("")
  {
    printf("%c", *ps);
    ps += 1;
  }

  return 0;
}