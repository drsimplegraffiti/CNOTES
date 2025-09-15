#### C Programming

Setup:

You need:

- a C compiler. I use gcc. (https://gcc.gnu.org/), If you are on mac, probably you have it already. check with `gcc --version`. GCC: GNU Compiler Collection.
- for windows, you can use https://www.codeblocks.org/
- an editor. I use vscode. (https://code.visualstudio.com/), you can use any editor you like.
- Download the c/c++ extension for vscode.

### Hello World

create a file called main.c and write the following code in it.

```c
#include <stdio.h> // this is a header file. It contains the declaration of printf function.


int main(void)
{
    int age = 90;
    printf("%d\n", age);

    char initial = 'D';
    printf("%c\n", initial);

    float fp = 45.90;
    printf("%f\n", fp); // the "%f" is a format specifier. It tells the printf function to print a float.

    double d = 45.90;
    printf("%f\n", d);


    printf("hello world\n");

     const int NUM = 5;
    printf("%i\n", NUM);

    return 0;
}
```

To compile the code, run the following command in the terminal.

```bash
gcc main.c
```

this will create a file called a.out. To run the program, run the following command in the terminal.

```bash
./a.out
```

or
Rename the output file to main and run the following command in the terminal.

```bash
gcc main.c -o main
```

#### Format Specifiers

The format specifiers are used to tell the printf function what type of data to print.

```c
#include <stdio.h> //header file: contains the declaration of printf function.

int main(void)
{
    int age = 90;
    printf("%d\n", age);

    char initial = 'D';
    printf("%c\n", initial);

    float fp = 45.90;
    printf("%f\n", fp); // the "%f" is a format specifier. It tells the printf function to print a float.

    double d = 45.90;
    printf("%f\n", d);

    return 0;
}
```

#### Pointers

Pointers are variables that store the address of other variables.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int myAge = 43;
    printf("%d", myAge); // Outputs 43
    printf("%p\n", &myAge); // Outputs 0x16fa12e08. &myAge is the address of myAge in memory. they are called pointers.


    //pointer variable
    int *agePtr; // * is used to declare a pointer variable. int *agePtr means agePtr is a pointer variable that points to an integer.
    agePtr = &myAge; // & is used to get the address of a variable. &myAge is the address of myAge in memory. agePtr = &myAge means agePtr is assigned the address of myAge.
    printf("%p\n", agePtr); // Outputs 0x16fa12e08. agePtr is the address of myAge in memory.

    return 0;
}

//2 ways to declare a pointer variable
int *agePtr; // * is used to declare a pointer variable. int *agePtr means agePtr is a pointer variable that points to an integer.
int* agePtr; // * is used to declare a pointer variable. int* agePtr means agePtr is a pointer variable that points to an integer.
```

#### Reading Input

```c
#include <stdio.h>

int main(void)
{
    // reading user input
    int num;

    printf("what is your age? ");

    scanf("%i", &num); //&num is the address of num variable in memory
    printf("You are %i years old\n", num);
    printf("%i\n", num);

    const int NUM = 5;
    printf("%i\n", NUM);

    return 0;
}
```

Example 2

```c
#include <stdio.h>

int main(void)
{
    // reading user input
    int num;

    printf("what is your age? \n");

    scanf("%i", &num);

    if (num < 18)
    {
        printf("you are underaged\n");
    }
    else
    {
        printf("you are good to go\n");
    }

    return 0;
}
```

#### If Else

```c
#include <stdio.h>

int main(void)
{
    // reading user input
    int num;

    printf("what is your age? \n");

    scanf("%i", &num);

    if (num < 18)
    {
        printf("you are underaged\n");
    }
    else if (num == 18)
    {
        printf("you are 18\n");
    }
    else
    {
        printf("you are good to go\n");
    }

    return 0;
}
```

#### Switch

```c
#include <stdio.h>

int main(void)
{
    // reading user input
    int num;

    printf("what is your age? \n");

    scanf("%i", &num);

    switch (num)
    {
    case 18:
        printf("you are 18\n");
        break;
    case 19:
        printf("you are 19\n");
        break;
    case 20:
        printf("you are 20\n");
        break;
    default:
        printf("you are not 18, 19 or 20\n");
        break;
    }

    return 0;
}
```

#### Ternary Operator

```c
#include <stdio.h>

int main(void)
{
    // reading user input
    int num;

    printf("what is your age? \n");

    scanf("%i", &num);

    num < 18 ? printf("you are underaged\n") : printf("you are good to go\n");

    return 0;
}
```

#### While Loop

```c
#include <stdio.h>

int main(void)
{
    // reading user input
    int num = 0;

    while (num < 10)
    {
        printf("%i\n", num);
        num++;
    }

    return 0;
}
```

#### Do While Loop

```c
#include <stdio.h>

int main(void)
{
    // reading user input
    int num = 0;

    do
    {
        printf("%i\n", num);
        num++;
    } while (num < 10);

    return 0;
}
```

#### For Loop

```c
#include <stdio.h>

int main(void)
{
    // reading user input
    int num = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("%i\n", i);
    }

    return 0;
}
```

#### Strings

strings are arrays of characters. i.e char[]

old way of declaring strings with null terminator

```c
#include <stdio.h>

