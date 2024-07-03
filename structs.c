#include <stdio.h>

struct _person
{
  unsigned int age;
  char letter;
};

int main()
{
  struct _person p1;
  p1.age = 42;
  p1.letter = 'X';

  struct _person p2;
  p2.age = 77;
  p2.letter = 'Y';

  struct _person p3;
  p3.age = 23;
  p3.letter = 'H';

  struct _person people[3] = {p1, p2, p3};

  for (int i = 0; i < 3; i += 1)
  {
    printf("Person | Letter: %c | Age: %d \n", people[i].letter, people[i].age);
  }

  return 0;
}