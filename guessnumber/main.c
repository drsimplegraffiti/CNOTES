#include <stdio.h>

struct Student {
  char name[10];
  int age;
};

struct Address {
  char street[255];
  struct Student student;
};

int main(void) {
  struct Student student1 = {"james", 9};
  printf("%s\n", student1.name);

  struct Address address = {"lekki", {"lee", 89}};
  printf("%s\n", address.street);
  printf("%d\n", address.student.age);
}
