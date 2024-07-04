#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _person
{
  char *name;
  char *city;
  int age;
} Person;

int main()
{
  Person p1;
  p1.age = 32;
  p1.name = (char *)malloc(strlen("Welington") + 1);
  p1.city = (char *)malloc(strlen("Joinville") + 1);
  strcpy(p1.city, "Joinville");
  strcpy(p1.name, "Welington");

  printf("%s | %s | %d years old\n", p1.name, p1.city, p1.age);

  Person p2 = {"Marlon",
               "Toronto",
               35};

  printf("%s | %s | %d years old\n", p2.name, p2.city, p2.age);

  // -> "points to" operator
  Person *p3 = (Person *)malloc(sizeof(Person));
  p3->age = 19;
  p3->name = malloc(strlen("Tiago") + 1);
  p3->city = malloc(strlen("Joinville") + 1);
  strcpy(p3->name, "Tiago");
  strcpy(p3->city, "Joinville");

  printf("%s | %s | %d years old\n", p3->name, p3->city, p3->age);

  Person *p4 = (Person *)malloc(sizeof(Person));
  (*p4).age = 22;
  (*p4).name = (char *)malloc(strlen("Bruno" + 1));
  (*p4).city = (char *)malloc(strlen("Araquari" + 1));
  strcpy((*p4).city, "Araquari");
  strcpy((*p4).name, "Bruno");

  printf("%s | %s | %d years old\n", p4->name, p4->city, p4->age);

  return 0;
}