/*
** EPITECH PROJECT, 2025
** strcmp
** File description:
** STRCMP
*/

#include "../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1) {
        if (*s1 != *s2)
            return (*s1 - *s2);
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}
