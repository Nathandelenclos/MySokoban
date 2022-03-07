/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** main
*/

#include <ncurses.h>
#include "include/sokoban.h"
#include "stdlib.h"

int *create_coord(int y, int x)
{
    int *coord = malloc(sizeof(int ) * 3);
    coord[0] = y;
    coord[1] = x;
    coord[2] = 0;
    return coord;
}

int main(int ac, char **av, char **env)
{
    data *d = malloc(sizeof(data));
    initscr();
    keypad(stdscr, TRUE);
    char *map = file_to_str(av[1]);
    d->map = char_to_array(map);
    d->default_map = char_to_array(map);
    d->p_coord = get_player_coord(d);
    d->holes = get_holes(d);
    d->crates = get_crates(d);
    display(d);
    manage_key(d);
    endwin();
    return 0;
}
