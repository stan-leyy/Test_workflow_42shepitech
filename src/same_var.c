/*
** EPITECH PROJECT, 2026
** same_var.c
** File description:
** is same var
*/

#include "../include/my.h"

int is_same_var(char *env_line, char *name)
{
    int i = 0;

    while (name[i] && env_line[i] && name[i] == env_line[i])
        i++;
    return (name[i] == '\0' && env_line[i] == '=');
}
