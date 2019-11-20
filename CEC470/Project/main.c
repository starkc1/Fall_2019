#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertHexToBin(unsigned char hex1);

unsigned char memory[65536] = {0};
unsigned char ACC = 0;
unsigned char IR = 0;
unsigned int MAR = 0;
unsigned int PC = 0;

unsigned char currentInstruction[24] = {0};
int main() {

    //CREATE AND READ IN MEMORY FILE BEGIN
    FILE *file = NULL;
    int i = 0;
    

    file = fopen("mem_in.txt", "r");
    
    if (file == NULL) {
        printf("Error");
        exit(0);
    }

    char c;
    while (!feof(file)) {
        c = getc(file);

        if (c == ' ') {

        } else {
            memory[i] = c;
            //printf("%c", memory[i]);
        }

        i++;
    }
    fclose(file);
    //CREATE AND READ IN MEMORY FILE END

    //PROGRAM START

    convertHexToBin(memory[0]);
    //PROGRAM END
}

void convertHexToBin(unsigned char hex1) {
    int value;
    printf("%c", hex1);
}