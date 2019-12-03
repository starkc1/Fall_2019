#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//VARIABLES START
#define HALT_OPCODE 0x19

unsigned char memory[65536];
unsigned char ACC = 0;
unsigned char IR = 0;
unsigned int MAR = 0;
unsigned int PC = 0;
//VARIABLES END

//FUNCTIONS START 
int ascii_to_hex(char c) {
    int num = (int) c;

    if (num < 58 && num > 47) {
        return num - 48;
    }
    if (num < 103 && num > 96) {
        return num - 87;
    }
    return num;
}

void fetchNextInstruction() {

}

void executeNextInstruction() {
    
}
//FUNCTIONS END

int main() {
    FILE *file = fopen("mem_in.txt", "rt");

    if (file == NULL) {
        printf("%s", "Please Put The File In The Same Folder as exe, and anme as mem_in.txt");
        exit(0);
    }

    char char1, char2;
    char c1, c2;
    int i = 0;
    unsigned char sum;

    while(!feof(file)) {
        char1 = fgetc(file);
        if (char1 != ' ' && char1 != '\n') {
            char2 = fgetc(file);
            if (char2 != ' ' && char2 != '\n') {
                c1 = ascii_to_hex(char1);
                c2 = ascii_to_hex(char2);
                //printf("%c: %d %c: %d\n", char1, c1, char2, c2);
                sum = c1 << 4 | c2;
                //printf("Number %d: 0x%02x\n", i, sum);
                memory[i] = sum;
                i++;
            }
        }
    }
    fclose(file);

    while(memory[PC] != HALT_OPCODE) {
        printf("0x%02x\n", memory[PC]);
        PC = PC + 1;
    }
    return 0;
}

