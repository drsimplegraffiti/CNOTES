#include <stdio.h>

int main() {
  int x = 5;
  int y = 0;
  int z = x / y; // divide by zero
  printf("%d\n", z);
  return 0;
}
