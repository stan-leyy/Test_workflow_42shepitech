/*
** EPITECH PROJECT, 2026
** tests.c
** File description:
** tests minishell1
*/

#include "../include/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_putchar, display_a_caracter, .init = redirect_all_std)
{
    my_putchar('A');
    cr_assert_stdout_eq_str("A");
}

Test(my_putstr, display_a_string, .init = redirect_all_std)
{
    my_putstr("Bryan goat");
    cr_assert_stdout_eq_str("Bryan goat");
}

Test(my_strlen, count_a_caracter, .init = redirect_all_std)
{
    cr_assert(my_strlen("HELLO") == 5);
}

Test(my_strcmp, compare_a_string, .init = redirect_all_std)
{
    cr_assert(my_strcmp("HELLO", "HELLO") == 0);
}
