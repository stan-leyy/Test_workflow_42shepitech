/*
** EPITECH PROJECT, 2026
** test_get_var.c
** File description:
** test get_var
*/

#include "../include/my.h"
#include <criterion/criterion.h>

char *get_var(char **env, char *name);

Test(env, get_var_found)
{
    char *env[] = {"PATH=/bin", NULL};
    char *val = get_var(env, "PATH");

    cr_assert_str_eq(val, "/bin");
}

Test(env, get_var_not_found)
{
    char *env[] = {"PATH=/bin", NULL};
    char *val = get_var(env, "HOME");

    cr_assert_null(val);
}
