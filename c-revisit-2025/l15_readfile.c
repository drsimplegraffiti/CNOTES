#include <stdio.h>

int main() {
    FILE *fptr = fopen("file.txt", "r");

    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char c = fgetc(fptr);
    while (c != EOF) {
        printf("%c", c);
        c = fgetc(fptr);
    }

    fclose(fptr);

    return 0;
}

