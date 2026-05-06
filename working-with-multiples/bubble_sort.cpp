#include "splashkit.h"
#include "splashkit-arrays.h"

const int MAX_SIZE = 5;

void write_list(const fixed_array<int, MAX_SIZE> &list)
{
    for (int i = 0; i < length(list); i++)
    {
        write_line( to_string(i + 1) + ": " + to_string(list[i]));
    }
}

void swap(int &v1, int &v2)
{
    int num = v1;

    v1 = v2;
    v2 = num;
}

void sort(fixed_array<int, MAX_SIZE> &list)
{
    for (int j = 0; j < length(list) - 1; j++)
    {
        for (int i = 0; i < length(list) - 1 - j; i++)
        {
            if (list[i] > list[i + 1])
            {
                swap(list[i], list[i + 1]);
            }
        }
    }  
}

int main()
{
    fixed_array<int, MAX_SIZE> numbers;

    
    numbers[0] = 10;
    numbers[1] = 4;
    numbers[2] = 5;
    numbers[3] = 3;
    numbers[4] = 7;

    sort(numbers);

    write_list(numbers);
}