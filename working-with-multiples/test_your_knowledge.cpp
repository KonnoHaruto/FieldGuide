#include "splashkit.h"
#include "splashkit-arrays.h"
#include "utilities.h"

const int NO_CHOICE = -1;

enum menu_option
{
    ADD_SONG = 1,
    UPDATE_SONG = 2,
    PLAY_SONG = 3,
    PAUSE_SONG = 4,
    PRINT_STATUS = 5,
    QUIT = 6,
};

enum update_song_option
{
    UPDATE_NAME = 1,
    UPDATE_LOVED = 2,
    RESET_TIMES_PLAYED = 3,
    DELETE = 4,
    UPDATE_QUIT = 5,
};

struct song_data
{
    string name;
    string song_id;
    string path;
    bool is_loved;
    int play_times;
};

struct music_player
{
    dynamic_array<song_data> songs;
    int id;
};

void print_menu()
{
    write_line("Main Menu");
    write_line("1. Add a new song");
    write_line("2. Update a song");
    write_line("3. Play a song");
    write_line("4. Pause / Resume a song");
    write_line("5. Print status");
    write_line("6. Quit\n");
}

void print_update_menu()
{
    write_line("Update Menu");
    write_line("1. Update name");
    write_line("2. Update loved");
    write_line("3. Reset times played");
    write_line("4. Delete song");
    write_line("5. Quit update");
}

void add_song(music_player &player)
{
    song_data song;
    write_line("Add a song!");

    song.name = read_string("Enter song name: ");
    song.song_id = "song-" + to_string(player.id);
    song.path = read_string("Enter path of the song: ");
    song.is_loved = read_bool("Love this song? [y/n]: ");
    song.play_times = 0;

    add(player.songs, song);
    player.id++;
    load_music(song.song_id, song.path);
}

void list_songs(const music_player &player)
{
    for (int i = 0; i < length(player.songs); i++)
    {
        write(to_string(i + 1) + ". ");
        write_line(player.songs[i].name);
    }
}

int find_song(const music_player &player)
{
    if(length(player.songs) == 0)
    {
        write_line("No songs added yet.");
        return NO_CHOICE;
    }

    string searching_text = read_string("Enter text to search for: ");
    bool found_song = false;

    for (int i = 0; i < length(player.songs); i++)
    {
        if (contains(player.songs[i].name, searching_text))
        {
            write_line(to_string(i + 1) + ". " + player.songs[i].name);
            found_song = true;
        }
    }
    
    if (!found_song)
    {
        write_line("No matching songs.");
        return NO_CHOICE;
    }

    int index = read_integer("Select a song: ", 1, length(player.songs)) - 1;

    if(!contains(player.songs[index].name, searching_text))
    {
        write_line("Invalid selection.");
        return NO_CHOICE;
    }

    return index;
}

void print_song_details(const song_data &song)
{
    string is_loved;
    if (song.is_loved == true)
    {
        is_loved = "True";
    }
    else
    {
        is_loved = "False";
    }

    write_line("name: " + song.name);
    write_line("song id: " + song.song_id);
    write_line("song path: " + song.path);
    write_line("is loved: " + is_loved);
    write_line("time played: " + to_string(song.play_times));
    write_line();
}

void update_song(music_player &player)
{
    int index = find_song(player);
    if (index == NO_CHOICE) return;

    update_song_option option;

    do
    {
        write_line("Current details:");
        print_song_details(player.songs[index]);
        write_line();
        print_update_menu();

        option = update_song_option(read_integer("Enter an option: ", 1, 5));

        switch (option)
        {
            case UPDATE_NAME:
                player.songs[index].name = read_string("Enter new name: ");
                break;
            case UPDATE_LOVED:
                player.songs[index].is_loved = !player.songs[index].is_loved;
                break;
            case RESET_TIMES_PLAYED:
                player.songs[index].play_times = 0;
                break;
            case DELETE:
                remove(player.songs, index);
                return;
            case UPDATE_QUIT:
                break;
        }
        write_line();
    } while (option != UPDATE_QUIT);
}

void play_song(music_player &player)
{
    int index = find_song(player);
    if(index == NO_CHOICE) return;

    play_music(player.songs[index].song_id);
    player.songs[index].play_times++;
}

void pause_or_resume_song()
{
    if(music_playing())
    {
        pause_music();
    }
    else 
    {
        resume_music();
    }
}

int get_played_songs_num(const music_player &player)
{
    if(length(player.songs) == 0) return NO_CHOICE;
    int result = 0;

    for (int i = 0; i < length(player.songs); i++)
    {
        if (player.songs[i].play_times > 0)
        {
            result++;
        }
    }
    return result;
}

int get_loved_songs_num(const music_player &player)
{
    if (length(player.songs) == 0) return NO_CHOICE;

    int result = 0;
    for (int i = 0; i < length(player.songs); i++)
    {
        if(player.songs[i].is_loved)
        {
            result++;
        }
    }

    return result;
}

void print_status(const music_player &player)
{
    int num_of_songs = length(player.songs);
    int num_of_played_songs = get_played_songs_num(player);
    int num_of_loved_songs = get_loved_songs_num(player);

    write_line("== Player Report ==");
    write_line("Total number of songs: " + to_string(num_of_songs));
    write_line("Total number of played songs: " + to_string(num_of_played_songs));
    write_line("Total number of loved songs: " + to_string(num_of_loved_songs));
}

int main()
{
    music_player player = {};
    player.id = 0;

    write_line("Welcome to Music Player!\n");

    menu_option option;
    do 
    {
        print_menu();
        option = menu_option(read_integer("Please choose an option: ", 1, 6));

        switch(option)
        {
            case ADD_SONG:
                add_song(player);
                break;
            case UPDATE_SONG:
                update_song(player);
                break;
            case PLAY_SONG:
                play_song(player);
                break;
            case PAUSE_SONG:
                pause_or_resume_song();
                break;
            case PRINT_STATUS:
                print_status(player);
                break;
            case QUIT:
                break;
        }

    } while (option != QUIT);
}