int main(void)
{
    // reading user input
    int num = 0;

    char name[20] = {'d', 'a', 'v', 'e', '\0'}; // \0 is the null terminator, 20 elements in array
    printf("%lu\n", sizeof(name)); // 20 bytes i.e d is 1 byte, a is 1 byte, v is 1 byte, e is 1 byte, \0 is 1 byte, 15 bytes of garbage
    int length = sizeof(name) / sizeof(name[0]);
    printf("%s\n", name);


     char names[] = "james";

    printf("%s\n", names);
    printf("sizeof: %zu\n", sizeof(names));   // 6
    printf("strlen: %zu\n", strlen(names));   // 5

    return 0;
}
```

Using string literal

```c
#include <stdio.h>

int main(void)
{
    // reading user input
    int num = 0;

    char name[20] = "dave"; // or use char name[] = "dave"; // 20 elements in array
    printf("%s\n", name);

    return 0;
}
```

#### String Functions

```c
#include <string.h>
```

#### Arrays

```c
#include <stdio.h>

int main(void)
{
    // reading user input
    int nums[3] = {1, 2, 3};

    // array of strings
    char *names[3] = {"dave", "john", "doe"};

    printf("%i\n", nums[0]); // %i specifier for integer
    printf("%i\n", nums[1]);
    printf("%i\n", nums[2]);

    printf("%s\n", names[0]);
    printf("%s\n", names[1]);

    return 0;
}
```

#### Ommiting Array Size

```c
#include <stdio.h>

int main(void)
{
    // reading user input
    int nums[] = {1, 2, 3}; // size is 3 because we have 3 elements, the compiler will figure it out.

    // array of strings
    char *names[] = {"dave", "john", "doe"};

    printf("%i\n", nums[0]);
    printf("%i\n", nums[1]);
    printf("%i\n", nums[2]);

    printf("%s\n", names[0]);
    printf("%s\n", names[1]);

    return 0;
}
```

#### Size of Array

```c
#include <stdio.h>

int main(void)
{
    int grades[] = {50, 75, 100, 67, 90}; // each int is 4 bytes, i.e 4 x 5 elements in the array

    // calculate the size of the array
    int array_size = sizeof(grades);

    printf("Size of array: %i bytes\n", array_size);
    printf("size of bytes in each element: %lu bytes\n", sizeof(grades[0]));

    // calculate the number of elements in the array
    int element_size = sizeof(grades[0]);

    int length = array_size / element_size;
    printf("Number of elements in array: %i\n", length);

    // reassigning values in the array
    grades[1] = 52;
    grades[2] = 78;
    printf("Grades[1]: %i\n", grades[1]);

}
```

#### Loops and Arrays

```c
#include <stdio.h>

