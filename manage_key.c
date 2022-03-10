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

void manage_key(data *d)
{
    while (check_screen(d->map));
    int c = getch();
    move_player(d, c);
    switch (c) {
    case 'q':
        return;
    case ' ':
        regen_map(d);
    }
    display(d);
    if (victory_check(d))
        return;
    if (loose_check(d))
        return;
    manage_key(d);
}