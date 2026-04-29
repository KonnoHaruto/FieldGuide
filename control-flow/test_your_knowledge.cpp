#include "splashkit.h"

int main()
{
    string line, user_input;

    int count = 0;
    double total_value, average_value;

    bool is_continue;

    write_line("Welcome to the simple stats calculator");
    write_line();

do
{
    write("Enter value: ");
    line = read_line();

    while(! is_integer(line))
    {
        write_line("Please enter a number");
        write("Enter value: ");
        line = read_line();
    }

    total_value = total_value + to_integer(line);
    count++;
    average_value = total_value / count;

    write_line("Count: " + to_string(count));
    write_line("Total: " + to_string(total_value));
    write_line("Average: " + to_string(average_value));

    write_line();

    write("Add another value: [y/n] ");
    user_input = read_line();

    if (user_input == "n" || user_input == "N" || user_input == "No")
    {
        is_continue = false;
    } 
    else if (user_input == "y" || user_input == "Y" || user_input == "Yes")
    {
        is_continue = true;
    }
    else
    {
        is_continue = true;
    }

} while (is_continue);
    write_line("I hope you got the information you are after!");
}