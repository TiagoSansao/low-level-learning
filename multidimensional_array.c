#include <stdio.h>

// void display2DArray(int arr[][4], int rows)
void display2DArray(int (*arr)[4], int rows)
{
  for (int i = 0; i < rows; i += 1)
  {
    for (int j = 0; j < (sizeof(arr)[0] / sizeof(int)); j += 1)
    {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int matrix[3][4] = {
      {1, 2, 3, 4},
      {2, 4, 8, 16},
      {1, 2, 3, 5}};

  display2DArray(matrix, 3);

  return 0;
}