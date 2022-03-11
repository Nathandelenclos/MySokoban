/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** main
*/

#include <ncurses.h>
#include "include/sokoban.h"
#include "include/my.h"
#include "stdlib.h"

int *create_coord(int y, int x)
{
    int *coord = malloc(sizeof(int) * 3);
    coord[0] = y;
    coord[1] = x;
    coord[2] = 0;
    return coord;
}

int get_max_line(char **map)
{
    int count = 0;
    for (int i = 0; map[i] != NULL; ++i)
        if (my_strlen(map[i]) > count)
            count = my_strlen(map[i]);
    return count;
}

int check_screen(char **tab)
{
    int line = get_max_line(tab);
    int column = 0;
    for (int i = 0; tab[i] != NULL; ++i)
        column++;
    if (LINES < (line) || COLS < column) {
        clear();
        char *message = "Please resize your window";
        mvprintw(LINES / 2, (COLS / 2) - my_strlen(message) / 2,
            message);
        refresh();
        return 1;
    }
    return 0;
}

int help(int argc, char **argv)
{
    if (argc > 1 && my_strcmp(argv[1], "-h")) {
        my_printf("USAGE\n"
                  "\t./my_sokoban map\n"
                  "DESCRIPTION\n"
                  "\tmap file representing the warehouse map, "
                  "containing ‘#’ for walls,\n"
                  "\t\t‘P’ for the player, ‘X’ for boxes and "
                  "‘O’ for storage locations.\n");
        return 1;
    }
    return 0;
}

int main(int ac, char **av, char **env)
{
    int ret = 0;
    data *d = malloc(sizeof(data));
    if (help(ac, av))
        return 0;
    initscr();
    keypad(stdscr, TRUE);
    char *map = file_to_str(av[1]);
    if (map == NULL || check_char(map) || check_hole(map))
        return 84;
    d->map = char_to_array(map);
    d->default_map = char_to_array(map);
    d->p_coord = get_player_coord(d);
    d->holes = get_holes(d);
    while (check_screen(d->map));
    display(d);
    ret = manage_key(d);
    endwin();
    return ret;
}
