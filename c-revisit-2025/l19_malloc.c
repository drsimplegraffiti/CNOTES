#include <stdio.h>
#include <stdlib.h> // the malloc header


// malloc() is used to allocate memory dynamically.
// we need memory allocation when we don't know the size of the data at compile time.

int main() {
    int *ptr;
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // here we are allocating memory for n integers
    ptr = (int*) malloc(n * sizeof(int));

    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        return 1;
    }

    // Memory has been successfully allocated
    for (int i = 0; i < n; i++) {
        ptr[i] = i + 1;
    }

    // Printing the elements of the array
    for (int i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Freeing the allocated memory. Important to avoid memory leaks.
    free(ptr);

    return 0;
}

