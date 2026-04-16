/*
** EPITECH PROJECT, 2026
** get_home.c
** File description:
** get home in env
*/

#include "../include/my.h"

char *get_var(char **env, char *name)
{
    int i = 0;
    int len = my_strlen(name);

    while (env[i] != NULL) {
        if (my_strncmp(env[i], name, len) == 0
            && env[i][len] == '=')
            return env[i] + len + 1;
        i++;
    }
    return NULL;
}
