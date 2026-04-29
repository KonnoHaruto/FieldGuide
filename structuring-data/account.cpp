#include "splashkit.h"
#include "utilities.h"

struct account_data
{
    string name;
    int balance;
};

enum account_menu_options
{
    RENAME_ACCOUNT,
    DEPOSIT,
    WITHDRAW,
    QUIT,
};

void write_menu()
{
    write_line("Account Program");
    write_line("----------------");
    write_line(" 1: Rename account ");
    write_line(" 2: Deposit ");
    write_line(" 3: Withdraw ");
    write_line(" 4: Quit ");
    write_line("----------------");
}

account_menu_options read_menu()
{
    write_menu();
    int value = read_integer("Enter option: ", 1, 4);

    return account_menu_options(value - 1); 
    /*
        return enum index.
        index starts with 0, so subtract 1 to get accurate enum index.

        if we get actual enum data, need to create another function like to_string().
    */
    

    // switch(value)
    // {
    //     case 1: return RENAME_ACCOUNT;
    //     case 2: return DEPOSIT;
    //     case 3: return WITHDRAW;
    //     default: return QUIT;
    // }
}

string to_string(account_menu_options option)
{
    switch(option)
    {
        case RENAME_ACCOUNT: return "Rename account";
        case DEPOSIT: return "Deposit";
        case WITHDRAW: return "Withdraw";
        case QUIT: return "Quit";
        default: return "Unknown";
    }
}

void rename_account(account_data &account)
{
    write_line("Current name: " + account.name);
    account.name = read_string("Enter new name: ");
}

void write_account(const account_data &account)
{
    write_line(account.name + " has a balance: " + to_string(account.balance));
}

void perform_account_action(account_menu_options option, account_data &account)
{
    write_line("Performing " + to_string(option));

    switch(option)
    {
        case RENAME_ACCOUNT:
            rename_account(account);
    }

    write_account(account);
}

int main()
{
    account_menu_options option;
    account_data account;

    account.balance = 100;

    option = read_menu();
    perform_account_action(option, account);
}