/*
** EPITECH PROJECT, 2026
** test_strncmp.c
** File description:
** test my_strncmp
*/

#include "../include/my.h"
#include <criterion/criterion.h>

int my_strncmp(const char *s1, const char *s2, int n);

Test(utils, strncmp_equal)
{
    cr_assert_eq(my_strncmp("abc", "abc", 3), 0);
}

Test(utils, strncmp_diff)
{
    cr_assert(my_strncmp("abc", "abd", 3) < 0);
}

Test(utils, strncmp_partial)
{
    cr_assert_eq(my_strncmp("abc", "abd", 2), 0);
}
