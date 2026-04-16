/*
** EPITECH PROJECT, 2025
** my_strlen
** File description:
** MY_STRLEN
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int j = 0;

    while (str[j] != '\0')
        j++;
    return j;
}
