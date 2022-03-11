/*
** EPITECH PROJECT, 2021
** Game error
** File description:
** game error handling
*/

#include "include/sokoban.h"
#include "ncurses.h"

int check_hole(char *map)
{
    int holes = 0;
    int crates = 0;
    for (int i = 0; map[i] != '\0'; ++i) {
        if (map[i] == 'O')
            holes += 1;
        if (map[i] == 'X')
            crates += 1;
    }
    if (holes == 0 || holes > crates)
        return 1;
    return 0;
}
