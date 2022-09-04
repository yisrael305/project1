#pragma once                                                             // Israel Weiss 
#ifndef projectGroceryHead
#define projectGroceryHead

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CHUNK 10

typedef struct {
	unsigned int day : 5;   
	unsigned int month : 4;
	unsigned int year : 12;
}date;


struct client {
	char* firstName;
	char* lastName;
	char* ID;
	char* phone;
	float debt;
	date dateOfDebt;
	int errors[7];            // Array of 1 and 0 that symbolizes the validation of each field in the client in the order. the last index symbolizes error id and name not matching. 
	struct client* next;
};

struct list {
	struct client* head;
	struct client* tail;
	float maxDebt;
	struct list* next;
};

struct client* createClient();
char* removeSpacesFromStr(char** string);
struct client* checkForExistingID(struct list* listOfClient, char* ID);
void addToHead(struct list* list, struct client* newClient);
void addToTail(struct list* list, struct client* newClient);
char* readInput(FILE* fp);
struct list* createList();
int validName(char** name);
int validID(char** ID);
int validPhone(char** phone);
int validNumber(char** number);
int validDate(char** date);
void openFileError();
int checkForMatchName(struct client* ExistingClient, struct client* newClient);
void realocatClient(struct list* listOfDebts, struct client* existingClient);
int checkIfItsNew(date* excistingDate, date* newDate);
void addToExistingClient(struct list* listOfDebts, struct client* existingClient, struct client* newClient);
void addToSortedList(struct list* listOfDebts, struct client* newClient);
void printClient(struct client* Client);
void erorrList(int type);
void printList(struct list* listOfclient);
void printInstructions();
int matchNameAndID(char* ID, char* firstName, char* lastName, struct list* listOfDebts);
void addToFile(char* input, FILE* fp, struct list* clientsList);
void selectQuery(struct list* clientsList, char* param);
int getQuery(FILE* fp, struct list* clientsList);
void readFile(FILE* fp, struct list* listOfDebts);
FILE* openFile(char* nameOfFile);
void printToFile(FILE* fp, struct client* record);
void freeClient(struct client* Client);
void freeList(struct list* List);
#endif