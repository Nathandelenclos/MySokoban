/*
** EPITECH PROJECT, 2021
** Manage Key
** File description:
** manage key
*/

#include <ncurses.h>
#include "include/sokoban.h"
#include "include/my.h"
#include "stdlib.h"

int manage_key(data *d)
{
    while (check_screen(d->map));
    int c = getch();
    move_player(d, c);
    if (c == ' ')
        regen_map(d);
    display(d);
    if (victory_check(d))
        return 0;
    else if (loose_check(d))
        return 1;
    return manage_key(d);
}
