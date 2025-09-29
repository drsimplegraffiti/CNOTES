#include <stdio.h>

int main() {
  int choice;
  double num1, num2, result;

  do {
    printf("\n===== Simple Calculator =====\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Modulus (%%)\n");
    printf("6. Exit\n");
    printf("Choose an operation: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 5) {
      printf("Enter first number: ");
      scanf("%lf",
            &num1); // lf is the %lf is a format specifier used with functions
                    // like scanf and printf.Used for reading double
      printf("Enter second number: ");
      scanf("%lf", &num2);
    }

    switch (choice) {
    case 1:
      result = num1 + num2;
      printf("Result: %.2lf\n", result);
      break;
    case 2:
      result = num1 - num2;
      printf("Result: %.2lf\n", result);
      break;
    case 3:
      result = num1 * num2;
      printf("Result: %.2lf\n", result);
      break;
    case 4:
      if (num2 != 0) {
        result = num1 / num2;
        printf("Result: %.2lf\n", result);
      } else {
        printf("Error: Division by zero!\n");
      }
      break;
    case 5:
      // Modulus only works on integers
      printf("Result: %d\n", (int)num1 % (int)num2);
      break;
    case 6:
      printf("Exiting... Goodbye!\n");
      break;
    default:
      printf("Invalid choice. Please try again.\n");
    }

  } while (choice != 6);

  return 0;
}
