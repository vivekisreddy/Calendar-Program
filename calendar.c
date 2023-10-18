#include <stdio.h>

// Function prototypes

int get_year_start(int year);           // takes year, returns day that year starts on
void printCalendar(int year, int starting_day);       // takes year and start day, prints 12 months
int printMonth(int year, int month, int starting_day);      // takes year, month and start day of month, prints 1 month, returns start of next month
int printMonthName(int year, int month);       // takes year and month number, prints header for that month, returns number of days in month
int getYear(void);

// Main function 

int main() { 
    int year, starting_day; //year - user input for year number; starting_day - first day of the year
    year = getYear();  //calls function getYear(); which takes in user input
    starting_day = get_year_start(year);  //calls function get_year_start() which gets the first day of the year
    printCalendar(year, starting_day); //prints the calendar with all the months in that year and the correct dates with the days
}

int getYear(void){
   int year; //user input
   printf("Please enter year for this calendar:"); //prompts for user input to enter a year
   scanf("%d", &year); //takes in input

   printf("\n");
   return year;   
}

/********************************************************
*   get_year_start()
*   Determines the day of the week that the specified
*   year starts on. Uses current calendar rules (ignores calendar changes)
*   Input:
*       year: the year being studied
*   Returns:
*       The day of the week the year starts on
*       0: Sunday, 1: Monday, etc
*   Source:
*       https://stackoverflow.com/questions/478694/what-is-the-easiest-algorithm-to-find-the-day-of-week-of-day-zero-of-a-given-year
*********************************************************/

//given function by homework assignment
//function gets the starting date of the year
int get_year_start(int year){
    int year_start =  (((year-1) * 365) + ((year-1) / 4) - ((year-1) / 100) + ((year-1) / 400) + 1) % 7;
    return year_start;
}


/********************************************************
*   printCalendar(in year, int day)
*   Prints 1 year of a calendar
*   
*   Input:
*       year: the year being studied
*       day: the day of the week that the year starts on
*   Returns:
*       Nothing
*   Calls: printMonth
*********************************************************/

void printCalendar(int year, int starting_day){ //prints the calendar of the given year by the user
    int dayMonth = starting_day; //sets dayMonth as the starting day
    printf("\n***   CALENDAR for %d   ***\n\n", year); //prints "calendar of" year
    for (int month = 0; month < 12; month++){ //loops through each month from Jan to Dec
       dayMonth = printMonth(year, month, dayMonth);
    }   
}
 

/********************************************************
*   printMonthName(int year, int month)
*   prints header for the month, returns number of days in month
*   
*   Input:
*       year: the year being studied
*       month: the month to be printed
*   Returns:
*       The number of days in the month
*********************************************************/
int printMonthName(int year, int month){ //function prints the month name and the number of days it has in that month
	switch (month) //switch statement goes through each case from 0 to 11 which is from Jan to Feb which eventually is looped
    {
    case 0: //January 
        printf("January %i\n", year);
        int num_days = 31; 
        return num_days;
        break;
    case 1:  //February
        printf("February %i\n", year);
        //checks whether the year is a leap year or not
        if (((year%4 == 0) && (year%100 != 0)) || (year%400 == 0)){
        num_days = 29; 
        return num_days;
        }
        else { // else it February is just 28 days 
            num_days = 28; 
            return num_days; 
        }
        break; 
    case 2: //March
        printf("March %i\n", year);
        num_days = 31; 
        return num_days; 
        break;
    case 3: //April
        printf("April %i\n", year);
        num_days = 30; 
        return num_days;  
        break;
    case 4: //May
        printf("May %i\n", year);
        num_days = 31; 
        return num_days;  
        break;
    case 5://June
        printf("June %i\n", year);
        num_days = 30; 
        return num_days;  
        break;
    case 6: //July
        printf("July %i\n", year);
        num_days = 31; 
        return num_days;  
        break;
    case 7: //August
        printf("August %i\n", year);
        num_days = 31; 
        return num_days;  
        break;
    case 8: //September 
        printf("September %i\n", year);
        num_days = 30; 
        return num_days;  
        break;
    case 9: //October 
        printf("October %i\n", year);
        num_days = 31; 
        return num_days;  
        break;
    case 10: //November 
        printf("November %i\n", year);
        num_days = 30; 
        return num_days;  
        break;
    case 11: //December 
        printf("December %i\n", year);
        num_days = 31; 
        return num_days;  
        break;
    default: // when none of the cases are true, then default statement is used
        printf("Invalid input of month. Try Again, and enter a new month.");
        break;
    } 
    return 0; 
}

/******************************************************
*   printMonth(int year, int month, int start_day)
*   Prints 1 month of a calendar, returns the start of the next month
*   
*   Input:
*       year: the year being studied
*       month: the month to be printed
*       start_day: the day of the week that the month starts on
*   Returns:
*       The start day of the next month
*   Calls: printMonthName
*********************************************************/
int printMonth(int year, int month, int starting_day){ //prints one month of a calendar and returns the starting date of the next month
    int num_days; 
    int day = 1;   //counter that loops through all the days of the week
    num_days = printMonthName(year, month);  //calls printMonthName() function 
    printf("\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n"); //prints the days of the week from Sun to Sat

    //for loop for checking what day the starting day starts on 
    for(int i = 0; i < starting_day; i++){ 
        printf("     "); // puts gaps before the starting day
    }

    //looping through the first week of the month 
    for(int i = starting_day; i < 7; i++){ 
        printf("%5d", day);  //prints the days of the first week
        day++;  //adds a date
    }
    printf("\n"); // adds a new line after the first week 

    //for loop for printing the rest of the dates 
    for(;day <= num_days;){
        for(int i = 0; i < 7; i++){ 
            if(day <= num_days){ //checks if day it's printed to is less than the num_days
                printf("%5d", day); //print the days of the rest of the week
                day++;  //adds the date
            }
            else {
                printf("\n\n");  //if not, it's going to enter two lines
                return i; 
            }
    
        }
        printf("\n");  //new line for the next month
    }
    return 0;  //checks if the program is executed successfully
}
