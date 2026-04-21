/*
** EPITECH PROJECT, 2025
** my_put_nbr
** File description:
** my_put_nbr
*/

#include <unistd.h>
#include "../my.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        nb = -nb;
    } else if (nb >= 10) {
        my_put_nbr(nb / 10);
    }
    my_putchar((nb % 10) + '0');
    return 0;
}
