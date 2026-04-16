/*
** EPITECH PROJECT, 2026
** parse.c
** File description:
** PARSING
*/

#include "../include/my.h"

char **parse(char *line)
{
    char **args = malloc(sizeof(char *) * 64);
    int i = 0;

    if (!args) {
        return NULL;
    }
    args[i] = strtok(line, " \n\t");
    while (args[i]) {
        i++;
        args[i] = strtok(NULL, " \n\t");
    }
    return args;
}
