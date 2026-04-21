/*
** EPITECH PROJECT, 2025
** fonction
** File description:
** fonction
*/

#include "my.h"

int buildin_cd_error_case(char **av)
{
    if (av[1] != NULL && av[2] != NULL) {
        mini_printf("cd :Too many arguments.\n");
        return -1;
    }
    return 0;
}
