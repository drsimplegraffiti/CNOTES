#include <stdio.h>

int main(){

    int a = 10;
    int *p = &a; // dereference

    printf("Value of a using pointer: %d\n", *p);
    return 0;
}

