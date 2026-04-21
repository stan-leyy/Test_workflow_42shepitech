/*
** EPITECH PROJECT, 2025
** my_strdup.c
** File description:
** my_strdup.c
*/

#include <stdlib.h>
#include "../my.h"

char *my_strdup(char *src)
{
    int i = 0;
    char *c = malloc(sizeof(char) * my_strlen(src) + 1);

    while (src[i] != '\0') {
        c[i] = src[i];
        i++;
    }
    c[i] = '\0';
    return c;
}
