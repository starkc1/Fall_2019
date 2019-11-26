#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//VARIABLES START
#define HALT_OPCODE_a '1'
#define HALT_OPCODE_b '9'
#define HALT_OPCODE "19"

//unsigned char memory[65536] = {0};
char memory[65538] = "";
unsigned char ACC = 0;
unsigned char IR = 0;
unsigned int MAR = 0;
int PC = 0;

char binaryNum[24] = "";
//VARIABLES END


//FUNCTIONS START
void convertHexToBin(char hex);
void fetchNextInstruction();
void executeNextInstruction();
//FUNCTIONS END

int main() {

    //LOAD AND CREATE MEMORY START
    FILE *file = NULL;
    int i = 0;

    file = fopen("mem_in.txt", "r");

    if (file == NULL) {
        printf("Please put the text file in the same folder as exe, and name as mem_in.txt");
        exit(0);
    }

    char c;
    while (!feof(file)) {
        c = getc(file);

        if (c != ' ') {
            //memory[i] = c;
            strncat(memory, &c, 1);
        }
        i++;
    }
    fclose(file);
    //LOAD AND CREATE MEMORY END
    

    // convertHexToBin(memory[0]);
    // convertHexToBin(memory[1]);
    // convertHexToBin(memory[2]);
    // convertHexToBin(memory[3]);
    // convertHexToBin(memory[4]);
    // convertHexToBin(memory[5]);
    // printf("%s\n", binaryNum);
    //printf("%c", binaryNum[0]);

    //READ THROUGH INSTRUCTIONS START
    char currentHex[2] = "";
    int PCIndexer = 0;
    for (int j = 0; j < sizeof(memory); j++) {
        strncat(currentHex, &memory[PCIndexer], 1);
        strncat(currentHex, &memory[PCIndexer + 1], 1);

        if (strcmp(currentHex, HALT_OPCODE) == 0) {
            j = sizeof(memory) + 1;
            return 0;
        } else { 
            //printf("%s\n", currentHex);
            fetchNextInstruction();
            executeNextInstruction();
            currentHex[0] = 0;
            PCIndexer = PC;
        }
    }
    //READ THROUGH INSTRUCTIONS END
}

void fetchNextInstruction() {
    int instructionLength = PC + 6;

    for (int i = PC; i < instructionLength; i++) {
        printf("%c", memory[i]);
        convertHexToBin(memory[i]);
    }
    printf("\n%s\n\n", binaryNum);
}

void executeNextInstruction() {
    PC = PC + 2;

    binaryNum[0] = 0;
}

void convertHexToBin(char hex) {
    
    switch (hex) {
        case '0':
            strcat(binaryNum, "0000");
            break;
        
        case '1':
            strcat(binaryNum, "0001");
            break;
        
        case '2':
            strcat(binaryNum, "0010");
            break;

        case '3':
            strcat(binaryNum, "0011");
            break;
        
        case '4':
            strcat(binaryNum, "0100");
            break;
        
        case '5':
            strcat(binaryNum, "0101");
            break;

        case '6':
            strcat(binaryNum, "0110");
            break;    

        case '7':
            strcat(binaryNum, "0111");
            break;

        case '8':
            strcat(binaryNum, "1000");
            break;
        
        case '9':
            strcat(binaryNum, "1001");
            break;
        
        case 'A':
        case 'a':
            strcat(binaryNum, "1010");
            break;
        
        case 'B':
        case 'b':
            strcat(binaryNum, "1011");
            break;

        case 'C':
        case 'c':
            strcat(binaryNum, "1100");
            break;

        case 'D':
        case 'd':
            strcat(binaryNum, "1101");
            break;

        case 'E':
        case 'e':
            strcat(binaryNum, "1110");
            break;

        case 'F':
        case 'f':
            strcat(binaryNum, "1111");
            break;
    }

}