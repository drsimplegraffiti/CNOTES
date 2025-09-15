#include <stdio.h>
#include <string.h>

int main() {
    char name[20];
    char copy[20];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Hello, %s!\n", name);

    // String length
    int len = strlen(name);
    printf("Length: %d\n", len);

    // String copy
    strcpy(copy, name);
    printf("Copied Name: %s\n", copy);

    // String compare
    if (strcmp(name, copy) == 0) {
        printf("Strings are equal\n");
    } else {
        printf("Strings are not equal\n");
    }

    // String concatenation
    strcat(name, "123");
    printf("After concatenation: %s\n", name);

    return 0;
}

