#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _animal
{
  char *nickname;
  char *specie;
  unsigned int age;
};

typedef struct _animal Animal;

Animal *instanceAnimal(Animal *ptrAnimal, const char *nickname, const char *specie, unsigned int age)
{
  ptrAnimal->age = age;
  ptrAnimal->nickname = malloc(strlen(nickname) + 1);
  ptrAnimal->specie = malloc(strlen(specie) + 1);
  strcpy(ptrAnimal->specie, specie);
  strcpy(ptrAnimal->nickname, nickname);

  return ptrAnimal;
}

void deallocateAnimal(Animal *animal)
{
  free(animal->specie);
  free(animal->nickname);
}

int main()
{
  Animal animal;

  instanceAnimal(&animal, "Joao", "rat", 7);

  printf("Animal %s is a %s and is %d years old.", animal.nickname, animal.specie, animal.age);

  deallocateAnimal(&animal);

  return 0;
}