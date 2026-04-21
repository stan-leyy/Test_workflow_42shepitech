/*
** EPITECH PROJECT, 2025
** fonction
** File description:
** fonction
*/

#include "my.h"

int such_or(char *line)
{
    int i = 0;

    while (line[i] != '\0') {
        if (line[i] == '|' && line[i + 1] == '|')
            return 1;
        i++;
    }
    return 0;
}

char **parse_or(char *line)
{
    int i = 0;
    char **buffer = malloc(sizeof(char *) * 64);
    char *token = NULL;
    char *copy = my_strdup(line);

    token = strtok(copy, "|");
    while (token != NULL && i < 63) {
         while (*token == '|' || *token == ' ')
            token++;
        if (*token == '\0')
            buffer[i] = NULL;
        else
            buffer[i] = checker(token);
        token = strtok(NULL, "|");
        if (token != NULL && token[0] == '\0')
            token = strtok(NULL, "|");
        i++;
    }
    buffer[i] = NULL;
    return buffer;
}