int main(void)
{
    int grades[] = {50, 75, 100, 67, 90}; // each int is 4 bytes, i.e 4 x 5 elements in the array


    for (int i = 0; i < 5; i++)
    {
        printf("Grade %i: %i\n", i + 1, grades[i]);
    }

    printf("\n");

    //array of strings
    char *names[] = {"David", "Michael", "Sarah", "John"};
    int length = sizeof(names) / sizeof(names[0]); // 4 x 8 bytes = 32 bytes / 8 bytes = 4 elements in the array
    printf("size of names: %lu\n", sizeof(names));
    printf("size of names[0]: %lu\n", sizeof(names[0])); // lu is unsigned long

    for (int i = 0; i < length; i++)
    {
        printf("Name %i: %s\n", i + 1, names[i]);
    }



}
```

#### Functions

```c
#include <stdio.h>

// function prototype
void sayHi(void);

int main(void)
{
    sayHi();
    return 0;
}

// function definition
void sayHi(void)
{
    printf("Hi\n");
}
```

#### Function Parameters

```c
#include <stdio.h>

// function prototype
void sayHi(char name[]);

int main(void)
{
    sayHi("dave");
    return 0;
}

// function definition
void sayHi(char name[])
{
    printf("Hi %s\n", name);
}
```

#### Function Return Values

```c
#include <stdio.h>

// function prototype
int add(int num1, int num2);

int main(void)
{
    int sum = add(5, 10);
    printf("%i\n", sum);
    return 0;
}

// function definition
int add(int num1, int num2)
{
    return num1 + num2;
}
```

#### Example 2

```c

// For numbers (int, float, etc.) → no need for const when returning from a function.
//
// For string literals ("text") → it’s best practice to return const char* so the compiler prevents accidental modification of read-only memory.
// So, const isn’t always required, but it’s a safety net when dealing with string literals.

#include <stdio.h>

// contract
const char *printNumber(void);

int main(void) {
  const char *response = printNumber();
  printf("%s\n", response);
}

// impl
const char *printNumber(void) {
  return "hello world"; // string literal
}
```

#### Pointers

Pointers are variables that store the address of other variables.

```c
#include <stdio.h>

int main(void)
{
    int age = 30;
    int *pAge = &age; // &age is the address of age variable in memory

    double gpa = 3.4;
    double *pGpa = &gpa;

    char grade = 'A';
    char *pGrade = &grade;

    printf("age: %p\n", pAge);
    printf("gpa: %p\n", pGpa);
    printf("grade: %p\n", pGrade);

    return 0;
}
```

#### Dereferencing Pointers

```c
#include <stdio.h>

int main(void)
{
    int age = 30;
    int *pAge = &age; // &age is the address of age variable in memory

    double gpa = 3.4;
    double *pGpa = &gpa;

    char grade = 'A';
    char *pGrade = &grade;

    printf("age: %p\n", pAge);
    printf("gpa: %p\n", pGpa);
    printf("grade: %p\n", pGrade);

    printf("age: %d\n", *pAge);
    printf("gpa: %f\n", *pGpa);
    printf("grade: %c\n", *pGrade);

    return 0;
}
```

#### Null Pointers

```c
#include <stdio.h>

int main(void)
{
    int *pAge = NULL; // NULL is a macro that sets the pointer to point to nothing

    printf("%p\n", pAge);

    return 0;
}
```

#### Pointers and Arrays

```c
#include <stdio.h>

int main(void)
{
    int nums[] = {1, 2, 3, 4, 5};
    printf("%p\n", nums); // nums is a pointer to the first element in the array
    printf("%d\n", *nums); // dereference the pointer to get the value of the first element in the array

    int *pNums = nums; // pNums is a pointer to the first element in the array
    printf("%p\n", pNums);
    printf("%d\n", *pNums);

    printf("%d\n", *(pNums + 1)); // get the value of the second element in the array

    return 0;
}
```

#### Incrementing Pointers

```c
#include <stdio.h>

int main(void)
{
    int nums[] = {1, 2, 3, 4, 5};
    printf("%p\n", nums); // nums is a pointer to the first element in the array
    printf("%d\n", *nums); // dereference the pointer to get the value of the first element in the array

    int *pNums = nums; // pNums is a pointer to the first element in the array
    printf("%p\n", pNums);
    printf("%d\n", *pNums);

    printf("%d\n", *(pNums + 1)); // get the value of the second element in the array

    pNums++; // increment the pointer to point to the next element in the array
    printf("%d\n", *pNums);

    return 0;
}
```

#### Decrementing Pointers

```c
#include <stdio.h>

