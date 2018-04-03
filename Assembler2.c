/*Matt Strand
 *Assembler attempt 2
 *START: 2/28/2018
 *LAST EDIT: 3/27/2018
 */

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#include "symbolTable.h"

/*
*
*This program works without the symbol table.
*Come back later and make this work with the symbol table,
*Figure out why only the first 2 assembly instructions are being converted into binary.
*
*/


int charToInt(char);
char intToChar(int);
char* removeAt(char*);
int stringToInt(char*);
char* intToBinary(int);
bool aOrC(char*);
bool jumpOrDest(char*);
char* jumpBits(char*);
char* destBits(char*);
bool compHelper(char*);
char* compBits(char*);
char* finalBinaryC(char*,char*,char*);


int main()
{
    FILE *send;
    char sendBuff[256];
    send = fopen("symbols.txt","w");

    //ADD PREDEFINED SYMBOLS
    fputs("SP=0\n", send);
    fputs("LCL=1\n", send);
    fputs("ARG=2\n", send);
    fputs("THIS=3\n", send);
    fputs("THAT=4\n", send);
    fputs("R0=0\n", send);
    fputs("R1=1\n", send);
    fputs("R2=2\n", send);
    fputs("R3=3\n", send);
    fputs("R4=4\n", send);
    fputs("R5=5\n", send);
    fputs("R6=6\n", send);
    fputs("R7=7\n", send);
    fputs("R8=8\n", send);
    fputs("R9=9\n", send);
    fputs("R10=10\n", send);
    fputs("R11=11\n", send);
    fputs("R12=12\n", send);
    fputs("R13=13\n", send);
    fputs("R14=14\n", send);
    fputs("R15=15\n", send);
    fputs("SCREEN=16328\n", send);
    fputs("KBD=24576\n", send);

/*
pass 1 is adding the symbols to the table without the ()
pass 2
*/
    //FIRST PASS
    FILE *fp;
    char buffer[256];


    /*
    *
    *   ADD THE FILE NAME BELOW
    *
    */
    fp = fopen("add.asm", "r");

    if(fp == NULL){
        printf("Error opening file\n");
    } else{
        while(fgets(buffer, 256, fp) != NULL){
            if(buffer[0]=='('){
                int myIt = 1;

                while(buffer[myIt]==')'){
                    //ADD LOGIC AND WAY TO STORE THE STRING THAT IS THE LABEL,
                    //THEN INSERT IT INTO THE SYMBOL FILE
                }
            }

        }
    }
    fclose(fp);
    free(buffer);

    fp = fopen("add.asm", "r");


    //SECOND PASS
    if(fp == NULL){
        printf("Error opening file\n");
    }
    else{
        while(fgets(buffer, 256, fp) != NULL){
            buffer[strcspn(buffer, "\r\n")] = 0;

            if(buffer[0]=='('){
                //FIND A WAY TO STORE THE DATA TO BE TRANSFERRED TO THE FILE
                char *sym = malloc(254*sizeof(char));
                int superLooper = 1;
                while(buffer[superLooper]!=')'){

                    superLooper++;
                }
            }

            if(aOrC(buffer) == true){
                if(buffer[0] == '@'){
                    char* noAt = removeAt(buffer);
                    int convert = stringToInt(noAt);
                    printf("%s\n",intToBinary(convert));
                }
            } else if(aOrC(buffer)== false){
                char* jump = jumpBits(buffer);
                char* dest = destBits(buffer);
                char* comp = compBits(buffer);
                char* finalBits = finalBinaryC(comp, dest, jump);
                printf("%s\n", finalBits);
                fclose(fp);
                free(comp);
                free(jump);
                free(dest);
                free(finalBits);
            }
        }
    }
    fclose(send);
    return 0;
}

int charToInt(char digit){
	return digit - '0';
}

char intToChar(int num){
	return num + '0';
}

char* removeAt(char* string){
    int length = strlen(string);

    char* justNum = malloc(length*sizeof(char));
    int iterations = 0;

    int i;
    for(i=1; i < length;i++){
        justNum[iterations] = string[i];
        iterations++;
    }
    justNum[iterations] = '\0';
    return justNum;
}

int stringToInt(char* string){
	int length = strlen(string)-1;
	int sum = 0;
	int power = 0;

	/*Starting at the end of the array and moving to the beginning
			sum is (sum + (charToInt(string[i]) * pow(10,power++))*/
	int i;
	for(i=length; i>=0; i--){
        sum = sum + (charToInt(string[i]) * ceil(pow(10,power++)));
    }
	return sum;
}

