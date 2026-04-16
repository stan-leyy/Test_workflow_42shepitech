/*
** EPITECH PROJECT, 2026
** my_setenv.c
** File description:
** My setenv
*/

#include "../include/my.h"

char *create_line(char *name, char *value)
{
    char *line = NULL;
    int len = 0;

    if (!name)
        return NULL;
    if (!value)
        value = "";
    len = strlen(name) + strlen(value) + 2;
    line = malloc(len);
    if (!line) {
        free(line);
        return NULL;
    }
    my_strcpy(line, name);
    my_strcat(line, "=");
    my_strcat(line, value);
    return line;
}

char **my_setenv(char **env, char *name, char *value)
{
    int len = env_len(env);
    char **new_env = malloc(sizeof(char *) * (len + 2));
    int replaced = 0;
    int i = 0;

    while (env[i]) {
        if (is_same_var(env[i], name)) {
            new_env[i] = create_line(name, value);
            replaced = 1;
        } else
            new_env[i] = my_strdup(env[i]);
        i++;
    }
    if (!replaced) {
        new_env[i] = create_line(name, value);
        i++;
    }
    new_env[i] = NULL;
    free_env(env);
    return new_env;
}