int main(void)
{
    int nums[] = {1, 2, 3, 4, 5};
    printf("%p\n", nums); // nums is a pointer to the first element in the array
    printf("%d\n", *nums); // dereference the pointer to get the value of the first element in the array

    int *pNums = nums; // pNums is a pointer to the first element in the array
    printf("%p\n", pNums);
    printf("%d\n", *pNums);

    printf("%d\n", *(pNums + 1)); // get the value of the second element in the array

    pNums++; // increment the pointer to point to the next element in the array
    printf("%d\n", *pNums);

    pNums--; // decrement the pointer to point to the previous element in the array
    printf("%d\n", *pNums);

    return 0;
}
```

#### Pointer Arithmetic

```c
#include <stdio.h>

int main(void)
{
    int nums[] = {1, 2, 3, 4, 5};
    printf("%p\n", nums); // nums is a pointer to the first element in the array
    printf("%d\n", *nums); // dereference the pointer to get the value of the first element in the array

    int *pNums = nums; // pNums is a pointer to the first element in the array
    printf("%p\n", pNums);
    printf("%d\n", *pNums);

    printf("%d\n", *(pNums + 1)); // get the value of the second element in the array

    pNums++; // increment the pointer to point to the next element in the array
    printf("%d\n", *pNums);

    pNums--; // decrement the pointer to point to the previous element in the array
    printf("%d\n", *pNums);

    pNums += 2; // increment the pointer to point to the next element in the array
    printf("%d\n", *pNums);

    pNums -= 2; // decrement the pointer to point to the previous element in the array
    printf("%d\n", *pNums);

    return 0;
}
```

#### structs

structs are used to group related data together.

```c

#include <stdio.h>

struct Student
{
    char name[50]; // each element is called a member
    char major[50]; // member
    int age;
    double gpa;
};

int main(void)
{
    struct Student student1;
    student1.age = 22;
    student1.gpa = 3.2;
    strcpy(student1.name, "dave"); // assigning value to a struct member
    strcpy(student1.major, "computer science");

    printf("%s\n", student1.name);
    printf("%s\n", student1.major);
    printf("%d\n", student1.age);
    printf("%f\n", student1.gpa);

    return 0;
}
```

#### Initializing structs at time of declaration

```c

#include <stdio.h>

struct Student {
  char name[10];
  int age;
};

int main(void) {
  struct Student student1 = {"james", 9};
  printf("%s\n", student1.name);
}

```

#### Nested Struct

```c

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
```

#### Union

🔹 What is a union?
A union is similar to a struct, but the members share the same memory location.
This means only one member can hold a valid value at a time.
The size of a union is the size of its largest member.

```c
#include <stdio.h>
#include <string.h>

// Define a union
union Data {
    int i;
    float f;
    char str[20];
};

int main() {
    union Data data;

    // Assign an integer
    data.i = 10;
    printf("data.i: %d\n", data.i);

    // Assign a float (overwrites the same memory)
    data.f = 220.5;
    printf("data.f: %.2f\n", data.f);

    // Assign a string (overwrites the same memory)
    strcpy(data.str, "Hello");
    printf("data.str: %s\n", data.str);

    // Notice that only the last assigned value is valid
    printf("\nAfter assigning string:\n");
    printf("data.i: %d\n", data.i);     // Garbage value
    printf("data.f: %.2f\n", data.f);   // Garbage value
    printf("data.str: %s\n", data.str); // Valid

    return 0;
}
```

#### Enum

enum is a custom data type that allows us to define a set of constants.

```c
#include <stdio.h>

int main(void) {
    enum Company {GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT};

    enum Company xerox = XEROX;
    enum Company google = GOOGLE;
    enum Company ebay = EBAY;

    printf("%d\n", xerox);
    printf("%d\n", google);
    printf("%d\n", ebay);

    return 0;
}
```

#### Boolean

```c
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool isMale = true;
    printf("%d\n", isMale);

    return 0;
}
```

#### File IO

```c
#include <stdio.h>

