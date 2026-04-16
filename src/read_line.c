/*
** EPITECH PROJECT, 2026
** read_line.c
** File description:
** READ LINE
*/

#include "../include/my.h"

char *read_line(void)
{
    char *line = NULL;
    size_t len = 0;

    if (getline(&line, &len, stdin) == -1) {
        free(line);
        return NULL;
    }
    return line;
}