char* intToBinary(int num){
	char *result = malloc(16*sizeof(char));
	//set each element in result to '0'
    int i;
    for(i=0;i < 15;i++){
        result[i]='0';
    }
	//set position to 14
	/*Use division and modulus to put the binary number in the array
    Advice: position-- */
    int leftover;
	int j;
	for(j=14; j>=0; j--){
        leftover = num%2;
        num = num/2;
        result[j] = intToChar(leftover);
	}
	result[15] = '\0';
	return result;
}

bool aOrC(char* string){
    //TRUE IF A, FALSE IF C
    if(string[0] == '@'){
        return true;
    } else if(string[0] == 'D'){
        return false;
    } else if(string[0] == 'M'){
        return false;
    } else if(string[0] == 'A'){
        return false;
    } else if(string[0] == 'J'){
        return false;
    }
}

bool jumpOrDest(char* string){
    //TRUE IF DEST, FALSE IF JUMP
    int i;
    for (i=0; i<strlen(string); i++){
        if(string[i] == '='){
            return true;
        } else if(string[i] == ';'){
            return false;
        }
    }
    return false;
}

char* jumpBits(char* string){
        int i=0;
        int start=0;
        char *savePos = malloc(4*sizeof(char));
        char *jmpBts = malloc(4*sizeof(char));
        jmpBts[3] = '\0';
        savePos[3] = '\0';

        while(i<strlen(string)){
            if(string[i] == ';'){
                savePos[0] = string[i+1];
                savePos[1] = string[i+2];
                savePos[2] = string[i+3];
            }
            i++;
        }

        if(savePos[0] == 'J' && savePos[1] == 'G' && savePos[2] == 'T'){
            jmpBts[0] = '0';
            jmpBts[1] = '0';
            jmpBts[2] = '1';
            free(savePos);
            return jmpBts;
        } else if(savePos[0] == 'J' && savePos[1] == 'E' && savePos[2] == 'Q'){
            jmpBts[0] = '0';
            jmpBts[1] = '1';
            jmpBts[2] = '0';
            free(savePos);
            return jmpBts;
        } else if(savePos[0] == 'J' && savePos[1] == 'G' && savePos[2] == 'E'){
            jmpBts[0] = '0';
            jmpBts[1] = '1';
            jmpBts[2] = '1';
            free(savePos);
            return jmpBts;
        } else if(savePos[0] == 'J' && savePos[1] == 'L' && savePos[2] == 'T'){
            jmpBts[0] = '1';
            jmpBts[1] = '0';
            jmpBts[2] = '0';
            free(savePos);
            return jmpBts;
        } else if(savePos[0] == 'J' && savePos[1] == 'N' && savePos[2] == 'E'){
            jmpBts[0] = '1';
            jmpBts[1] = '0';
            jmpBts[2] = '1';
            free(savePos);
            return jmpBts;
        } else if(savePos[0] == 'J' && savePos[1] == 'L' && savePos[2] == 'E'){
            jmpBts[0] = '1';
            jmpBts[1] = '1';
            jmpBts[2] = '0';
            free(savePos);
            return jmpBts;
        } else if(savePos[0] == 'J' && savePos[1] == 'M' && savePos[2] == 'P'){
            jmpBts[0] = '1';
            jmpBts[1] = '1';
            jmpBts[2] = '1';
            free(savePos);
            return jmpBts;
        } else{
            jmpBts[0] = '0';
            jmpBts[1] = '0';
            jmpBts[2] = '0';
            free(savePos); //FREE THE MEMORY ALLOCATED TO savePos
            return jmpBts;
        }
}

char* destBits(char* string){
    char* destBts=malloc(4*sizeof(char));

    int i;
    int counter = 0;
    //SET ALL BITS TO 0
    for(i=0;i<4;i++){
        destBts[i] = '0';
    }
    destBts[3] = '\0';

    //CHECK AND SET BITS TO TRUE IF INPUT CALLS FOR IT
    while(string[counter] != '='){
        if(string[counter] == 'M'){
            //SET BIT 3 TRUE
            destBts[0] = '1';
        } else if(string[counter] == 'D'){
            //SET BIT 4 TRUE
            destBts[1] = '1';
        } else if(string[counter] == 'A'){
            //SET BIT 5 TRUE
            destBts[2] = '1';
        }
        counter++;
    }
    return destBts;
}

