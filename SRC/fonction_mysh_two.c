/*
** EPITECH PROJECT, 2025
** mysh
** File description:
** fonction
*/

#include "my.h"

char *checker(char *line)
{
    int i = 0;

    while (line[i] == '\t' || line[i] == ' ')
        line++;
    i = my_strlen(line) - 1;
    while (i >= 0 && (line[i] == ' ' || line[i] == '\t'
            || line[i] == '\n'))
        i--;
    line[i + 1] = '\0';
    return line;
}

char **parse_in_fonction_semicolon(char *line)
{
    int i = 0;
    char *token = NULL;
    char **buffer = malloc(sizeof(char *) * 64);

    token = strtok(line, ";");
    for (; token != NULL && i < 63; i++) {
        buffer[i] = checker(token);
        token = strtok(NULL, ";");
    }
    buffer[i] = NULL;
    return buffer;
}
