#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>

#define MAX_THREADS 5

int globalCounter = 0;

void *worker_function(void *arg)
{
  pthread_t thread = pthread_self();
  printf("Nova thread criada. TID = %lu\n", (unsigned long)thread);
  printf("Global counter: %i\n", globalCounter);
  globalCounter++;
}

int main()
{
  pthread_t pthread_list[MAX_THREADS];

  for (unsigned int i = 0; i < MAX_THREADS; i += 1)
  {
    pthread_t thread;
    pthread_create(&thread, NULL, worker_function, NULL);
    pthread_list[globalCounter] = thread;
  }

  for (unsigned int i = 0; i < MAX_THREADS; i += 1)
  {
    pthread_join(pthread_list[i], NULL);
    printf("pthread join %i\n", i);
  }

  return 0;
}
