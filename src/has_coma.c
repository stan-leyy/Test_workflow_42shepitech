/*
** EPITECH PROJECT, 2026
** has_coma.c
** File description:
** detect coma
*/

#include "../include/my.h"

int has_coma(char *line)
{
    int i = 0;

    while (line[i]) {
        if (line[i] == ';')
            return 1;
        i++;
    }
    return 0;
}
