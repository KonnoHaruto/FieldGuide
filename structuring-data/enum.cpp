#include "splashkit.h"
#include "utilities.h"

const int NUM_DAYS = 7;

enum day
{
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
};

string to_string(day d)
{
    switch(d)
    {
        case 0: return "Sunday";
        case 1: return "Monday";
        case 2: return "Tuesday";
        case 3: return "Wednesday";
        case 4: return "Thursday";
        case 5: return "Friday";
        case 6: return "Saturday";
        default: return "Invalid day";
    }
}

day read_day(string prompt)
{   
    write_line(prompt);

    for (int i = 0; i < NUM_DAYS; i++)
    {
        write_line(to_string(i+1) + ": " + to_string(day(i)));
    }

    int input = read_integer("Enter a day number (1-7): ", 1, NUM_DAYS );
    return day(input-1);
}

int main()
{
    day today;

    today = read_day("What day is it today? ");

    write_line("Today is " + to_string(today));

    return 0;
}