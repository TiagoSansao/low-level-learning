#include <stdio.h>
#include <stdlib.h>

char *readLineAndStoreDynamically()
{
  int incrementValue = 10;
  char *buffer = malloc(sizeof(char) * incrementValue);
  char *currentPosition = buffer;
  char character;
  size_t length = 0;
  size_t maxLength = incrementValue;

  while (1)
  {
    character = fgetc(stdin);
    if (character == '\n')
      break;

    if (++length >= maxLength)
    {
      maxLength += incrementValue;
      char *newBuffer = realloc(buffer, maxLength);
      printf("Reallocated buffer, new position: %p\n", newBuffer);

      if (newBuffer == NULL)
      {
        free(buffer);
        return NULL;
      }

      currentPosition = newBuffer + (currentPosition - buffer);
      buffer = newBuffer;
    }

    *currentPosition++ = character;
  }

  *currentPosition = '\0';
  return buffer;
}

int main()
{
  char *pc = readLineAndStoreDynamically();

  printf("\n Result: ");

  while (*pc != '\0')
  {
    printf("%c", *pc);
    pc += 1;
  }

  printf("\n");

  return 0;
}