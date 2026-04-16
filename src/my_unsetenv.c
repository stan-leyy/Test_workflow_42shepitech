/*
** EPITECH PROJECT, 2026
** my_unsetenv.c
** File description:
** my_unsetenv
*/

#include "../include/my.h"

char **my_unsetenv(char **env, char *name)
{
    int len = env_len(env);
    char **new_env = malloc(sizeof(char *) * (len + 1));
    int i = 0;
    int j = 0;

    if (!new_env) {
        free(new_env);
        return NULL;
    }
    while (env[i]) {
        if (!is_same_var(env[i], name)) {
            new_env[j] = my_strdup(env[i]);
            j++;
        }
        i++;
    }
    new_env[j] = NULL;
    free_env(env);
    return new_env;
}
