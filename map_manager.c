/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** Map manager
*/

#include <stdio.h>
#include <ncurses.h>
#include "include/my.h"
#include "include/sokoban.h"
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

char *file_to_str(char *filename)
{
    int fd1 = open(filename, O_RDONLY);
    struct stat st;
    char *data;
    int size = 0;

    if (fd1 < 0 || errno == 2) {
        my_error("File can't open\n");
        return NULL;
    }
    stat(filename, &st);
    data = malloc(st.st_size + 1);
    size = read(fd1, data, st.st_size);
    if (size <= 0) {
        write(2, "An error occurred in the read.\n", 31);
        return NULL;
    }
    data[size] = '\0';
    if (close(fd1) < 0 || errno == 2) {
        my_error("File can't close\n");
        return NULL;
    }
    return data;
}

char **char_to_array(char *map)
{
    int count = 1;
    char **new_map;
    char *buff = malloc(sizeof(char) * (my_strlen(map) + 1));
    for (int i = 0; i < my_strlen(map); ++i)
        if (map[i] == '\n' || map[i] == '\0')
            count++;
    new_map = malloc(sizeof(char *) * (count + 1));
    for (int i = 0, y = 0, h = 0; i < my_strlen(map) + 1; ++i, ++h) {
        if (map[i] == '\n' || map[i] == '\0') {
            buff[h] = '\0';
            new_map[y] = my_strdup(buff);
            h = -1;
            y++;
        } else {
            buff[h] = map[i];
        }
    }
    new_map[count] = NULL;
    free(buff);
    return new_map;
}

void regen_map(data *d)
{
    for (int i = 0; d->map[i] != NULL; ++i)
        free(d->map[i]);
    for (int i = 0; d->default_map[i] != NULL; ++i)
        d->map[i] = my_strdup(d->default_map[i]);
    d->p_coord = get_player_coord(d);
}

int check_char(char *map)
{
    char str[2];
    str[1]='\0';
    for (int i = 0; map[i] != '\0'; ++i) {
        if (map[i] != '#' && map[i] != ' ' && map[i] != 'P'
        && map[i] != 'X' && map[i] != 'O' && map[i] != '\0' && map[i] != '\n') {
            str[0] = map[i];
            my_error("Invalid map: char '");
            my_error(str);
            my_error("' is banned.\n");
            return 1;
        }
    }
    return 0;
}

void display(data *d)
{
    clear();
    for (int i = 0; d->map[i] != NULL; ++i) {
        printw(d->map[i]);
        if (d->map[i + 1] != NULL)
            printw("\n");
    }
    refresh();
}
