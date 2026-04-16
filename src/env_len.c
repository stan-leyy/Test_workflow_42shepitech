/*
** EPITECH PROJECT, 2026
** env_len.c
** File description:
** env length
*/

#include "../include/my.h"

int env_len(char **env)
{
    int i = 0;

    while (env && env[i])
        i++;
    return i;
}
