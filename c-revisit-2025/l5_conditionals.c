#include <stdio.h>

int main(){
  int num;


  printf("Enter a number: ");
  scanf("%d", &num);

  if(num > 0){
    printf("%s\n", "positive number");
  }else if (num < 0){
    printf("%s\n", "negative number");
  }else{
    printf("%s\n", "zero");
  }
}
