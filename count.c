#include"calendar.h"
/* This file contains count function and 
some relevant functions

/**
 * @brief This function takes in two dates and returns the number of days in between.
 * 		  If the first date is later than the second the answer will be negative.
 * 
 * @param fromMonth 
 * @param fromDay 
 * @param fromYear 
 * @param toMonth 
 * @param toDay 
 * @param toYear 
 * @return int 
 */

int count(int fromMonth, int fromDay, int fromYear, int toMonth, int toDay, int toYear) {

	/* Your code comes here */

	// calculate number of days up to the first date given 
	int f_year = 0;

	for(int i = 1; i < fromYear; i++){
		f_year += (isLeapYear(i)) ? 366 : 365;
	}
	for(int i = 1; i < fromMonth; i++)
		f_year += monthDays(i,fromYear);
	
	f_year += fromDay;


	// calculate number of days up to the first date given 
	int t_year = 0;

	for(int i = 1; i < toYear; i++){
		t_year += (isLeapYear(i)) ? 366 : 365;
	}
	for(int i = 1; i < toMonth; i++)
		t_year += monthDays(i,toYear);
	
	t_year += toDay;

	// printf("\nt_year is: %d\nf_year is %d\n", t_year, f_year);

	// return the difference of the second date minus the first date
	return t_year - f_year;
	}


int getMonth(char token[]) {
	int n;
	if (token[0] < '0' || token[0]> '9' || token[1] < '0' || token[1]> '9')
		return 0;//error in retrieving the month
	n = 10 * (token[0] - '0') + token[1] - '0';
	if (n > 12)
		return 0;//error, month should be from 1 and 12...
	return n;
}

int getDay(char token[]) {
	int n;
	if (token[0] < '0' || token[0]> '9' || token[1] < '0' || token[1]> '9')
		return 0;//error in retrieving the day
	n = 10 * (token[0] - '0') + token[1] - '0';
	if (n > 31)
		return 0;//error, month should be from 1 and 12...
	return n;
}

int getYear(char token[]) {
	int n;
	if (token[0] < '0' || token[0]> '9' ||
		token[1] < '0' || token[1]> '9' ||
		token[2] < '0' || token[2]> '9' ||
		token[3] < '0' || token[3]> '9')
		return 0;//error in retrieving the year
	n = 1000 * (token[0] - '0') + 100 * (token[1] - '0') + 10 * 
	(token[2] - '0') + token[3] - '0';
	return n;
}
void handleCount(void) {
	/* Your code comes here */
	
	int mm, dd, yyyy, MM, DD, YYYY;
	int error = 0;

	char lastCharacter; // needed to get the return value of getCommandWord

	char date1[MAX_COMMAND_TOKEN_LENGTH]; // stores the first date
	lastCharacter = getCommandWord(date1, MAX_COMMAND_TOKEN_LENGTH); // puts the first date into date1
	
	// Extract the first token
	char* token = strtok(date1, "/"); // split the string by '/'
	if( (mm = getMonth(token)) == 0){ // check 
		printf("\nError getting the Month for the first date\n"); 
		error = 1;
		}// get the month and make it into an integer
	token = strtok(NULL, "/"); // split again but this time get rid of month
	if ( (dd = getDay(token)) == 0) {
		printf("\nError getting the Day for the first date\n");
		error = 1;
		} // get the day and make it an integer
	token = strtok(NULL, "/"); // split again but this time get rid of day
	if ( (yyyy = getYear(token)) == 0){
		printf("\nError getting the Year for the first date\n");
		error = 1;
	}  // Make the year into an integer
	
	char date2[MAX_COMMAND_TOKEN_LENGTH]; // stores the string of the second date
	lastCharacter = getCommandWord(date2, MAX_COMMAND_TOKEN_LENGTH); // populates date2 with the value of the second date
	

	// Extract the first token
   char * token2 = strtok(date2, "/"); // split the string by '/'
   if ( (MM = getMonth(token2)) == 0){ // validate the month
	   printf("\nError getting the Month for the second date\n");
	   error = 1;
   }  // get the month and make it into an integer

   token2 = strtok(NULL, "/"); // split again but this time get rid of month
   if( (DD = getDay(token2)) == 0) { // Validate the Day
	   printf("\nError getting the Day for the second date\n"); 
	   error = 1;
	   }// get the day and make it an integer
	   
   token2 = strtok(NULL, "/"); // split again but this time get rid of day
   if ( (YYYY = getYear(token2)) == 0){ // validate the year
	   printf("\nError getting the Year for the second date\n");
	   error = 1;
   } // Make the year into an integer

	// printf("\nmm/dd/yyyy: %d %d %d     MM/DD/YYYY: %d %d %d", mm,dd,yyyy,MM,DD,YYYY);
	if(!error){
	int difference  = count(mm,dd,yyyy,MM,DD,YYYY);
	printf("\nNumber of days in between: %d\n", difference);
	}
	else
	return;
}
int monthDays(int month, int year) {
	switch (month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		if (isLeapYear(year))
			return 29;
		else
			return 28;
	}
	return -1;
}
int isValidDate(int month, int day, int year) {
	return year >= 1 && month >= 1 && month <=12 && day >= 1 && day <= monthDays(month, year);
}
int compareTo(int fromMonth, int fromDay, int fromYear, int toMonth, int toDay, int toYear) {
	//returns negative int if from date < to date
	//return zero if from date == to date
	//returns positive int otherwise
	if (fromYear != toYear)
		return fromYear - toYear;
	if (fromMonth != toMonth)
		return fromMonth - toMonth;
	return fromDay - toDay;
}
int isLeapYear(int year) //97 leap years in every 400 years... 365 days + 97/400
{
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);//2000, 2020, 1600, 2024, 2016,... are leap years...
	//1900, 1800, 1700, 2100, 2002, 2019,... are not leap years...
}