int main(void)
{
    FILE *fpointer = fopen("employees.txt", "w"); // w is for write mode

    fprintf(fpointer, "Jim, Salesman\nPam, Receptionist\nOscar, Accounting");

    fclose(fpointer);

    return 0;
}
```

#### Reading Files

```c
#include <stdio.h>

int main(void)
{
    char line[255];
    FILE *fpointer = fopen("employees.txt", "r"); // r is for read mode

    fgets(line, 255, fpointer); // read the first line
    printf("%s", line);

    fgets(line, 255, fpointer); // read the second line
    printf("%s", line);

    fgets(line, 255, fpointer); // read the third line
    printf("%s", line);

    fclose(fpointer);

    return 0;
}
```

#### Reading Files with a Loop

```c
#include <stdio.h>

int main(void)
{
    char line[255];
    FILE *fpointer = fopen("employees.txt", "r"); // r is for read mode

    while (fgets(line, 255, fpointer) != NULL)
    {
        printf("%s", line);
    }

    fclose(fpointer);

    return 0;
}
```

#### Preprocessor Directives

Preprocessor Directives and Macros

The C preprocessor is a tool that processes the source code before compilation. It allows for powerful features like conditional compilation, file inclusion, and macro definitions, which can make programs more flexible, readable, and easier to maintain.

9.1.1 Understanding Preprocessor Directives

Preprocessor directives are special instructions to the C preprocessor that are included in the source code but are not part of the actual code that gets compiled. These directives are preceded by a # symbol. Preprocessor directives are executed before the actual compilation begins. Common preprocessor directives include:

#define : Defines a macro or constant.

#include : Includes external files in the program.

#ifdef, #ifndef, #endif : Conditional compilation.

#if, #else, #elif : Conditional compilation with expressions.
· #undef : Undefines a previously defined macro.
. #pragma : Used for implementation-specific instructions.

9.1.2 Macros

A macro is a fragment of code that gets replaced by a preprocessor before compilation. Macros are defined
using the #define directive. There are two types of macros in C:

Object-like macros: These are simple replacements. For example:

#define PI 3.14159

. Whenever the program encounters the identifier PI , it is replaced with the value 3.14159.

Function-like macros: These are more complex and can accept parameters, similar to functions:

#define SQUARE(x) ((x)\* (x))

. In this example, SQUARE(x) will be replaced by the expression ((x) \* (x)).

Advantages of Macros:

. Macros allow for code reuse and prevent magic numbers or hardcoded values.
· Function-like macros improve code readability and avoid repeated code.

Disadvantages of Macros:
· Since macros are expanded directly in the code, they can lead to difficult-to-debug errors (like incor-
rect evaluation order in complex expressions).
. Macros do not have type safety, so they can be prone to errors if used improperly (e.g., passing a
complex expression like SQUARE(a + b) ).

9.1.3 Conditional Compilation

Conditional compilation is a mechanism by which the compiler includes or excludes certain portions of
code based on certain conditions. This is useful for compiling code for different platforms or debugging.
The most common preprocessor directives used for conditional compilation are:

. #ifdef : This checks if a macro is defined.
. #ifndef : This checks if a macro is not defined.
. #endif : Marks the end of a conditional block.
. #else : Specifies an alternative block to compile if the condition is false.
. #elif : Checks another condition if the previous ones failed.

For example:

```c

#define DEBUG

#ifdef DEBUG
printf("Debugging mode is enabled.\n");
#endif
```

```c
#include <stdio.h> // this is a header file. It contains the declaration of printf function.
#include <stdlib.h> // this is a header file. It contains the declaration of malloc function.

int main(void)
{
    printf("Hello World\n");

    return 0;
}
```

#### Macros

Macros are constants, they are defined using the #define directive. They are not variables, they are just a text replacement.

```c
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14 // macros are constants, they are defined using the #define directive

int main(void)
{
    printf("%f\n", PI);

    return 0;
}
```

#### Conditional Compilation

```c
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14 // macros are constants, they are defined using the #define directive

int main(void)
{
    #ifdef PI
        printf("%f\n", PI);
    #else
        printf("PI is not defined\n");
    #endif

    return 0;
}
```

#### import files from another directory

Create a folder called utils and create a file called utils.h and utils.c. Add the following code to the utils.h file.
.h are header files. They contain the declaration of functions.

```c
#ifndef UTILS_H_ // if UTILS_H_ is not defined
#define UTILS_H_ // define UTILS_H_

