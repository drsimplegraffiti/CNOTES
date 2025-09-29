#include <stdio.h>

int main(void) {
  // Declare and initialize array
  int arr[5] = {1, 2, 3, 4, 5};

  // Print the first element
  printf("%d\n", arr[0]);

  // Calculate the length of the array
  int length = sizeof(arr) / sizeof(arr[0]);

  // Loop through the array and print each element
  for (int i = 0; i < length; i++) {
    printf("Number %d\n", arr[i]); // Print current array element
  }
  printf("%d\n", length);

  return 0;
}

// note
// sizeof(arr) = total size of array in bytes
// sizeof(arr[0]) = size of one element
