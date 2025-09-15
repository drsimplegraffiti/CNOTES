#include <stdio.h>

int main(){
    FILE *fptr = fopen("file.txt", "w");

    if(fptr == NULL){
        printf("%s\n", "Error opening file");
    }

    fprintf(fptr, "Hello file!");
    fclose(fptr);

    return 0;
}