void sayHi(char name[]);

#endif // end of if statement
```

Add the following code to the utils.c file.
.c files contain the definition of functions.

```c
#include <stdio.h>
#include "utils.h"

void sayHi(char name[])
{
    printf("Hi %s\n", name);
}
```

Add the following code to the main.c file.

```c
#include <stdio.h>
#include "utils/utils.h"

int main(void)
{
    sayHi("dave");
    return 0;
}
```

Run:

```bash
cc main.c utils/utils.c -o main
./main
```

#### Makefile

Makefile is a file that contains instructions for compiling and running the program.

Create a file called Makefile and add the following code to it.

```makefile
main: main.c utils/utils.c
    gcc main.c utils/utils.c -o main
```

To compile the program, run the following command in the terminal.

```bash
make
```

To run the program, run the following command in the terminal.

```bash
./main
```

#### Error Handling

c does not have built in error handling. We have to write our own error handling.
We will use the errno.h header file to handle errors.

```c
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void)
{
    FILE *fpointer = fopen("employees.txt", "r"); // r is for read mode

    if (fpointer == NULL)
    {
        printf("Error: %d\n", errno);
        exit(1);
    }

    char line[255];

    while (fgets(line, 255, fpointer) != NULL)
    {
        printf("%s", line);
    }

    fclose(fpointer);

    return 0;
}
```

#### Example 2 of Error Handling using a simple calculator

```c
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void)
{
    double num1;
    double num2;

    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter second number: ");
    scanf("%lf", &num2);

    printf("Answer: %f\n", num1 + num2);

    return 0;
}
```

#### Memory Allocation

Memory allocation is the process of allocating memory during the program execution.
We use the malloc function to allocate memory.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int age = 30;
    double gpa = 3.4;
    char grade = 'A';

    printf("%p\n", &age);
    printf("%p\n", &gpa);
    printf("%p\n", &grade);

    int *pAge = malloc(4); // allocate 4 bytes of memory
    *pAge = 30;
    printf("%p\n", pAge);
    printf("%d\n", *pAge);

    double *pGpa = malloc(8); // allocate 8 bytes of memory
    *pGpa = 3.4;
    printf("%p\n", pGpa);
    printf("%f\n", *pGpa);

    char *pGrade = malloc(1); // allocate 1 byte of memory
    *pGrade = 'A';
    printf("%p\n", pGrade);
    printf("%c\n", *pGrade);

    return 0;
}
```

```c
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *pAge = malloc(sizeof(int));
    if (pAge == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    *pAge = 30;
    printf("Address: %p\n", (void *)pAge);
    printf("Value: %d\n", *pAge);

    free(pAge);
    return 0;
}
```

#### Freeing Memory

We use the free function to free up memory.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int age = 30;
    double gpa = 3.4;
    char grade = 'A';

    printf("%p\n", &age);
    printf("%p\n", &gpa);
    printf("%p\n", &grade);

    int *pAge = malloc(4); // allocate 4 bytes of memory
    *pAge = 30;
    printf("%p\n", pAge);
    printf("%d\n", *pAge);

    double *pGpa = malloc(8); // allocate 8 bytes of memory
    *pGpa = 3.4;
    printf("%p\n", pGpa);
    printf("%f\n", *pGpa);

    char *pGrade = malloc(1); // allocate 1 byte of memory
    *pGrade = 'A';
    printf("%p\n", pGrade);
    printf("%c\n", *pGrade);

    free(pAge);
    free(pGpa);
    free(pGrade);

    return 0;
}
```

#### dynamic arrays

We can use the malloc function to create dynamic arrays.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int *nums = malloc(size * sizeof(int)); // allocate memory for the array

    for (int i = 0; i < size; i++)
    {
        nums[i] = i + 1;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d\n", nums[i]);
    }

    free(nums); // free up memory

    return 0;
}
```

#### realloc

