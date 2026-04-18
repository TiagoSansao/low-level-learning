#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>

#define MAX_THREADS 900

int i = 0;
pthread_mutex_t lock;

void *worker_function(void *arg)
{
  pthread_mutex_lock(&lock);
  printf("New thread spawned. TID: %lu\n", (unsigned long)pthread_self());
  int x = i;
  usleep(100);
  x += 1;
  i = x;
  pthread_mutex_unlock(&lock);
}

int main()
{
  pthread_mutex_init(&lock, NULL);
  pthread_t pthreadList[MAX_THREADS];

  for (unsigned int j = 0; j < MAX_THREADS; j += 1)
  {
    pthread_create(&pthreadList[j], NULL, worker_function, NULL);
  }

  for (unsigned int j = 0; j < MAX_THREADS; j += 1)
  {
    pthread_join(pthreadList[j], NULL);
  }

  printf("Global counter end state: %d", i);

  return 0;
}
