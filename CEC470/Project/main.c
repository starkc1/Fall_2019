#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    //CREATE AND READ IN MEMORY FILE BEGIN
    FILE *file = NULL;
    int i = 0;
    int memory[65536];

    file = fopen("mem_in.txt", "r");
    
    if (file == NULL) {
        printf("Error");
        exit(0);
    }

    int num;
    while(!feof(file)) {
        fscanf(file, "%d", num);
        //memory[i] = num;
        
        printf("Number: %d\n", num);
        i++;
    }

    // while (fgets(num, sizeof num, file) != NULL) {
    //     memory[i] = num;
    //     i++;
    // }
    fclose(file);

    printf("%d", memory[0]);
    //CREATE AND READ IN MEMORY FILE END



}