#include "splashkit.h"
#include "utilities.h"

enum menu_option
{
    ENTER_DETAIL = 1,
    PRINT = 2,
    QUIT = 3,
};

struct book_data
{
    string name;
    string location;
    int pages;
};

// This will ask user the book details.
void get_book_detail(book_data &book)
{
    write_line();
    book.name = read_string("Enter the name of the book: ");
    book.location = read_string("Enter book location: ");
    book.pages = read_integer("Enter number of pages: ");
    write_line();
}

// Get the book details and return it.
book_data start_system()
{
    book_data book;

    write_line("Book entry system: ");
    get_book_detail(book);

    return book;
}

// Print the menu.
void write_menu()
{
    write_line("Menu: ");
    write_line("1 - Enter book details");
    write_line("2 - Print book");
    write_line("3 - Quit");
}

// This will ask options user wants.
menu_option read_menu()
{
    write_menu();
    menu_option option = menu_option(read_integer("Please choose an option: ", 1, 3));

    return menu_option(option);
}

// Print the book details.
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