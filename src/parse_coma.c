/*
** EPITECH PROJECT, 2026
** parse_coma.c
** File description:
** parsing for coma
*/

#include "../include/my.h"

char **parse_coma(char *line)
{
    char **cmd = malloc(sizeof(char *) * 64);
    int i = 0;

    cmd[i] = strtok(line, ";");
    while (cmd[i]) {
        i++;
        cmd[i] = strtok(NULL, ";");
    }
    return cmd;
}
