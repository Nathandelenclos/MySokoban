/*
** EPITECH PROJECT, 2021
** Victory & Loose
** File description:
** check Victory & Loose
*/

#include <ncurses.h>
#include "include/sokoban.h"
#include "include/my.h"
#include "stdlib.h"

int victory_check(data *d)
{
    node *tmp = d->holes;
    while (tmp != NULL) {
        int *coord = (int *) tmp->data;
        if (d->map[coord[0]][coord[1]] != 'X')
            return 0;
        tmp = tmp->next;
    }
    return 1;
}

int box_is_loose(data *d, crate *c)
{
    if (d->map[c->coord[0] + 1][c->coord[1]] == '#' &&
        d->map[c->coord[0]][c->coord[1] + 1] == '#')
        c->is_off = 1;
    if (d->map[c->coord[0] - 1][c->coord[1]] == '#' &&
        d->map[c->coord[0]][c->coord[1] - 1] == '#')
        c->is_off = 1;
    if (d->map[c->coord[0] + 1][c->coord[1]] == '#' &&
        d->map[c->coord[0]][c->coord[1] - 1] == '#')
        c->is_off = 1;
    if (d->map[c->coord[0] - 1][c->coord[1]] == '#' &&
        d->map[c->coord[0]][c->coord[1] + 1] == '#')
        c->is_off = 1;
    return 0;
}

void free_crates(node *tmp)
{
    while (tmp != NULL) {
        free(tmp->data);
        tmp = tmp->next;
    }
    free(tmp);
}

int loose_check(data *d)
{
    node *tmp = get_crates(d);
    while (tmp != NULL) {
        crate *c = (crate *) tmp->data;
        box_is_loose(d, c);
        if (c->is_off == 0)
            return 0;
        tmp = tmp->next;
    }
    free_crates(tmp);
    return 1;
}
