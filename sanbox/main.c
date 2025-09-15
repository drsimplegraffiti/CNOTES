
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int size;
  printf("Enter size of array: ");
  scanf("%d", &size);

  int *nums = malloc(size * sizeof(int)); // allocate memory for the array

  for (int i = 0; i < size; i++) {
    nums[i] = i + 1;
  }

  for (int i = 0; i < size; i++) {
    printf("%d\n", nums[i]);
  }

  free(nums); // free up memory

  return 0;
}
