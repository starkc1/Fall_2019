#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//VARIABLES START
#define HALT_OPCODE_a '1'
#define HALT_OPCODE_b '9'
#define HALT_OPCODE "19"

//unsigned char memory[65536] = {0};
char memory[65538] = "";
unsigned char ACC[24] = "";
char IR[24] = "";
unsigned char MAR[24] = "";
int PC = 0;

//char IR[24] = "";
//VARIABLES END


//FUNCTIONS START
void convertHexToBin(char hex);
void fetchNextInstruction();
void executeNextInstruction();

bool checkIfMemoryOp();
bool checkIfBranchOp();

void executeMemoryOp();

void performAddCommand();
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
            if (c != '\n') {
                strncat(memory, &c, 1);
            }
            
        }
        i++;
    }
    fclose(file);
    //LOAD AND CREATE MEMORY END

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
            PCIndexer = PCIndexer + 1;
        }
    }
    //READ THROUGH INSTRUCTIONS END
}

void fetchNextInstruction() {
    int instructionLength = PC + 6;

    for (int i = PC; i < instructionLength; i++) {
        convertHexToBin(memory[i]);
    }
    printf("%s\n", IR);
}

void executeNextInstruction() {
    switch (IR[0]) {
        case '0':
            if (checkIfMemoryOp()) {
                executeMemoryOp();
            } else if (checkIfBranchOp()) {
            }
            break;
        case '1':
            char function[3] = "";
            strncat(function, &IR[1], 1);
            strncat(function, &IR[2], 1);
            strncat(function, &IR[3], 1);

            if (strcmp(function, '000') == 0) {
                performAddCommand();
            } else if (strcmp(function, '001') == 0) {

            } else if (strcmp(function, '010') == 0) {

            } else if (strcmp(function, '011') == 0) {

            } else if (strcmp(function, '100') == 0) {

            } else if (strcmp(function, '101') == 0) {

            } else if (strcmp(function, '110') == 0) {

            } else if (strcmp(function, '111') == 0) {

            }

            break;
    }


    IR[0] = 0;
}

void performAddCommand() {
    
}

void executeMemoryOp() {
    switch(IR[4]) {
        case '0':

            break;
        case '1':
            switch (IR[5]) {
                case '0':

                    break;
                case '1':

                    break;
            }
            break;
    }
}

bool checkIfMemoryOp() {
    char memoryTest[12] = "";
    for (int i = 0; i < 4; i++) {
        strncat(memoryTest, &IR[i], 1);
    }

    if (strcmp(memoryTest, "0000") == 0) {
        return true;
    } else {
        return false;
    }

    memoryTest[0] = 0;
}

bool checkIfBranchOp() {
    char branchTest[24] = "";

    for (int i = 0; i < 5; i++) {
        strncat(branchTest, &IR[i], 1);
    }

    if (strcmp(branchTest, "00010") == 0) {
        return true;
    } else {
        return false;
    }

    branchTest[0] = 0;
}

void convertHexToBin(char hex) {
    
    switch (hex) {
        case '0':
            strcat(IR, "0000");
            break;
        
        case '1':
            strcat(IR, "0001");
            break;
        
        case '2':
            strcat(IR, "0010");
            break;

        case '3':
            strcat(IR, "0011");
            break;
        
        case '4':
            strcat(IR, "0100");
            break;
        
        case '5':
            strcat(IR, "0101");
            break;

        case '6':
            strcat(IR, "0110");
            break;    

        case '7':
            strcat(IR, "0111");
            break;

        case '8':
            strcat(IR, "1000");
            break;
        
        case '9':
            strcat(IR, "1001");
            break;
        
        case 'A':
        case 'a':
            strcat(IR, "1010");
            break;
        
        case 'B':
        case 'b':
            strcat(IR, "1011");
            break;

        case 'C':
        case 'c':
            strcat(IR, "1100");
            break;

        case 'D':
        case 'd':
            strcat(IR, "1101");
            break;

        case 'E':
        case 'e':
            strcat(IR, "1110");
            break;

        case 'F':
        case 'f':
            strcat(IR, "1111");
            break;
    }

}