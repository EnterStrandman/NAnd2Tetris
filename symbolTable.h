#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE

struct Symbol{
	char* symbol;
	int address;
	struct Symbol* next;
};

struct SymbolTable{
	struct Symbol* head;
};


void printtable(struct SymbolTable* table){
	struct Symbol* temp = NULL;
	temp = table->head;
	while( temp != NULL ){
		printf("%s\n", temp->symbol);
		printf("%d\n", temp->address);
		temp = temp -> next;
	}
}

void insertAtEnd(struct SymbolTable* table, char* symbol, int item){
    if(table->head == NULL){
        table->head = malloc(sizeof(struct Symbol));
        int length = strlen(symbol);
        table->head->symbol = malloc(sizeof(char) * length);
        strcpy(table->head->symbol, symbol);//inserts the value of symbol to proper size array
        table->head->address = item;
        table->head->next = NULL;
    } else {
        struct Symbol* temp = NULL;
        temp = table->head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = malloc(sizeof(struct Symbol));
        int length = strlen(symbol);
        temp->next->symbol = malloc(sizeof(char) * length);
        strcpy(temp->next->symbol, symbol);
        temp->next->address = item;
        temp->next->next = NULL;

    }
}

void destroytable(struct SymbolTable* table){
	struct Symbol* temp = table->head;
	while(temp != NULL){
		table->head = temp->next;
		free(temp->symbol);
		free(temp);
		temp = table->head;
	}
}

int getAddress(struct SymbolTable* table,char* symbol){
	struct Symbol* temp = NULL;
	temp = table->head;
	while( temp != NULL ){
        if(strcmp(symbol,temp->symbol) == 0){
            return temp->address;
        }
		temp = temp -> next;
	}
	return -1;
}
#endif
