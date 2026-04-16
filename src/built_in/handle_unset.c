/*
** EPITECH PROJECT, 2026
** handle_unset.c
** File description:
** handle unsetenv
*/

#include "../../include/my.h"

int handle_unsetenv(char **av, char ***env)
{
    int i = 1;

    if (my_strcmp(av[0], "unsetenv") != 0)
        return 0;
    if (!av[1]) {
        write(2, "unsetenv: Too few arguments.\n", 29);
        return 1;
    }
    while (av[i] != NULL) {
        *env = my_unsetenv(*env, av[i]);
        i++;
    }
    return 1;
}
