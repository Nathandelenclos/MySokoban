/*
** EPITECH PROJECT, 2021
** get
** File description:
** element
*/

#include <ncurses.h>
#include "include/sokoban.h"
#include "include/my.h"
#include "stdlib.h"

int *get_player_coord(data *d)
{
    int *coord = malloc(sizeof(int) * 3);
    coord[2] = 0;
    int y = 0;
    int find = 1;
    for (int i = 0; i < my_strlen(d->map[0]) + 1 && find; ++i) {
        if (d->map[y] == NULL)
            break;
        if (d->map[y][i] == 'P') {
            coord[0] = y;
            coord[1] = i;
        }
        if (d->map[y][i] == '\0') {
            i = -1;
            y++;
        }
    }
    return coord;
}

node *get_holes(data *d)
{
    node *holes = NULL;
    int y = 0;
    for (int i = 0; i < my_strlen(d->map[0]) + 1; ++i) {
        if (d->map[y] == NULL)
            break;
        if (d->map[y][i] == 'O') {
            put_in_list(&holes, create_coord(y, i));
        }
        if (d->map[y][i] == '\0') {
            i = -1;
            y++;
        }
    }
    return holes;
}

crate *create_crate(int y, int x)
{
    crate *c = malloc(sizeof(crate));
    c->coord = create_coord(y, x);
    c->is_off = 0;
    return c;
}

node *get_crates(data *d)
{
    node *crates = NULL;
    int y = 0;
    for (int i = 0; i < my_strlen(d->map[0]) + 1; ++i) {
        if (d->map[y] == NULL)
            break;
        if (d->map[y][i] == 'X') {
            put_in_list(&crates, create_crate(y, i));
        }
        if (d->map[y][i] == '\0') {
            i = -1;
            y++;
        }
    }
    return crates;
}