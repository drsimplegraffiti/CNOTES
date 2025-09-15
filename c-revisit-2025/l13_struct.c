#include <stdio.h>


struct Person {
    char name[50];
    int age;
};


int main(){

    struct Person p1 = {"james", 1};
    printf("Person %s\n", p1.name);
    printf("Age %d\n", p1.age);

    return 0;
}
