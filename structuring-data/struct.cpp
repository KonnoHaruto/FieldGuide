#include "splashkit.h"
#include "utilities.h"

struct unit_result
{
    string unit_code;
    string unit_name;
    int score;
};

unit_result read_unit_result()
{
    unit_result result;
    result.unit_code = read_string("Enter unit code: ");
    result.unit_name = read_string("Enter unit namue: ");
    result.score = read_integer("Enter the score: ");

    return result;
}

void write_unit_result(const unit_result &result)
{
    write_line(result.unit_code + ", " + result.unit_name + ", " + to_string(result.score));
    if (result.score >= 80)
    {
        write_line("Congratulations!");
    }
}

int main()
{
    unit_result result;

    result = read_unit_result();

    write_unit_result(result);

    return 0;
}