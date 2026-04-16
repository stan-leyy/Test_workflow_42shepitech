/*
** EPITECH PROJECT, 2026
** free_env.c
** File description:
** free env
*/

#include "../include/my.h"

void free_env(char **env)
{
    int i = 0;

    while (env[i]) {
        free(env[i]);
        i++;
    }
    free(env);
}
