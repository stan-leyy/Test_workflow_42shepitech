/*
** EPITECH PROJECT, 2026
** copy_env.c
** File description:
** copy env
*/

#include "../include/my.h"

char **copy_env(char **env)
{
    int len = env_len(env);
    char **new_env = malloc(sizeof(char *) * (len + 1));
    int i = 0;

    if (!new_env) {
        return NULL;
    }
    while (env[i]) {
        new_env[i] = my_strdup(env[i]);
        i++;
    }
    new_env[i] = NULL;
    return new_env;
}
