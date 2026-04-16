/*
** EPITECH PROJECT, 2025
** my_strcat
** File description:
** STRCAT
*/
#include "../include/my.h"
#include <unistd.h>

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0') {
        i++;
    }
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}