bool compHelper(char* string){
    int i;
    for(i=0;i<strlen(string);i++){
        if(string[i] == 'M'){
            return true;
        }
    }
    return false;
}

char* compBits(char* string){
    bool compStart = false;
    int i;
    int counter = 0;
    int newStringCount = 0;
    char* compBts = malloc(8*sizeof(char));
    char* compStr = malloc(4*sizeof(char));
    compBts[7] = '\0';
    compStr[3] = '\0';

    //Determine what you want to find - @LB
	char toFind = ' ';
	if(jumpOrDest(string)){
		toFind = '=';
	} else{
		toFind = ';';
	}

	//Find it - @LB
	i = 0;
	while(string[i] != toFind){
		i++;
	}

	//Now loop from there to the end of the string - @LB
	for(++i; i < strlen(string); i++){
		compStr[counter++] = string[i];
	}
	compStr[counter] = '\0';

    bool compHelp = compHelper(compStr);
    if(compHelp == false){
        compBts[0] = '0';
        if(strcmp(compStr,"0") == 0){
            compBts[1] = '1';
            compBts[2] = '0';
            compBts[3] = '1';
            compBts[4] = '0';
            compBts[5] = '1';
            compBts[6] = '0';
        } else if(strcmp(compStr,"1") == 0){
            compBts[1] = '1';
            compBts[2] = '1';
            compBts[3] = '1';
            compBts[4] = '1';
            compBts[5] = '1';
            compBts[6] = '1';
        } else if(strcmp(compStr,"-1") == 0){
            compBts[1] = '1';
            compBts[2] = '1';
            compBts[3] = '1';
            compBts[4] = '0';
            compBts[5] = '1';
            compBts[6] = '0';
        } else if(strcmp(compStr,"D") == 0){
            compBts[1] = '0';
            compBts[2] = '0';
            compBts[3] = '1';
            compBts[4] = '1';
            compBts[5] = '0';
            compBts[6] = '0';
        } else if(strcmp(compStr,"A") == 0){
            compBts[1] = '1';
            compBts[2] = '1';
            compBts[3] = '0';
            compBts[4] = '0';
            compBts[5] = '0';
            compBts[6] = '0';
        } else if(strcmp(compStr,"!D") == 0){
            compBts[1] = '0';
            compBts[2] = '0';
            compBts[3] = '1';
            compBts[4] = '1';
            compBts[5] = '0';
            compBts[6] = '1';
        } else if(strcmp(compStr,"!A") == 0){
            compBts[1] = '1';
            compBts[2] = '1';
            compBts[3] = '0';
            compBts[4] = '0';
            compBts[5] = '0';
            compBts[6] = '1';
        } else if(strcmp(compStr,"-D") == 0){
            compBts[1] = '0';
            compBts[2] = '0';
            compBts[3] = '1';
            compBts[4] = '1';
            compBts[5] = '1';
            compBts[6] = '1';
        } else if(strcmp(compStr,"-A") == 0){
            compBts[1] = '1';
            compBts[2] = '1';
            compBts[3] = '0';
            compBts[4] = '0';
            compBts[5] = '1';
            compBts[6] = '1';
        } else if(strcmp(compStr,"D+1") == 0){
            compBts[1] = '0';
            compBts[2] = '1';
            compBts[3] = '1';
            compBts[4] = '1';
            compBts[5] = '1';
            compBts[6] = '1';
        } else if(strcmp(compStr,"A+1") == 0){
            compBts[1] = '1';
            compBts[2] = '1';
            compBts[3] = '0';
            compBts[4] = '1';
            compBts[5] = '1';
            compBts[6] = '1';
        } else if(strcmp(compStr,"D-1") == 0){
            compBts[1] = '0';
            compBts[2] = '0';
            compBts[3] = '1';
            compBts[4] = '1';
            compBts[5] = '1';
            compBts[6] = '0';
        } else if(strcmp(compStr,"A-1") == 0){
            compBts[1] = '1';
            compBts[2] = '1';
            compBts[3] = '0';
            compBts[4] = '0';
            compBts[5] = '1';
            compBts[6] = '0';
        } else if(strcmp(compStr,"D+A") == 0){
            compBts[1] = '0';
            compBts[2] = '0';
            compBts[3] = '0';
            compBts[4] = '0';
            compBts[5] = '1';
            compBts[6] = '0';
        } else if(strcmp(compStr,"D-A") == 0){
            compBts[1] = '0';
            compBts[2] = '1';
            compBts[3] = '0';
            compBts[4] = '0';
            compBts[5] = '1';
            compBts[6] = '1';
        } else if(strcmp(compStr,"A-D") == 0){
            compBts[1] = '0';
            compBts[2] = '0';
            compBts[3] = '0';
            compBts[4] = '1';
            compBts[5] = '1';
            compBts[6] = '1';
        } else if(strcmp(compStr,"D&A") == 0){
            compBts[1] = '0';
            compBts[2] = '0';
            compBts[3] = '0';
            compBts[4] = '0';
            compBts[5] = '0';
            compBts[6] = '0';
        } else if(strcmp(compStr,"D|A") == 0){
            compBts[1] = '0';
            compBts[2] = '1';
            compBts[3] = '0';
            compBts[4] = '1';
            compBts[5] = '0';
            compBts[6] = '1';
        }
    } else if(compHelp == true){
        compBts[0] = '1';
        if(strcmp(compStr,"M") == 0){
            compBts[1] = '1';
            compBts[2] = '1';
            compBts[3] = '0';
            compBts[4] = '0';
            compBts[5] = '0';
            compBts[6] = '0';
        } else if(strcmp(compStr,"!M") == 0){
            compBts[1] = '1';
            compBts[2] = '1';
            compBts[3] = '0';
            compBts[4] = '0';
            compBts[5] = '0';
            compBts[6] = '1';
        } else if(strcmp(compStr,"-M") == 0){
            compBts[1] = '1';
            compBts[2] = '1';
            compBts[3] = '0';
            compBts[4] = '1';
            compBts[5] = '1';
            compBts[6] = '1';
        } else if(strcmp(compStr,"M+1") == 0){
            compBts[1] = '1';
            compBts[2] = '1';
            compBts[3] = '0';
            compBts[4] = '1';
            compBts[5] = '1';
            compBts[6] = '1';
        } else if(strcmp(compStr,"M-1") == 0){
            compBts[1] = '1';
            compBts[2] = '1';
            compBts[3] = '0';
            compBts[4] = '0';
            compBts[5] = '1';
            compBts[6] = '0';
        } else if(strcmp(compStr,"D+M") == 0){
            compBts[1] = '0';
            compBts[2] = '0';
            compBts[3] = '0';
            compBts[4] = '0';
            compBts[5] = '1';
            compBts[6] = '0';
        } else if(strcmp(compStr,"D-M") == 0){
            compBts[1] = '0';
            compBts[2] = '1';
            compBts[3] = '0';
            compBts[4] = '0';
            compBts[5] = '1';
            compBts[6] = '1';
        } else if(strcmp(compStr,"M-D") == 0){
            compBts[1] = '0';
            compBts[2] = '0';
            compBts[3] = '0';
            compBts[4] = '1';
            compBts[5] = '1';
            compBts[6] = '1';
        } else if(strcmp(compStr,"D&M") == 0){
            compBts[1] = '0';
            compBts[2] = '0';
            compBts[3] = '0';
            compBts[4] = '0';
            compBts[5] = '0';
            compBts[6] = '0';
        } else if(strcmp(compStr,"D|M") == 0){
            compBts[1] = '0';
            compBts[2] = '1';
            compBts[3] = '0';
            compBts[4] = '1';
            compBts[5] = '0';
            compBts[6] = '1';
        }
    }
    free(compStr);
    return compBts;
}

char* finalBinaryC(char* comp, char* dest, char* jump){
    char* binarySet =(char*)malloc(17*sizeof(char));
    int i = 0;
    int counter = 0;
    int destCount = 0;
    int jumpCount = 0;
    binarySet[16] = '\0';

    while(i <= 15){
        if(i < 3){
            binarySet[i] = '1';
            i++;
        } else if(i > 2 && i <= 9){
            binarySet[i] = comp[counter];
            i++;
            counter++;
        } else if(i > 9 && i <= 12){
            binarySet[i] = dest[destCount];
            i++;
            destCount++;
        } else if(i > 12 && i <= 15){
            binarySet[i] = jump[jumpCount];
            i++;
            jumpCount++;
        }
    }
    return binarySet;
}




