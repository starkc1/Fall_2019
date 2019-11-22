#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HALT_OPCODE_a 0x1
#define HALT_OPCODE_b 0x9

void getBytes(unsigned char hex, int byteNum);
int * convertHexToBin(char hex);

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
    
    // while (memory[PCtracker] != HALT_OPCODE_a && memory[PCtracker + 1] != HALT_OPCODE_b) {
    //     int PCindexer = PC;
    //     getBytes(memory[PCindexer], 1);
    //     PC++;
    //     PCtracker = PC;
    // }
    //PROGRAM END
    getBytes('c', 1);
}

void getBytes(unsigned char hex, int byteNum) {
    int *binary = convertHexToBin((char) '0');
    

    for (int i = 0; i < 4; i++) {
        printf("test %d", binary[i]);
    }

    switch (byteNum) {
        case 1:
            
            break;
        case 2:
            break;
    }
}

int * convertHexToBin(char hex) {
    int* bin;
    
    switch (hex) {
        case '0':
            bin[0] = 0;
            bin[1] = 0;
            bin[2] = 0;
            bin[3] = 0;
            break;
        
        // case '1':
        //     bin[0] = '0';
        //     bin[1] = '0';
        //     bin[2] = '0';
        //     bin[3] = '1';
        //     break;
        
        // case '2':
        //     bin[0] = '0';
        //     bin[1] = '0';
        //     bin[2] = '1';
        //     bin[3] = '0';
        //     break;

        // case '3':
        //     bin[0] = '0';
        //     bin[1] = '0';
        //     bin[2] = '1';
        //     bin[3] = '1';
        //     break;
        
        // case '4':
        //     bin[0] = '0';
        //     bin[1] = '0';
        //     bin[2] = '1';
        //     bin[3] = '0';
        //     break;
        
        // case '5':
        //     bin[0] = '0';
        //     bin[1] = '1';
        //     bin[2] = '0';
        //     bin[3] = '1';
        //     break;

        // case '6':
        //     bin[0] = '0';
        //     bin[1] = '1';
        //     bin[2] = '1';
        //     bin[3] = '0';
        //     break;    

        // case '7':
        //     bin[0] = '0';
        //     bin[1] = '1';
        //     bin[2] = '1';
        //     bin[3] = '1';
        //     break;

        // case '8':
        //     bin[0] = '1';
        //     bin[1] = '0';
        //     bin[2] = '0';
        //     bin[3] = '0';
        //     break;
        
        // case '9':
        //     bin[0] = '1';
        //     bin[1] = '0';
        //     bin[2] = '0';
        //     bin[3] = '1';
        //     break;
        
        // case 'A':
        // case 'a':
        //     bin[0] = '1';
        //     bin[1] = '0';
        //     bin[2] = '1';
        //     bin[3] = '0';
        //     break;
        
        // case 'B':
        // case 'b':
        //     bin[0] = '1';
        //     bin[1] = '0';
        //     bin[2] = '1';
        //     bin[3] = '1';
        //     break;

        // case 'C':
        // case 'c':
        //     bin[0] = '1';
        //     bin[1] = '1';
        //     bin[2] = '0';
        //     bin[3] = '0';
        //     break;

        // case 'D':
        // case 'd':
        //     bin[0] = '1';
        //     bin[1] = '1';
        //     bin[2] = '0';
        //     bin[3] = '1';
        //     break;

        // case 'E':
        // case 'e':
        //     bin[0] = '1';
        //     bin[1] = '1';
        //     bin[2] = '1';
        //     bin[3] = '0';
        //     break;

        // case 'F':
        // case 'f':
        //     bin[0] = '1';
        //     bin[1] = '1';
        //     bin[2] = '1';
        //     bin[3] = '1';
        //     break;
    }

    return (bin);
}