#include "splashkit.h"

struct target_data
{
    double x;
    double y;
    double radius;
};

int main()
{
    open_window("Reaction Timer", 800, 600);

    target_data target;

    while (!quit_requested())
    {
        process_events();

        clear_screen(COLOR_WHITE);
        refresh_screen();
    }

    return 0;
}