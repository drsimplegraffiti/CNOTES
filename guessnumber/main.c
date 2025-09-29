#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int random, guess;
  int no_of_guess = 0;

  // Seed the random number generator
  srand(time(NULL));
  random = (rand() % 10) + 1; // Random number between 1 and 10

  printf("Welcome to the Number Guessing Game!\n");

  do {
    printf("Please enter your guess between 1 and 10: ");
    scanf("%d", &guess);
    no_of_guess++;

    printf("Current number of guesses: %d\n", no_of_guess);
    printf("Number entered: %d\n", guess);

    if (guess < random) {
      printf("Too small! Try a larger number.\n");
    } else if (guess > random) {
      printf("Too large! Try a smaller number.\n");
    } else {
      printf("🎉 Congratulations! You guessed the number in %d attempts.\n",
             no_of_guess);
    }
  } while (guess != random);

  return 0;
}
