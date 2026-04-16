/*
** EPITECH PROJECT, 2026
** free_all.c
** File description:
** free all
*/

#include "../include/my.h"

void free_all(char **av, char *line)
{
    free(av);
    free(line);
}
