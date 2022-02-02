#include<stdio.h>
#include<string.h>
#define MAX_COMMAND_TOKEN_LENGTH 15
#define REFERENCE_DAY 738177 // Number of days from day 1/1/1 to 1/23/2022
char getCommandWord(char command[], int maxLength);
int getMonth(char token[]);
int getDay(char token[]);
int getYear(char token[]);
int monthDays(int month, int year);
int isValidDate(int month, int day, int year);
int compareTo(int fromMonth, int fromDay, int fromYear, int toMonth, int toDay, int toYear);
void handleCount(void);
int count(int fromMonth, int fromDay, int fromYear, int toMonth, int toDay, int toYear);
void handlePrint(void);
int isLeapYear(int year);
