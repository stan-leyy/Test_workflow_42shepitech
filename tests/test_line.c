/*
** EPITECH PROJECT, 2026
** test_line.c
** File description:
** test create line
*/

#include "../include/my.h"
#include <criterion/criterion.h>
#include <string.h>

char *create_line(char *name, char *value);

Test(env, create_line_basic)
{
    char *line = create_line("PATH", "/bin");

    cr_assert_str_eq(line, "PATH=/bin");
    free(line);
}

Test(env, create_empty_line)
{
    char *line = create_line("TEST", "");

    cr_assert_str_eq(line, "TEST=");
}
