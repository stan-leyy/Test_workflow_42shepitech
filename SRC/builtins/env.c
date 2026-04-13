/*
** EPITECH PROJECT, 2025
** fonction
** File description:
** fonction
*/

#include "../my.h"

void display_environnement(char **env)
{
    int i = 0;

    while (env[i] != NULL) {
        mini_printf("%s\n", env[i]);
        i++;
    }
}
