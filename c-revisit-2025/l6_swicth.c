#include <stdio.h>

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    switch(num) {
        case 1: 
            printf("One\n"); 
            break;
        case 2: 
            printf("Two\n"); 
            break;
        default: 
            printf("Other\n");
    }

    return 0;
}

