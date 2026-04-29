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
        write_line("Please enter a value between " + to_string(low) + " " + to_string(high));
        value = read_integer(prompt);
    }
    return value;
}


int main()
{
    string name;
    int age, value;

    name = read_string("enter your name: ");

    write_line("Hello " + name);

    age = read_integer("What is your age: ");

    write_line("You entered " + to_string(age));

    value = read_integer("Enter a value between 1 and 10: ", 1, 10);
    write_line("You entered " + to_string(value));
}