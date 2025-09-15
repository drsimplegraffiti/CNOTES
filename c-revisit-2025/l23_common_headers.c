
#include <stdio.h>      // For printf, scanf
#include <stdlib.h>     // For malloc, free
#include <string.h>     // For strlen, strcpy
#include <math.h>       // For sqrt, pow
#include <ctype.h>      // For isdigit, toupper
#include <stdbool.h>    // For bool, true, false
#include <time.h>       // For time, struct tm
#include <limits.h>     // For INT_MAX
#include <float.h>      // For FLT_MAX

int main() {
    // 1. stdio.h - printf
    printf("Hello, World!\n");

    // 2. stdlib.h - malloc
    int *arr = (int*) malloc(3 * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    arr[0] = 1; arr[1] = 2; arr[2] = 3;
    printf("Array: %d %d %d\n", arr[0], arr[1], arr[2]);
    free(arr);

    // 3. string.h - strlen, strcpy
    char src[] = "C Programming";
    char dest[50];
    strcpy(dest, src);
    printf("Copied string: %s (Length: %lu)\n", dest, strlen(dest));

    // 4. math.h - sqrt, pow
    double num = 16.0;
    printf("Square root of %.2f is %.2f\n", num, sqrt(num));
    printf("2 raised to power 3 is %.2f\n", pow(2, 3));

    // 5. ctype.h - isdigit, toupper
    char ch = 'a';
    if (isdigit(ch)) {
        printf("%c is a digit.\n", ch);
    } else {
        printf("%c is not a digit.\n", ch);
    }
    printf("Uppercase of %c is %c\n", ch, toupper(ch));

    // 6. stdbool.h - true, false
    bool isCodingFun = true;
    if (isCodingFun) {
        printf("Coding is fun!\n");
    }

    // 7. time.h - current time
    time_t now;
    time(&now);
    printf("Current time: %s", ctime(&now));

    // 8. errno.h - simulate file open error
    FILE *fptr = fopen("no_file.txt", "r");
    if (fptr == NULL) {
        perror("File open error");
    } else {
        fclose(fptr);
    }

    // 9. limits.h - INT_MAX
    printf("Max int value: %d\n", INT_MAX);

    // 10. float.h - FLT_MAX
    printf("Max float value: %e\n", FLT_MAX);

    return 0;
}


//  When using the math library, you need to link it with the -lm option.
//  This is done by adding -lm at the end of the compile command.
//  if it is not linked, you will get an error like: 
//  "undefined reference to `sqrt'" or "undefined reference to `pow'"
// run with the linker command: clang -lm -o l23_common_headers l23_common_headers.c 
