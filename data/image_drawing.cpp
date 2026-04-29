#include "splashkit.h"

const string IMAGE_NAME = "tree";

int main()
{
    bitmap tree;

    double angle;
    double scale_x, scale_y;

    string user_input;

    open_window("image_drawing", 500, 300);

    write("What degree do you want to apply? Enter: ");
    user_input = read_line();
    angle = to_double(user_input);

    write("How big do you want it to be? Enter: ");
    user_input = read_line();
    scale_x = to_double(user_input);
    scale_y = to_double(user_input);


    tree = load_bitmap(IMAGE_NAME, "tree.png");

    draw_bitmap(tree, 10, 20, option_scale_bmp(scale_x, scale_y));
    draw_bitmap(IMAGE_NAME, 220, 20, option_rotate_bmp(angle));


    refresh_screen();
    delay(5000);
}