#include"calendar.h"
void print(int MM, int YYYY) {
	/* Your code comes here */
	/*Sun = 0, Mon = 1,..., Sat = 6*/

	int day, sunday = 0, weekday;

	day = get_first_day(MM,YYYY);

	weekday = (day < 0) ? (7 + day) : day;

	printf("\nSun\tMon\tTue\tWed\tThurs\tFri\tSat\n");

	for(int i = 0; i<weekday;i++) // Format the first day of the week 
        printf("\t");

    for(day = 1; day <= monthDays(MM, YYYY); day++) // loops through the month to count the days and tab, if sunday do a newline
    {
		if(++weekday > 6){ // checks if the day is sunday
			weekday = 0; // wrap around
			sunday = 1; // set Sunday = True
		}

        printf("%d %s", day, day == monthDays(MM, YYYY)?"":sunday?"\n":"\t"); // prints the corresponding day of the week
		sunday = 0;
    } 
	printf("\n");
}
void handlePrint(void) {
	/* Your code comes here */
	int MM, YYYY;
	int error = 0;
	char lastCharacter;
	char input[MAX_COMMAND_TOKEN_LENGTH];
	lastCharacter = getCommandWord(input, MAX_COMMAND_TOKEN_LENGTH); // get the date from the buffer
	
	// Extract the first token
   char * token = strtok(input, "/"); // split the string by '/'

   if ( (MM = getMonth(token)) == 0){ // validate the month
	   printf("\nError getting the month\n");
	   error = 1;
   }  // get the month and make it into an integer

   token = strtok(NULL, "/"); // split again but this time get rid of month

   if ( (YYYY = getYear(token)) == 0){ // validate the year
	   printf("\nError getting the year\n");
	   error = 1;
   }  // get the month and make it into an integer

	if(!error)
		print(MM, YYYY);
	else
		return;
}

int get_first_day(int MM, int YYYY){
	int sum = 0;

	for(int i = 1; i < YYYY; i++){
		sum += (isLeapYear(i)) ? 366 : 365;
	}
	for(int i = 1; i < MM; i++)
		sum += monthDays(i,YYYY);
	
	return (sum - REFERENCE_DAY)%7;
}