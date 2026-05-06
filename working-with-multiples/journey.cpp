#include "splashkit.h"
#include "splashkit-arrays.h"

#include "utilities.h"

void write_list(const dynamic_array<string> &list)
{
    for (int i = 0; i < length(list); i++)
    {
        write_line(to_string(i +1) + ": " + list[i]);
    }
}

dynamic_array<string> read_list(string prompt)
{
    dynamic_array<string> result;
    write_line(prompt);

    while(read_bool("Add entry [y/n]: "))
    {
        add(result, read_string("Enter value: "));
    }

    return result;
}


int find_index(const dynamic_array<string> &list, string search_for)
{
    for (int i = 0; i < length(list); i++)
    {
        if (list[i] == search_for)
        {
            return i;
        }
    }
    return -1;
}

bool contains(const dynamic_array<string> &list, string search_for)
{
    return find_index(list, search_for) != -1;
}

string shortest(const dynamic_array<string> &list)
{
    string result = list[0];
    for (int i = 1; i < length(list); i++)
    {

        if (length_of(list[i]) < length_of(result))
        {
            result = list[i];
        }
    }

    return result;
}

int main()
{
    // fixed_array<int, 10> numbers;
    // dynamic_array<int> nums;
    // fixed_array<string, 5> todos;


    dynamic_array<string> names;

    // add(names, "Andrew");
    // add(names, "Charlotte");
    // add(names, "Jai");
    // add(names, "Hui");
    // add(names, "Ganesh");

    names = read_list("Enter the item you want to add: ");
    write_list(names);

    if(contains(names, "米津玄師"))
    {
        write_line("米津玄師 is in the list!");
    }

    write_line("The shortest item: " + shortest(names));

    // remove(names, 0);
    // write_list(names);

    // insert(names, 0, "コムドット裕次郎");
    // write_list(names);
}