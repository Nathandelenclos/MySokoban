/*
** EPITECH PROJECT, 2021
** Moove player
** File description:
** moove player
*/

#include <ncurses.h>
#include "include/sokoban.h"
#include "include/my.h"
#include "stdlib.h"

void player_move_down(data *d)
{
    switch (d->map[d->p_coord[0] + 1][d->p_coord[1]]) {
    case '#':
        break;
    case 'X':
        char t = d->map[d->p_coord[0] + 2][d->p_coord[1]];
        if (t != ' ' && t != 'O')
            break;
        d->map[d->p_coord[0] + 2][d->p_coord[1]] = 'X';
    default:
        d->p_coord[0] += 1;
        break;
    }
}

void player_move_up(data *d)
{
    switch (d->map[d->p_coord[0] - 1][d->p_coord[1]]) {
    case '#':
        break;
    case 'X':
        char t = d->map[d->p_coord[0] - 2][d->p_coord[1]];
        if (t != ' ' && t != 'O')
            break;
        d->map[d->p_coord[0] - 2][d->p_coord[1]] = 'X';
    default:
        d->p_coord[0] -= 1;
        break;
    }
}

void player_move_left(data *d)
{
    switch (d->map[d->p_coord[0]][d->p_coord[1] - 1]) {
    case '#':
        break;
    case 'X':
        char t = d->map[d->p_coord[0]][d->p_coord[1] - 2];
        if (t != ' ' && t != 'O')
            break;
        d->map[d->p_coord[0]][d->p_coord[1] - 2] = 'X';
    default:
        d->p_coord[1] -= 1;
        break;
    }
}

void player_move_right(data *d)
{
    switch (d->map[d->p_coord[0]][d->p_coord[1] + 1]) {
    case '#':
        break;
    case 'X':
        char t = d->map[d->p_coord[0]][d->p_coord[1] + 2];
        if (t != ' ' && t != 'O')
            break;
        d->map[d->p_coord[0]][d->p_coord[1] + 2] = 'X';
    default:
        d->p_coord[1] += 1;
        break;
    }
}

void move_player(data *d, int c)
{
    if (d->default_map[d->p_coord[0]][d->p_coord[1]] == 'O')
        d->map[d->p_coord[0]][d->p_coord[1]] = 'O';
    else
        d->map[d->p_coord[0]][d->p_coord[1]] = ' ';
    switch (c) {
    case KEY_DOWN:
        player_move_down(d);
        break;
    case KEY_UP:
        player_move_up(d);
        break;
    case KEY_LEFT:
        player_move_left(d);
        break;
    case KEY_RIGHT:
        player_move_right(d);
        break;
    }
    d->map[d->p_coord[0]][d->p_coord[1]] = 'P';
}
