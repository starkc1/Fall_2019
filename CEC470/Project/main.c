#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

//VARIABLES START
#define HALT_OPCODE 0x19

unsigned char memory[65536];
unsigned char instruc[8] = "";

unsigned char ACC = 0;
unsigned char IR = 0;
unsigned int MAR = 0;
unsigned int PC = 0;
//VARIABLES END

//FUNCTIONS START 
void convertHexToBin(char hex);

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
    IR = memory[PC];
    printf("%02x ", IR);
}

int convertHexToDecimal(char hex[2]) {
    //char hex[2] = "";
    //strncat(hex, hex1, 1);
    //strncat(hex, hex2, 1);

    int count = 0;
    int dec = 0;
    int dig;
    int i;

    for (i = 1; i >= 0; i--) {
        switch (hex[i]) {
        case 'a':
            dig = 10;
            break;
        case 'b':
            dig = 11;
            break;
        case 'c':
            dig = 12;
            break;
        case 'd':
            dig = 13;
            break;
        case 'e':
            dig = 14;
            break;
        case 'f':
            dig = 15;
            break;
        default:
            dig = hex[i] - 0x30;
            break;
        }
        dec = dec + (dig) * pow((double)16, (double)count);
        count++;
    }
    //printf("%s -> %d\n", hex, dec);
    return dec;
}

void executeNextInstruction() {
    char newIR[2] = "";
    sprintf(newIR, "%02x", IR);
    //printf("0x%c\n", newIR[1]);
    convertHexToBin(newIR[0]);
    convertHexToBin(newIR[1]);
    printf("0b%s ", instruc);

    if (instruc[0] == '1') { //Logical Operation
        printf("%s\n", "Math Op");
    } else { // Non-Logical Operation
        char lastBits[3] = "";
        for (int j = 5; j < 8; j++) {
            strncat(lastBits, &instruc[j], 1);
        } 
        if (instruc[3] == '0') { //Memory Operation
            printf("%s\n", "Memory Op");
            if (instruc[4] == '0') { //STORE
                if (strcmp(lastBits, "000") == 0) {

                } else if (strcmp(lastBits, "001") == 0) {

                } else if (strcmp(lastBits, "010") == 0) {

                } else if (strcmp(lastBits, "100") == 0) {

                } else if (strcmp(lastBits, "101") == 0) {

                } else if (strcmp(lastBits, "110") == 0) {

                }
            } else { //LOAD
                int PCIndex = PC;
                int address = 0;
                int value = 0;
                if (strcmp(lastBits, "000") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    ACC = memory[address];
                    PC = PC + 4;
                } else if (strcmp(lastBits, "001") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    ACC = value;
                    PC = PC + 3;
                } else if (strcmp(lastBits, "010") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    ACC = convertHexToDecimal(nextHex);
                    PC = PC + 3;
                } else if (strcmp(lastBits, "100") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    nextHex[0] = 0;
                    sprintf(nextHex, "%02x", memory[PCIndex + 2]);
                    address = address + convertHexToDecimal(nextHex);
                    MAR = address;
                    PC = PC + 3;
                } else if (strcmp(lastBits, "101") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    nextHex[0] = 0;

                    sprintf(nextHex, "%02x", memory[PCIndex + 2]);
                    value = value + convertHexToDecimal(nextHex);
                    MAR = value;
                } else if (strcmp(lastBits, "110") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    nextHex[0] = 0;

                    sprintf(nextHex, "%02x", memory[MAR + 1]);
                    value = value + convertHexToDecimal(nextHex);
                    MAR = value;
                }
            }
        } else { //Branch Operation
            printf("%s\n", "Branch Op");
        }
    }

    instruc[0] = 0;
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
        //printf("0x%02x\n", memory[PC]);
        fetchNextInstruction();
        executeNextInstruction();
        //PC = PC + 1;
    }
    return 0;
}

void convertHexToBin(char hex) {
    
    switch (hex) {
        case '0':
            strcat(instruc, "0000");
            break;
        
        case '1':
            strcat(instruc, "0001");
            break;
        
        case '2':
            strcat(instruc, "0010");
            break;

        case '3':
            strcat(instruc, "0011");
            break;
        
        case '4':
            strcat(instruc, "0100");
            break;
        
        case '5':
            strcat(instruc, "0101");
            break;

        case '6':
            strcat(instruc, "0110");
            break;    

        case '7':
            strcat(instruc, "0111");
            break;

        case '8':
            strcat(instruc, "1000");
            break;
        
        case '9':
            strcat(instruc, "1001");
            break;
        
        case 'A':
        case 'a':
            strcat(instruc, "1010");
            break;
        
        case 'B':
        case 'b':
            strcat(instruc, "1011");
            break;

        case 'C':
        case 'c':
            strcat(instruc, "1100");
            break;

        case 'D':
        case 'd':
            strcat(instruc, "1101");
            break;

        case 'E':
        case 'e':
            strcat(instruc, "1110");
            break;

        case 'F':
        case 'f':
            strcat(instruc, "1111");
            break;
    }

}