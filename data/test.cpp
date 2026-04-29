#include "splashkit.h"

int main()
{
    string user_input;
    string title;

    int available_saving;
    int save_amount;

    double target_saving, current_saving;
    double remaining_weeks, needed_weeks;

    write("What are you saving for? Enter title: ");
    title = read_line();
    

    write("How much do you need to save? Enter dollars: ");
    user_input = read_line();
    target_saving = to_integer(user_input);

    write_line();

    write("How long before the purchase? Enter weeks: ");
    user_input = read_line();
    remaining_weeks = to_double(user_input);

    write("How much do you have already? Enter dollars: ");
    user_input = read_line();
    current_saving = to_integer(user_input);

    write("How much can you save each week? Enter dollars: ");
    user_input = read_line();
    available_saving = to_integer(user_input);

    save_amount = target_saving / remaining_weeks;
    needed_weeks = (target_saving - current_saving) / available_saving;

    write_line();

    write_line("For the " + title + ", you need to save " + to_string(save_amount) + " dollars a week");
    write_line("Based on current savings you will need " + to_string(needed_weeks) + " to save $" + to_string(target_saving));
}