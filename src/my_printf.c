/*
** EPITECH PROJECT, 2025
** mini_printf.c
** File description:
** MINI_PRINTF
*/

#include <unistd.h>
#include <stdarg.h>
#include "../include/my.h"

void my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar(45);
        nb = -nb;
    }
    if (nb < 10) {
        my_putchar(nb + '0');
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + '0');
    }
}

int my_printf(const char *format, ...)
{
    va_list list;
    int i = 0;

    va_start(list, format);
    for (; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] == '%')
            my_putchar('%');
        if (format[i] == '%' && (format[i + 1] == 'i' || format[i + 1] == 'd'))
            my_put_nbr(va_arg(list, int));
        if (format[i] == '%' && format[i + 1] == 'c')
            my_putchar(va_arg(list, int));
        if (format[i] == '%' && format[i + 1] == 's')
            my_putstr(va_arg(list, char *));
        if (format[i] == '%')
            i += 1;
        else
            my_putchar(format[i]);
    }
    va_end(list);
    return i;
}