We can use the realloc function to resize an array.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int *nums = malloc(size * sizeof(int)); // allocate memory for the array

    for (int i = 0; i < size; i++)
    {
        nums[i] = i + 1;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d\n", nums[i]);
    }

    printf("Enter new size of array: ");
    scanf("%d", &size);

    nums = realloc(nums, size * sizeof(int)); // resize the array

    for (int i = 0; i < size; i++)
    {
        nums[i] = i + 1;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d\n", nums[i]);
    }

    free(nums); // free up memory

    return 0;
}
```

#### fgets

fgets is used to read a line of text from a file.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char line[255];
    FILE *fpointer = fopen("employees.txt", "r"); // r is for read mode

    while (fgets(line, 255, fpointer) != NULL)
    {
        printf("%s", line);
    }

    fclose(fpointer);

    return 0;
}
```

#### fscanf

fscanf is used to read a line of text from a file.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char line[255];
    FILE *fpointer = fopen("employees.txt", "r"); // r is for read mode

    while (fscanf(fpointer, "%s", line) != EOF)
    {
        printf("%s\n", line);
    }

    fclose(fpointer);

    return 0;
}
```

#### fgetc

fgetc is used to read a character from a file.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char line[255];
    FILE *fpointer = fopen("employees.txt", "r"); // r is for read mode

    char c = fgetc(fpointer);
    while (c != EOF)
    {
        printf("%c", c);
        c = fgetc(fpointer);
    }

    fclose(fpointer);

    return 0;
}
```

#### fputc

fputc is used to write a character to a file.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fpointer = fopen("employees.txt", "w"); // w is for write mode

    fputc('A', fpointer);
    fputc('B', fpointer);
    fputc('C', fpointer);

    fclose(fpointer);

    return 0;
}
```

#### fputs

fputs is used to write a string to a file.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fpointer = fopen("employees.txt", "w"); // w is for write mode

    fputs("Hello World", fpointer);

    fclose(fpointer);

    return 0;
}
```

#### Command Line Arguments

Command line arguments are arguments passed to the program when it is executed.
. arge (Argument Count): The number of arguments passed to the program, including the program's
name.
. argv (Argument Vector): An array of strings (character pointers) that holds each argument passed to
the program.

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("Number of arguments: %d\n", argc);

    for (int i = 0; i < argc; i++)
    {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    return 0;
}
```

Run with

```bash
➜  into-to-c-program git:(main) ✗ cc main.c  && ./a.out "hi"
Number of arguments: 2
Argument 0: ./a.out
Argument 1: h
```

#### Example 2 of Command Line Arguments

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    double num1 = atof(argv[1]);
    double num2 = atof(argv[2]);

    printf("Answer: %f\n", num1 + num2);

    return 0;
}
```

#### type cast

type cast is used to convert one data type to another.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num1 = 6;
    int num2 = 5;

    printf("%d\n", num1 / num2); // 6 / 5 = 1

    printf("%f\n", (double)num1 / num2); // 6.000000 / 5 = 1.200000

    return 0;
}
```

#### Pointer

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // allocate memory for 5 integers
  int *ptr = malloc(sizeof(int) * 5);
  if (ptr == NULL) { // always check malloc result
    perror("malloc failed"); // failure check, malloc() returns NULL. calloc() is similar to malloc but initializes the allocated memory to 0
    return 1;
  }

  // store a value into the allocated memory
  ptr[0] = 90;
  ptr[1] = 89;

  // print pointer address, (void *)ptr : this is a generic pointer that can point to any data
  printf("Pointer address: %p\n", (void *)ptr);

  // print the stored value
  printf("First value: %d\n", ptr[0]);
  printf("Second value: %d\n", ptr[1]);

  // free the allocated memory
  free(ptr);

  return 0;
}

```

#### GDB GNU Debugger

```bash
sudo apt update
sudo apt install gdb
```

### To use

```bash
# Compile with debugging info
gcc -g program.c -o program

# Start gdb
gdb ./program

# Inside gdb:
run                 # run the program
break main          # set breakpoint at main()
break 15            # set breakpoint at line 15
next                # go to next line (step over functions)
step                # step into a function
continue            # continue until next breakpoint
print var           # print variable value
backtrace           # show call stack (useful after crash)
list                # show source code around current line
quit                # exit gdb
```
