/*
Matt Strand
CS 271
Template provided by Mr. Bowe
Citations:
*/

#include <stdio.h>
#include <string.h> //for strlen
#include <math.h>   //for pow
#include <stdlib.h> //for malloc


int charToInt(char);
int stringToInt(char*);
char intToChar(int);
char* intToBinary(int);

int main(){
	char* theString = "32766\0"; //should give you 111111111111110, you should try other numbers.
	printf("%s\n",theString);
	int num = stringToInt(theString);
	printf("%d\n",num);
	printf("%s\n", intToBinary(num));
	return 0;
}

int charToInt(char digit){
	return digit - '0';
}

char intToChar(int num){
	return num + '0';
}

int stringToInt(char* string){

	int length = strlen(string)-1;
	int sum = 0;
	int power = 0;

	/*Starting at the end of the array and moving to the beginning
			sum is (sum + (charToInt(string[i]) * pow(10,power++))*/
	int i;
	printf("%d\n", length);
	for(i=length; i>=0; i--){

        sum = sum + (charToInt(string[i]) * ceil(pow(10,power++)));
        printf("Sum equals ");
        printf("%d", sum);
        printf(" during iteration ");
        printf("%d\n",i);
    }
	return sum;
}



char* intToBinary(int num){
	char *result = (char*)malloc(16*sizeof(char));
	//set each element in result to '0'
    int i;
    for(i=0;i<strlen(result);i++){
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
