#include <stdio.h>
#include <errno.h>

int main() {
    FILE *fptr = fopen("nonexistent.txt", "r");

    if (fptr == NULL) {
        perror("Error opening file"); // perror prints a message to stderr
        return errno; // errno contains the error code
    }

    fclose(fptr);

    return 0;
}

