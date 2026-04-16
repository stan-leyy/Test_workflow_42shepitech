/*
** EPITECH PROJECT, 2026
** test_env.c
** File description:
** tests env
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

int env_len(char **env);


Test(env, env_len_basic)
{
    char *env[] = {"PATH=/bin", "HOME=/home", NULL};

    cr_assert_eq(env_len(env), 2);
}

Test(env, env_len_empty)
{
    char *env[] = {NULL};

    cr_assert_eq(env_len(env), 0);
}
