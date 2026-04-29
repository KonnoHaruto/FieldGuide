#include "splashkit.h"
#include "utilities.h"

const int GOAL_POINT = 6;
const int BEHIND_POINT = 1;
const int MAX_WIDTH = 26;

const int SYMBOL_SPACE = 2;
const int SYMBOL_AND_EXTRA_SPACE = 3;


void draw_heading_line(int width)
{
    int remaining_line;
    write("+");
    remaining_line = width - SYMBOL_SPACE;
    for (int i = 0; i < remaining_line; i++)
    {
        write("-");
    }
    write("+\n");
}

void draw_title(string title, int width)
{
    int space;
    space = width - (length_of(title) + SYMBOL_AND_EXTRA_SPACE);
    draw_heading_line(width);
    write("|");
    write(" " + title);
    for (int i = 0; i < space; i ++)
    {
        write(" ");
    }
    write("|\n");
    draw_heading_line(MAX_WIDTH);
}


int calculate_score(int goals, int behinds)
{
    int goal_points = goals * GOAL_POINT;
    int behind_points = behinds * BEHIND_POINT;

    return goal_points + behind_points;
}

int update_goals(int &goals, int behinds)
{
    write_line();
    write_line("Current goals: " + to_string(goals));
    goals = read_integer("Enter new goals: ");
    return calculate_score(goals, behinds);
}

int update_behinds(int goals, int &behinds)
{
    write_line();
    write_line("Current behinds: " + to_string(behinds));
    behinds = read_integer("Enter new behinds: ");
    return calculate_score(goals, behinds);
}

void print_score(int score)
{
    write_line("Current Score: " + to_string(score));
}

void print_details(string name, int goals, int behinds, int score)
{
    write_line();
    write_line(name + ":");
    write_line(to_string(goals) + " Goals");
    write_line(to_string(behinds) + " Behinds");
    write_line(to_string(score));
    write_line();
}

bool check_continued()
{
    string is_continued = read_bool("Are you sure you want to quit? [Y/n]: ");
    if (is_continued == "y")
    {
        return false;
    }
    else return true;
}

bool show_menu(string name, int &goals, int &behinds, int &score)
{
    int option;

    draw_title("Main Menu", MAX_WIDTH);
    write_line("1: Update goals");
    write_line("2: Update behinds");
    write_line("3: Print details");
    write_line("4: Quit");
    draw_heading_line(MAX_WIDTH);

    option = read_integer("Enter option: ", 1, 4);
    switch (option)
    {
    case 1:
        score = update_goals(goals, behinds);
        print_score(score);
        break;
    case 2:
        score = update_behinds(goals, behinds);
        print_score(score);
        break;
    case 3:
        print_details(name, goals, behinds, score);
        break;
    case 4:
        return false;
        break;
    default:
        break;
    }
    return true;
}


void start_calculator()
{
    string team_name;
    int goal, behind, score;

    bool is_continued;

    draw_title("Score Calculator", MAX_WIDTH);
    write_line();
    write_line("Welcome to the AFL score calculator!");
    write_line();
    team_name = read_string("Enter team name: ");
    goal = read_integer("Enter goals: ");
    behind = read_integer("Enter behinds: ");
    score = calculate_score(goal, behind);

    write_line();
    write_line("Current Score: " + to_string(score));
    write_line();

    do
    {
        is_continued = show_menu(team_name, goal, behind, score);
        write_line();

        if(!is_continued)
        {
            is_continued = check_continued();
        }
    }
    while(is_continued);
    write_line();
    write("Bye!");
}



int main()
{
    start_calculator();
}