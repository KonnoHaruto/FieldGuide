#include "splashkit.h"


enum light_size
{
    SMALL_LIGHT,
    MEDIUM_LIGHT,
    LARGE_LIGHT,
};

struct light_data
{
    bool is_on;
    int x;
    int y;
    light_size size;
};

int main()
{
    light_data light;

    light.is_on = false;
    light.x = 50;
    light.y = 50;
    light.size = MEDIUM_LIGHT;

    write_line(to_string(light.x));
    return 0;
}