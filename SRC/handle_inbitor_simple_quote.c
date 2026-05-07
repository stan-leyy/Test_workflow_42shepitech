/*
** EPITECH PROJECT, 2025
** principale_fonction
** File description:
** main
*/

#include "my.h"

int copy_string(char *src, char *dest, int *j)
{
    int i = 1;
    char quote = src[0];

    while (src[i] != '\0' && src[i] != quote) {
        dest[*j] = src[i];
        i++;
        (*j)++;
    }
    if (src[i] == quote)
        i++;
    return i;
}

char *handle_inhibitor(char *line)
{
    int i = 0;
    int j= 0;
    char *buffer = malloc(sizeof(char) * strlen(line) + 1);

    while (line[i] != '\0') {
        if (line[i] == '\'' || line[i] == '\"')
            i += copy_string(&line[i], buffer, &j);
        else {
            buffer[j] = line[i];
            i++;
            j++;
        }
    }
    buffer[j] = '\0';
    return buffer;
}
