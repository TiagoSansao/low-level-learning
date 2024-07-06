#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "pool_of_instances.h"

#define POOL_SIZE 10

int idCounter = 0;
AdminUser *pool[POOL_SIZE];

void initializePool()
{
  for (int i = 0; i < POOL_SIZE; i++)
  {
    pool[i] = NULL;
  }
}

void displayPool()
{
  for (int i = 0; i < POOL_SIZE; i++)
  {
    char *slotState = pool[i] == NULL ? "Empty" : "Filled";
    printf("Pool[%d]: %s\n", i, slotState);
  }
}

void initializeAdminUser(AdminUser *ptrAdminUser)
{
  ptrAdminUser->id = idCounter++;
  ptrAdminUser->name = malloc(strlen("Default admin") + 1);
  ptrAdminUser->service = malloc(strlen("Default service") + 1);
  strcpy(ptrAdminUser->name, "Default admin");
  strcpy(ptrAdminUser->service, "Default service");
}

void inspectAdminUser(AdminUser *ptrAdminUser)
{
  printf("AdminUser - id: %d - Name: %s - Service: %s\n", ptrAdminUser->id, ptrAdminUser->name, (*ptrAdminUser).service);
};

AdminUser *getAnAdminUser()
{
  for (int i = 0; i < POOL_SIZE; i++)
  {
    if (pool[i] != NULL)
    {
      AdminUser *tmpAdminUserRef = pool[i];
      pool[i] = NULL;
      printf("Admin user id [%d] was retrieved from slot [%d] of the pool.\n", tmpAdminUserRef->id, i);
      return tmpAdminUserRef;
    }
  }

  AdminUser *ptrNewAdminUser = malloc(sizeof(AdminUser));
  initializeAdminUser(ptrNewAdminUser);

  printf("The pool was empty, adminUser id [%d] was created.\n", ptrNewAdminUser->id);

  return ptrNewAdminUser;
}

void returnAnAdminUser(AdminUser *ptrAdminUser)
{
  for (int i = 0; i < POOL_SIZE; i++)
  {
    if (pool[i] == NULL)
    {
      pool[i] = ptrAdminUser;
      printf("Admin user id [%d] was stored at slot [%d] of the pool.\n", ptrAdminUser->id, i);
      return NULL;
    }
  }

  printf("The pool is full and AdminUser id [%d] will be deallocated.\n", ptrAdminUser->id);

  free(ptrAdminUser->name);
  free(ptrAdminUser->service);
  free(ptrAdminUser);
}

int main()
{
  initializePool();

  AdminUser *adm0 = getAnAdminUser();
  AdminUser *adm1 = getAnAdminUser();
  AdminUser *adm2 = getAnAdminUser();

  inspectAdminUser(adm0);
  inspectAdminUser(adm1);
  inspectAdminUser(adm2);

  returnAnAdminUser(adm0);
  returnAnAdminUser(adm2);

  AdminUser *adm3 = getAnAdminUser();
  AdminUser *adm4 = getAnAdminUser();
  AdminUser *adm5 = getAnAdminUser();
  AdminUser *adm6 = getAnAdminUser();
  AdminUser *adm7 = getAnAdminUser();
  AdminUser *adm8 = getAnAdminUser();
  AdminUser *adm9 = getAnAdminUser();
  AdminUser *adm10 = getAnAdminUser();
  AdminUser *adm11 = getAnAdminUser();
  AdminUser *adm12 = getAnAdminUser();
  AdminUser *adm13 = getAnAdminUser();
  AdminUser *adm14 = getAnAdminUser();

  returnAnAdminUser(adm3);
  returnAnAdminUser(adm4);
  returnAnAdminUser(adm5);
  returnAnAdminUser(adm6);
  returnAnAdminUser(adm7);
  returnAnAdminUser(adm8);
  returnAnAdminUser(adm9);
  returnAnAdminUser(adm10);
  returnAnAdminUser(adm11);
  returnAnAdminUser(adm12);
  returnAnAdminUser(adm13);
  returnAnAdminUser(adm14);

  return 0;
}
