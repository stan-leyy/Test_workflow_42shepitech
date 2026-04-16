/*
** EPITECH PROJECT, 2026
** test_same_var.c
** File description:
** test same var
*/

#include "../include/my.h"
#include <criterion/criterion.h>

int is_same_var(char *env_line, char *name);

Test(env, same_var_ok)
{
    cr_assert(is_same_var("PATH=/bin", "PATH"));
}

Test(env, same_var_fail)
{
    cr_assert_not(is_same_var("PATH=/bin", "HOME"));
}
