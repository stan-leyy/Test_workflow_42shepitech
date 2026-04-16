/*
** EPITECH PROJECT, 2026
** my_strdup.c
** File description:
** my strdup
*/

#include "../include/my.h"

int my_size(char const *str)
{
    int j = 0;

    while (str[j] != '\0')
        j++;
    return j;
}

char *my_strdup(char const *src)
{
    int i = 0;
    char *abd;

    abd = malloc(sizeof(char) * (my_size(src) + 1));
    if (!abd) {
        return NULL;
    }
    while (src[i] != '\0') {
        abd[i] = src[i];
        i++;
    }
    abd[i] = '\0';
    return abd;
}
