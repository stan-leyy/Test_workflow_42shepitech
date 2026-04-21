/*
** EPITECH PROJECT, 2025
** principale_fonction
** File description:
** main
*/

#include "my.h"

int such_inhibitor_slach(char *line)
{
    int i = 0;

    while(line[i] != '\0') {
        if (line[i] == '/')
            return 1;
        i++;
    }
    return 0;
}
