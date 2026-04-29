#include "splashkit.h"

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    int num_a, num_b;

    num_a = 2;
    num_b = 8;

    write_line("Before the swap:");
    write_line("num_a is " + to_string(num_a));
    write_line("num_b is " + to_string(num_b));

    swap(num_a, num_b);

    write_line("\nAfter the swap:");
    write_line("num_a is " + to_string(num_a));
    write_line("num_b is " + to_string(num_b));

    return 0;
}