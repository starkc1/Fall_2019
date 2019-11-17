#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    //CREATE AND READ IN MEMORY FILE BEGIN
    FILE *file = NULL;
    int i = 0;
    char* memory[65536];

    file = fopen("mem_in.txt", "r");
    
    if (file == NULL) {
        printf("Error");
        exit(0);
    }

    char num[3];
    // while(!feof(file)) {
    //     fscanf(file, "%s", num);
    //     memory[i] = (char) num;
        
    //     printf("Number: %s\n", memory[i]);
    //     i++;
    // }

    while (fgets(num, sizeof num, file) != NULL) {
        memory[i] = num;
        i++;
    }
    fclose(file);

    printf("%d", memory[0]);
    //CREATE AND READ IN MEMORY FILE END



}