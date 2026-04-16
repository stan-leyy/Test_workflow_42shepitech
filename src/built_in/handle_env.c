/*
** EPITECH PROJECT, 2026
** handle_env.c
** File description:
** handle env
*/

#include "../../include/my.h"

int handle_env(char **av, char **env)
{
    int i = 0;

    if (my_strcmp((av[0]), "env") == 0 && av[1] != NULL) {
        my_printf("env: '%s': No such file or directory\n", av[1]);
        return 84;
    }
    if (my_strcmp((av[0]), "env") != 0)
        return 0;
    while (env && env[i]) {
        my_putstr(env[i]);
        my_putchar('\n');
        i++;
    }
    return 1;
}
