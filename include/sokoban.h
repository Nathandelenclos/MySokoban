/*
** EPITECH PROJECT, 2021
** Day09
** File description:
** libmy.a
*/

#include "./list.h"

#ifndef SOKOBAN_H
	#define SOKOBAN_H

typedef struct crate_s {
    int *coord;
    int is_off;
} crate;

typedef struct data_s {
    char **map;
    char **default_map;
    int *p_coord;
    node *holes;
} data;

char *file_to_str(char *filename);
void display(data *d);
char **char_to_array(char *map);
int *get_player_coord(data *d);
void manage_key(data *d);
void regen_map(data *d);
void move_player(data *d, int c);
int *create_coord(int y, int x);
node *get_holes(data *d);
node *get_crates(data *d);
int victory_check(data *d);
int loose_check(data *d);
int check_char(char *map);
int check_screen(char **tab);
#endif
