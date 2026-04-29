#include "splashkit.h"
#include "utilities.h"

const int MIN_OPTION = 1;
const int MAX_OPTION = 3;

enum menu_option
{
    ENTER_DETAIL,
    PRINT,
    QUIT,
};

struct book_data
{
    string name;
    string location;
    int pages;
};

void get_book_detail(book_data &book)
{
    write_line();
    book.name = read_string("Enter the name of the book: ");
    book.location = read_string("Enter book location: ");
    book.pages = read_integer("Enter number of pages: ");
    write_line();
}

book_data start_system()
{
    book_data book;

    write_line("Book entry system: ");
    get_book_detail(book);

    return book;
}

void write_menu()
{
    write_line("Menu: ");
    write_line("1 - Enter book details");
    write_line("2 - Print book");
    write_line("3 - Quit");
}

menu_option read_menu()
{
    write_menu();
    int option = read_integer("Option: ", MIN_OPTION, MAX_OPTION);

    return menu_option(option - 1);
}

void print_detail(const book_data &book)
{
    write_line();

    write_line("Book details: ");
    write_line("Title: " + book.name);
    write_line("Location: " + book.location);
    write_line("Pages: " + to_string(book.pages));

    write_line();
}

// void quit_program(menu_option &option)
// {
//     option = QUIT;
// }

int main()
{
    menu_option option;
    book_data book = start_system();

    do{
    option = read_menu();

    switch(option)
    {
        case ENTER_DETAIL: 
            get_book_detail(book);
            break;
        case PRINT: 
            print_detail(book);
            break;
        default:
            break;
    }
    } while (option != QUIT);

    return 0;
}