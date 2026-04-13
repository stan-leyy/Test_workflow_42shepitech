/*
** EPITECH PROJECT, 2025
** mini
** File description:
** mini
*/

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "../my.h"

void mini(const char *format, va_list aff, int i)
{
    if (format[i] == 'd' || format[i] == 'i')
        my_put_nbr(va_arg(aff, int));
    if (format[i] == 'c')
        my_putchar(va_arg(aff, int));
    if (format[i] == 's')
        my_putstr(va_arg(aff, char*));
    if (format[i] == '%')
        my_putchar('%');
}

int mini_printf(const char *format, ...)
{
    int i;
    va_list aff;

    va_start(aff, format);
    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            mini(format, aff, i);
        } else {
            my_putchar(format[i]);
        }
    }
    va_end(aff);
    return 0;
}
