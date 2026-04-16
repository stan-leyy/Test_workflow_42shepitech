/*
** EPITECH PROJECT, 2026
** test_full_env.c
** File description:
** tests all env functions
*/

#include "../include/my.h"
#include <criterion/criterion.h>

Test(env, full_flow)
{
    char **env = malloc(sizeof(char *) * 1);

    env[0] = NULL;
    env = my_setenv(env, "A", "1");
    env = my_setenv(env, "B", "2");
    env = my_unsetenv(env, "A");
    cr_assert_eq(env_len(env), 1);
    cr_assert_str_eq(env[0], "B=2");
    free_env(env);
}
