/*
** EPITECH PROJECT, 2025
** my_putstr
** File description:
** PUTSTR
*/
#include "../include/my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return i;
}
