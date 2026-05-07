/*
** EPITECH PROJECT, 2025
** principale_fonction
** File description:
** main
*/

#include "my.h"

char *get_before_or(char *line)
{
    int i = 0;
    char *result = NULL;

    while (line[i] != '\0') {
        if (line[i] == '|' && line[i + 1] == '|')
            break;
        i++;
    }
    result = malloc(sizeof(char) * (i + 1));
    strncpy(result, line, i);
    result[i] = '\0';
    return checker(result);
}

char *get_after_or(char *line)
{
    int i = 0;

    while (line[i] != '\0') {
        if (line[i] == '|' && line[i + 1] == '|')
            return my_strdup(line + i + 2);
        i++;
    }
    return NULL;
}
