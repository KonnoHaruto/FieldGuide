#include "splashkit.h"

int main()
{
        download_sound_effect("Hello World", "https://programmers.guide/resources/code-examples/part-0/hello-world-snippet-saddle-club.ogg", 443);
    download_font("main", "https://programmers.guide/resources/code-examples/part-0/Roboto-Italic.ttf", 443);
    open_window("Tree on the hill by Haruto", 800, 600);
    
    play_sound_effect("Hello World");

    clear_screen(COLOR_WHITE);

    fill_ellipse(COLOR_LIGHT_GREEN, 0, 500, 800, 400);
    fill_rectangle(COLOR_BROWN, 300, 300, 200, 400);
    fill_circle(COLOR_DARK_GREEN, 390, 250, 175);

    draw_text("Tree on the hill", COLOR_BLACK, "main", 40, 280, 20);

    refresh_screen();
    delay(100000);
}