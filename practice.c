/*Matt Strand
*CS 271
*practice.c
*
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void instructions();
void fizzBuzz(int);
int smallest(int[], int);
int vowelCount(char*);
void aOrC(char*);
void jumpOrDest(char*);

int main()
{
    bool menu = true;
    int menuChoice;
    int arraySmall[10];

    while(menu){
        instructions();
        scanf("%d",&menuChoice);
        if(menuChoice == 1){
            //FIZZ BUZZ
            int fizzBuzzMax;
            printf("Type the number to FizzBuzz upto:");
            scanf("%d", &fizzBuzzMax);
            fizzBuzz(fizzBuzzMax);
        } else if(menuChoice == 2){
            //SMALLEST VALUE IN ARRAY
            arraySmall[0]=100;
            arraySmall[1]=5;
            arraySmall[2]=1928;
            arraySmall[3]=4378;
            arraySmall[4]=1872;
            arraySmall[5]=277;
            arraySmall[6]=483;
            arraySmall[7]=140;
            arraySmall[8]=1;
            arraySmall[9]=-10;
            printf("%d",smallest(arraySmall,10));
            printf(" is the smallest number\n");
        } else if(menuChoice == 3){
            //NUMBER OF VOWELS
            char countWord[256];
            int vowels;
            printf("Type the word to count vowels:");
            scanf("%s", countWord);
            vowels = vowelCount(countWord);
            printf("%d", vowels);
        } else if(menuChoice == 4){
            //A OR C INSTRUCTION
            char acdc[256];
            printf("Type the instruction:");
            scanf("%s", acdc);
            aOrC(acdc);
        } else if(menuChoice == 5){
            //JUMP OR DESTINATION
            char jumpRope[256];
            printf("Type the string:");
            scanf("%s", jumpRope);
            jumpOrDest(jumpRope);
        } else if(menuChoice == 6){
            printf("Goodbye.");
            menu = false;
        } else{
            printf("Invalid input.");
        }
    }
    return 0;
}

void instructions(){
    printf("\n");
    printf("1.FizzBuzz\n");
    printf("2.Smallest Value in array\n");
    printf("3.Vowel Count\n");
    printf("4.A or C instruction\n");
    printf("5.Jump or Destination\n");
    printf("6.Exit\n");
    printf("Type the corresponding number of the option you wish to perform:");
}

void fizzBuzz(int num){
    int count = 0;
    while(count < num){
        if(count%3 == 0 && count%5 == 0){
            printf("FizzBuzz\n");
            count++;
        } else if(count%3 == 0){
            printf("Fizz\n");
            count++;
        } else if(count%5 == 0){
            printf("Buzz\n");
            count++;
        } else{
            printf("%d\n",count);
            count++;
        }
    }
}

int smallest(int array[], int length){
    int i;
    int smallest;
    for(i=0;i<length;i++){
        if(array[i] < smallest){
            smallest = array[i];
        }
    }
    return smallest;
}

int vowelCount(char* string){
    int vowels = 0;
    int i;
    for (i=0; i<strlen(string); i++){
        if (string[i] == 'a'){
            vowels++;
        } else if(string[i] == 'e'){
            vowels++;
        } else if(string[i] == 'i'){
            vowels++;
        } else if(string[i] == 'o'){
            vowels++;
        } else if(string[i] == 'u'){
            vowels++;
        }
    }
    return vowels;
}

void aOrC(char* string){
    if(string[0] == '@'){
        printf("A instruction!");
    } else if(string[0] == 'D'){
        printf("C instruction!");
    } else if(string[0] == 'M'){
        printf("C instruction!");
    } else if(string[0] == 'A'){
        printf("C instruction!");
    } else if(string[0] == 'J'){
        printf("C instruction!");
    } else{
        printf("Not an A or C instruction");
    }
}

void jumpOrDest(char* string){
    int i;
    for (i=0; i<strlen(string); i++){
        if(string[i] == '='){
            printf("Dest\n");
        } else if(string[i] == ';'){
            printf("Jump\n");
        }
    }
}


