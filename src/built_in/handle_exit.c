/*
** EPITECH PROJECT, 2026
** handle_exit.c
** File description:
** handle exit
*/

#include "../../include/my.h"

int handle_exit(char **av, char *line)
{
    if (!av || !av[0])
        return 0;
    if (my_strcmp(av[0], "exit") != 0)
        return 0;
    free_all(av, line);
    my_putstr("exit\n");
    exit(0);
}
