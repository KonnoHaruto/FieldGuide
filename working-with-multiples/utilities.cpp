#include "utilities.h"
#include "splashkit.h"

string read_string(string prompt)
{
    write(prompt);
    return read_line();
}

int read_integer(string prompt)
{
    string line;
    line = read_string(prompt);

    while(! is_integer(line) )
    {
        write_line("PLease enter a whole number.");
        line = read_string(prompt);
    }

    return to_integer(line);
}

int read_integer(string prompt, int low, int high)
{
    int value = read_integer(prompt);
    while (value < low || value > high)
    {
        write_line("Please enter a value between " + to_string(low) + " and " + to_string(high));
        value = read_integer(prompt);
    }
    return value;
}

double read_double(string prompt)
{
    string line = read_string(prompt);

    while (! is_double(line) )
    {
        write_line("Please enter a double number.");
        line = read_string(prompt);
    }

    return to_double(line);
}

bool read_bool(string prompt)
{
    string line = read_string(prompt);
    while(line != "y" && line != "n")
    {
        write_line("Please enter y or n");
        line = read_string(prompt);
    }
    return line == "y";
}
