/*
** EPITECH PROJECT, 2026
** handle_builin.c
** File description:
** cd and exit
*/

#include "../../include/my.h"

int handle_builtin(char **av, char *line, char ***env)
{
    if (handle_exit(av, line))
        return 1;
    if (handle_env(av, *env))
        return 1;
    if (handle_cd(av, *env))
        return 1;
    if (handle_setenv(av, env))
        return 1;
    if (handle_unsetenv(av, env))
        return 1;
    return 0;
}
