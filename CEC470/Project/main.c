#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HALT_OPCODE_a 0x1
#define HALT_OPCODE_b 0x9

void getBytes(unsigned char hex1, int byteNum);
char convertHexToBin(hex);

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
    int PCtracker = PC;
    while (memory[PCtracker] != HALT_OPCODE_a && memory[PCtracker + 1] != HALT_OPCODE_b) {
        int PCindexer = PC;


    }
    // while (memory[PC] != HALT_OPCODE) {
    //     printf("%c", memory[PC]);
    //     // getOpcode(memory[PC]);
    //     // get2ndByte(memory[PC + 1]);
    //     // get3rdByte(memory[PC + 2]);
    //     PC++;
    // }
    //PROGRAM END
}

void getBytes(unsigned char hex, int byteNum) {
    switch (byteNum) {
        case 1:
            switch (hex) {
                case '0':
                currentInstruction[0] = '0';
                currentInstruction[1] = '0';
                currentInstruction[2] = '0';
                currentInstruction[3] = '0';
                break;
            }
            break;
        case 2:
            switch (hex) {
                case '0':
                currentInstruction[0] = '0';
                currentInstruction[1] = '0';
                currentInstruction[2] = '0';
                currentInstruction[3] = '0';
                break;
            }
            break;
    }
}

char convertHexToBin(hex) {
    char bin[4];

    switch (hex) {
        case '0':
            bin[0] = '0';
            bin[1] = '0';
            bin[2] = '0';
            bin[3] = '0';
            break;
        
        case '1':
            bin[0] = '0';
            bin[1] = '0';
            bin[2] = '0';
            bin[3] = '1';
            break;
        
        case '2':
            bin[0] = '0';
            bin[1] = '0';
            bin[2] = '1';
            bin[3] = '0';
            break;

        case '3':
            bin[0] = '0';
            bin[1] = '0';
            bin[2] = '1';
            bin[3] = '1';
            break;
        
        case '4':
            bin[0] = '0';
            bin[1] = '0';
            bin[2] = '1';
            bin[3] = '0';
            break;
    }

    return bin;
}