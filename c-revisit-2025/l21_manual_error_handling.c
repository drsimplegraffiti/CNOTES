#include <stdio.h>

int main() {
    FILE *fptr = fopen("nonexistent.txt", "r");

    if (fptr == NULL) {
        printf("Error: File could not be opened.\n");
        return 1; // exit program with error
    }

    fclose(fptr);

    return 0;
}

