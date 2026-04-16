/*
** EPITECH PROJECT, 2026
** mandatory_and.c
** File description:
** handle && operator
*/

#include "../include/my.h"

int dear_and(char *line)
{
    int i = 0;

    while (line[i] != '\0') {
        if (line[i] == '&' && line[i + 1] == '&')
            return 1;
        i++;
    }
    return 0;
}

static char *trim_token(char *token)
{
    while (*token == '&' || *token == ' ' || *token == '\t')
        token++;
    return token;
}

char **parse_and(char *line)
{
    int i = 0;
    char **buffer = malloc(sizeof(char *) * 64);
    char *token = NULL;
    char *copy = my_strdup(line);

    if (!buffer || !copy)
        return NULL;
    token = strtok(copy, "&");
    while (token != NULL && i < 63) {
        token = trim_token(token);
        if (token[0] != '\0') {
            buffer[i] = token;
            i++;
        }
        token = strtok(NULL, "&");
    }
    buffer[i] = NULL;
    return buffer;
}