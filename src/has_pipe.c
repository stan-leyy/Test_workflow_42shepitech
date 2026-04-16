/*
** EPITECH PROJECT, 2026
** has_pipe.c
** File description:
** detect pipe
*/

#include "../include/my.h"

int has_pipe(char *line)
{
    int i = 0;

    while (line[i]) {
        if (line[i] == '|')
            return 1;
        i++;
    }
    return 0;
}
