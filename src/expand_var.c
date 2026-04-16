/*
** EPITECH PROJECT, 2026
** expand_vars.c
** File description:
** expands env values
*/

#include "../include/my.h"

void dup_var(char **av, char *value, int i)
{
    if (value)
        av[i] = my_strdup(value);
    else
        av[i] = my_strdup("");
}

void expand_vars(char **av, char **env)
{
    int i = 0;
    char *value = NULL;

    while (av[i] != NULL) {
        if (av[i][0] == '$') {
            value = get_var(env, av[i] + 1);
            free(av[i]);
            dup_var(av, value, i);
        }
        i++;
    }
}
