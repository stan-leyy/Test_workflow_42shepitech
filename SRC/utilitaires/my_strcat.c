/*
** EPITECH PROJECT, 2025
** strcat
** File description:
** contact character
*/

#include "../my.h"

char *my_strcat(char *dest, char *src)
{
    int j = 0;
    int i = 0;

    for (j = 0; dest[j] != '\0'; j++);
    while (src[i] != '\0'){
        dest[j] = src[i];
        i++;
        j++;
    }
    dest[j] = '\0';
    return dest;
}
