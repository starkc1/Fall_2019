#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    //CREATE AND READ IN MEMORY FILE BEGIN
    FILE *file = NULL;
    int i = 0;
    unsigned char memory[65536] = {0};

    file = fopen("mem_in.txt", "r");
    
    if (file == NULL) {
        printf("Error");
        exit(0);
    }

    char c;
    while (!feof(file)) {
        c = getc(file);
        memory[i] = c;
        //printf("%c", memory[i]);
        i++;
    }
    fclose(file);
    //CREATE AND READ IN MEMORY FILE END



}