#include <stdio.h>

int main()
{
  int nums[5] = {2, 3, 5, 7, 11};

  int *ptr = nums;
  int *ptr2 = &nums;
  int *ptr3 = &nums[0];

  printf("%d\n", ptr == ptr2 && ptr2 == ptr3);

  printf("%p\n", &nums);
  printf("%p\n", nums);

  for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i += 1)
  {
    printf("%d\n", *(ptr + i));
    printf("%d\n", nums[i]);
  }

  return 0;
}