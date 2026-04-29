#include "splashkit.h"

const int MAX_GUESSES = 7;
const int MAX_NUMER = 100;

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

bool perform_guess(int guess_number, int target)
{
    int guess;

    guess = read_integer("Guess " + to_string(guess_number) + ": ");

    if (target < guess)
    {
        write_line("The number is less than " + to_string(guess));
    }
    else if (target > guess)
    {
        write_line("The number is larger than " + to_string(guess));
    }
    else
    {
        write_line("Well done... the number was " + to_string(guess));
    }

    return guess == target;
}

void play_game()
{
    int my_number, guess_number;
    bool got_it;

    my_number = rnd(1, MAX_NUMER);
    guess_number = 0;

    write_line("I am thinking of a number between 1 and " + to_string(MAX_NUMER));
    do
    {
        guess_number++;
        got_it = perform_guess(guess_number, my_number);
    }
    while (guess_number < MAX_GUESSES && !got_it);

    if(!got_it) write_line("You ran out of guesses... the number was " + to_string(my_number));
}


int main()
{
    string again;
    do
    {
        play_game();
        write_line();
        again = read_string("Play again? [Y or n]: ");
    }
    while (again != "n" && again != "N");
}