#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

//VARIABLES START
#define HALT_OPCODE 0x19

unsigned char memory[65536];
unsigned char instruc[8] = "";
unsigned char hexStore[2];

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

void convertDecimalToHex(int num) {
    int i = 0;
    hexStore[0] = 0;
    while (num != 0) {
        int temp = 0;

        temp = num % 16;

        if (temp < 10) {
            hexStore[i] = temp  + 48;
            i = i + 1;
        } else {
            hexStore[i] = temp + 55;
            i = i + 1;
        }

        num = num / 16;
    }

    int j = i - 1;
    i = 0;
    char charTemp;
    while (i < j) {
        charTemp = hexStore[i];
        hexStore[i] = hexStore[j];
        hexStore[j] = charTemp;
        i++;
        j--;
    }
}

void executeNextInstruction() {
    char newIR[2] = "";
    sprintf(newIR, "%02x", IR);
    //printf("0x%c\n", newIR[1]);
    convertHexToBin(newIR[0]);
    convertHexToBin(newIR[1]);
    printf("0b%s ", instruc);
    printf("PC: %d ", PC);

    if (instruc[0] == '1') { //Logical Operation
        printf("%s\n", "Math Op");
        int PCIndex = PC;
        int address = 0;
        int value = 0;
        char functionBits[3] = "";
        for (int j = 1; j < 4; j++) {
            strncat(functionBits, &instruc[j], 1);
        }
        
        char destBits[2] = "";
        for (int j = 4; j < 6; j++) {
            strncat(destBits, &instruc[j], 1);
        }

        char sourceBits[2] = "";
        for (int j = 6; j < 8; j++) {
            strncat(sourceBits, &instruc[j], 1);
        }

        if (strcmp(functionBits, "000") == 0) { //AND
            if (strcmp(destBits, "00") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    memory[MAR] = memory[MAR] & value;
                } else if (strcmp(sourceBits, "01") == 0) {
                    memory[MAR] = memory[MAR] & ACC;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    memory[MAR] = memory[MAR] & value;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    memory[MAR] = memory[MAR] & value;
                }
            } else if (strcmp(destBits, "01") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    ACC = ACC & value;
                } else if (strcmp(sourceBits, "01") == 0) {
                    ACC = ACC & ACC;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    ACC = ACC & value;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    ACC = ACC & value;
                }
            } else if (strcmp(destBits, "10") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    MAR = MAR & value;
                } else if (strcmp(sourceBits, "01") == 0) {
                    MAR = MAR & ACC;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    MAR = MAR & value;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    MAR = MAR & value;
                }
            } else if (strcmp(destBits, "11") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    memory[PC] = memory[PC] & value;
                } else if (strcmp(sourceBits, "01") == 0) {
                    memory[PC] = memory[PC] & ACC;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    memory[PC] = memory[PC] & value;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    memory[PC] = memory[PC] & value;
                }
            }
        } else if (strcmp(functionBits, "001") == 0) { //OR
            if (strcmp(destBits, "00") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    memory[MAR] = memory[MAR] | value;
                } else if (strcmp(sourceBits, "01") == 0) {
                    memory[MAR] = memory[MAR] | ACC;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    memory[MAR] = memory[MAR] | value;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    memory[MAR] = memory[MAR] | value;
                }
            } else if (strcmp(destBits, "01") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    ACC = ACC | value;
                } else if (strcmp(sourceBits, "01") == 0) {
                    ACC = ACC | ACC;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    ACC = ACC | value;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    ACC = ACC | value;
                }
            } else if (strcmp(destBits, "10") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    MAR = MAR | value;
                } else if (strcmp(sourceBits, "01") == 0) {
                    MAR = MAR | ACC;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    MAR = MAR | value;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    MAR = MAR | value;
                }
            } else if (strcmp(destBits, "11") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    memory[PC] = memory[PC] | value;
                } else if (strcmp(sourceBits, "01") == 0) {
                    memory[PC] = memory[PC] | ACC;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    memory[PC] = memory[PC] | value;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    memory[PC] = memory[PC] | value;
                }
            }
        } else if (strcmp(functionBits, "010") == 0) { //XOR
            if (strcmp(destBits, "00") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    memory[MAR] = memory[MAR] ^ value;
                } else if (strcmp(sourceBits, "01") == 0) {
                    memory[MAR] = memory[MAR] ^ ACC;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    memory[MAR] = memory[MAR] ^ value;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    memory[MAR] = memory[MAR] ^ value;
                }
            } else if (strcmp(destBits, "01") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    ACC = ACC ^ value;
                } else if (strcmp(sourceBits, "01") == 0) {
                    ACC = ACC ^ ACC;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    ACC = ACC ^ value;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    ACC = ACC ^ value;
                }
            } else if (strcmp(destBits, "10") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    MAR = MAR ^ value;
                } else if (strcmp(sourceBits, "01") == 0) {
                    MAR = MAR ^ ACC;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    MAR = MAR ^ value;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    MAR = MAR ^ value;
                }
            } else if (strcmp(destBits, "11") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    memory[PC] = memory[PC] ^ value;
                } else if (strcmp(sourceBits, "01") == 0) {
                    memory[PC] = memory[PC] ^ ACC;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    memory[PC] = memory[PC] ^ value;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    memory[PC] = memory[PC] ^ value;
                }
            }
        } else if (strcmp(functionBits, "011") == 0) { //ADD
            if (strcmp(destBits, "00") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    memory[MAR] = memory[MAR] + value;
                } else if (strcmp(sourceBits, "01") == 0) {
                    memory[MAR] = memory[MAR] + ACC;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    memory[MAR] = memory[MAR] + value;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    memory[MAR] = memory[MAR] + value;
                }
            } else if (strcmp(destBits, "01") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    ACC = ACC + value;
                } else if (strcmp(sourceBits, "01") == 0) {
                    ACC = ACC + ACC;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    ACC = ACC + value;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    ACC = ACC + value;
                }
            } else if (strcmp(destBits, "10") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    MAR = MAR + value;
                } else if (strcmp(sourceBits, "01") == 0) {
                    MAR = MAR + ACC;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    MAR = MAR + value;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    MAR = MAR + value;
                }
            } else if (strcmp(destBits, "11") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    memory[PC] = memory[PC] + value;
                } else if (strcmp(sourceBits, "01") == 0) {
                    memory[PC] = memory[PC] + ACC;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    memory[PC] = memory[PC] + value;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    memory[PC] = memory[PC] + value;
                }
            }
        } else if (strcmp(functionBits, "100") == 0) { //SUB
            if (strcmp(destBits, "00") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    memory[MAR] = memory[MAR] - value;
                } else if (strcmp(sourceBits, "01") == 0) {
                    memory[MAR] = memory[MAR] - ACC;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    memory[MAR] = memory[MAR] - value;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    memory[MAR] = memory[MAR] - value;
                }
            } else if (strcmp(destBits, "01") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    ACC = ACC - value;
                } else if (strcmp(sourceBits, "01") == 0) {
                    ACC = ACC - ACC;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    ACC = ACC - value;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    ACC = ACC - value;
                }
            } else if (strcmp(destBits, "10") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    MAR = MAR - value;
                } else if (strcmp(sourceBits, "01") == 0) {
                    MAR = MAR - ACC;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    MAR = MAR - value;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    MAR = MAR - value;
                }
            } else if (strcmp(destBits, "11") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    memory[PC] = memory[PC] - value;
                } else if (strcmp(sourceBits, "01") == 0) {
                    memory[PC] = memory[PC] - ACC;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    memory[PC] = memory[PC] - value;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    memory[PC] = memory[PC] - value;
                }
            }
        } else if (strcmp(functionBits, "101") == 0) { //INC
            if (strcmp(destBits, "00") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    memory[MAR] = value++;
                } else if (strcmp(sourceBits, "01") == 0) {
                    memory[MAR] = ACC++;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    memory[MAR] = value++;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    memory[MAR] = value++;
                }
            } else if (strcmp(destBits, "01") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    ACC = value++;
                } else if (strcmp(sourceBits, "01") == 0) {
                    ACC = ACC++;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    ACC = value++;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    ACC = value++;
                }
            } else if (strcmp(destBits, "10") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    MAR = value++;
                } else if (strcmp(sourceBits, "01") == 0) {
                    MAR = ACC++;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    MAR = value++;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    MAR = value++;
                }
            } else if (strcmp(destBits, "11") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    memory[PC] = value++;
                } else if (strcmp(sourceBits, "01") == 0) {
                    memory[PC] = ACC++;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    memory[PC] = value++;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    memory[PC] = value++;
                }
            }
        } else if (strcmp(functionBits, "110") == 0) { //DEC
            if (strcmp(destBits, "00") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    memory[MAR] = value--;
                } else if (strcmp(sourceBits, "01") == 0) {
                    memory[MAR] = ACC--;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    memory[MAR] = value--;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    memory[MAR] = value--;
                }
            } else if (strcmp(destBits, "01") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    ACC = value--;
                } else if (strcmp(sourceBits, "01") == 0) {
                    ACC = ACC--;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    ACC = value--;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    ACC = value--;
                }
            } else if (strcmp(destBits, "10") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    MAR = value--;
                } else if (strcmp(sourceBits, "01") == 0) {
                    MAR = ACC--;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    MAR = value--;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    MAR = value--;
                }
            } else if (strcmp(destBits, "11") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    memory[PC] = value--;
                } else if (strcmp(sourceBits, "01") == 0) {
                    memory[PC] = ACC--;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    memory[PC] = value--;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    memory[PC] = value--;
                }
            }
        } else if (strcmp(functionBits, "111") == 0) { //NOT
            if (strcmp(destBits, "00") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    memory[MAR] = ~value;
                } else if (strcmp(sourceBits, "01") == 0) {
                    memory[MAR] = ~ACC;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    memory[MAR] = ~value;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    memory[MAR] = ~value;
                }
            } else if (strcmp(destBits, "01") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    ACC = ~value;
                } else if (strcmp(sourceBits, "01") == 0) {
                    ACC = ~ACC;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    ACC = ~value;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    ACC = ~value;
                }
            } else if (strcmp(destBits, "10") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    MAR = ~value;
                } else if (strcmp(sourceBits, "01") == 0) {
                    MAR = ~ACC;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    MAR = ~value;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    MAR = ~value;
                }
            } else if (strcmp(destBits, "11") == 0) {
                if (strcmp(sourceBits, "00") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    memory[PC] = ~value;
                } else if (strcmp(sourceBits, "01") == 0) {
                    memory[PC] = ~ACC;
                } else if (strcmp(sourceBits, "10") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    memory[PC] = ~value;
                } else if (strcmp(sourceBits, "11") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    value = convertHexToDecimal(&memory[address]);
                    memory[PC] = ~value;
                }
            }
        }
     
        PC = PC + 4;
    
    
    } else { // Non-Logical Operation
    
        char lastBits[3] = "";
        for (int j = 5; j < 8; j++) {
            strncat(lastBits, &instruc[j], 1);
        } 
        if (instruc[3] == '0') { //Memory Operation
            //printf("%s\n", "Memory Op");
            if (instruc[4] == '0') { //STORE
                printf("%s\n", "STORE Op");
                int PCIndex = PC;
                int address = 0;
                int value = 0;

                if (strcmp(lastBits, "000") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    convertDecimalToHex(ACC);
                    

                    memory[address] = (ascii_to_hex(hexStore[0]) << 4 | ascii_to_hex(hexStore[1]));
                    //PC = PC + 3;
                } else if (strcmp(lastBits, "001") == 0) {

                } else if (strcmp(lastBits, "010") == 0) {
                    char nextHex[2] = "";
                    convertDecimalToHex(ACC);
                    memory[MAR] = (ascii_to_hex(hexStore[0]) << 4 | ascii_to_hex(hexStore[1]));
                } else if (strcmp(lastBits, "100") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    convertDecimalToHex(MAR);
                    memory[address] = (ascii_to_hex(hexStore[0]) << 4 | ascii_to_hex(hexStore[1]));
                    //PC = PC + 3;
                } else if (strcmp(lastBits, "101") == 0) {
                    
                } else if (strcmp(lastBits, "110") == 0) {
                    char nextHex[2] = "";
                    convertDecimalToHex(MAR);
                    memory[MAR] = (ascii_to_hex(hexStore[0]) << 4 | ascii_to_hex(hexStore[1]));
                    //PC = PC + 3;
                }
                PC = PC + 4;
            } else { //LOAD
                printf("%s\n", "LOAD Op");
                int PCIndex = PC;
                int address = 0;
                int value = 0;
                if (strcmp(lastBits, "000") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    ACC = memory[address];
                    //PC = PC + 3;
                } else if (strcmp(lastBits, "001") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    ACC = value;
                    //PC = PC + 3;
                } else if (strcmp(lastBits, "010") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    ACC = convertHexToDecimal(nextHex);
                    //PC = PC + 3;
                } else if (strcmp(lastBits, "100") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    address = convertHexToDecimal(nextHex);
                    nextHex[0] = 0;
                    sprintf(nextHex, "%02x", memory[PCIndex + 2]);
                    address = address + convertHexToDecimal(nextHex);
                    MAR = memory[address];
                    //PC = PC + 3;
                } else if (strcmp(lastBits, "101") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[PCIndex + 1]);
                    value = convertHexToDecimal(nextHex);
                    nextHex[0] = 0;

                    sprintf(nextHex, "%02x", memory[PCIndex + 2]);
                    value = value + convertHexToDecimal(nextHex);
                    MAR = value;
                    //PC = PC + 3;
                } else if (strcmp(lastBits, "110") == 0) {
                    char nextHex[2] = "";
                    sprintf(nextHex, "%02x", memory[MAR]);
                    value = convertHexToDecimal(nextHex);
                    nextHex[0] = 0;

                    sprintf(nextHex, "%02x", memory[MAR + 1]);
                    value = value + convertHexToDecimal(nextHex);
                    MAR = value;
                    //PC = PC + 3;
                }
                PC = PC + 4;
            }
        } else { //Branch Operation
            int PCIndex = PC;
            int address = 0;
            printf("%s\n", "Branch Op");
            PC = PC + 4;
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

    // convertDecimalToHex(234);
    // printf("0x%s\n", hexStore);

    while(memory[PC] != HALT_OPCODE) {
        //printf("0x%02x\n", memory[PC]);
        
        fetchNextInstruction();
        executeNextInstruction();

        //PC = PC + 1;
    }

    FILE *outputFile;
    outputFile = fopen("mem_out.txt", "w");

    for (int i = 0; i < sizeof(memory); i++) {
        if (i % 10 == 0) {
            fprintf(file, "\n");
        } else {
            fprintf(file, "%02x ", memory[i]);
        }
    }
    // for (int i = 0; i < 400; i++) {
    //     if (i % 10 == 0) {
    //         printf("\n");   
    //     } else {
    //         printf("%02x ", memory[i]);
    //     }
        
    // }
    
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