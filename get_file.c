/*
** EPITECH PROJECT, 2021
** Get file
** File description:
** get file in str
*/

#include <stdio.h>
#include "include/my.h"
#include "include/sokoban.h"
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

int check_if_file_can_open(int fd)
{
    if (fd < 0 || errno == 2) {
        my_error("File can't open\n");
        return 1;
    }
    return 0;
}

int check_if_error(int size)
{
    if (size <= 0) {
        write(2, "An error occurred in the read.\n", 31);
        return 1;
    }
    return 0;
}

char *file_to_str(char *filename)
{
    int fd1 = open(filename, O_RDONLY);
    struct stat st;
    char *data;
    int size = 0;
    if (check_if_file_can_open(fd1))
        return NULL;
    stat(filename, &st);
    data = malloc(st.st_size + 1);
    size = read(fd1, data, st.st_size);
    if (check_if_error(size))
        return NULL;
    data[size] = '\0';
    if (close(fd1) < 0 || errno == 2) {
        my_error("File can't close\n");
        return NULL;
    }
    return data;
}
