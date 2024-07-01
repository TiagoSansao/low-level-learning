#include <stdio.h>
#include <string.h>

int main()
{
  char answer[3];

  printf("Are you beautiful? \"YES\" or \"NO\"\n");
  scanf("%s", answer);

  if (strcmp(answer, "YES") == 0)
  {
    printf("You're beautiful");
  }
  else
  {
    printf("You're not beautiful ;-;, go to the gym bro! Then, you'll be a greek god (small penis)");
  }

  return 0;
}