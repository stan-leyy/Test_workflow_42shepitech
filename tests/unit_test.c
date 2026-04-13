/*
** EPITECH PROJECT, 2025
** test
** File description:
** unit_tests
*/

#include "../SRC/my.h"
#include "criterion/criterion.h"
#include "criterion/redirect.h"

Test(my_strcmp, check_compare)
{
    int i = my_strcmp("papa", "papa");
    cr_assert_eq(i, 0);
}

Test(my_strcmp, check_compare_erreur)
{
    int i = my_strcmp("papa", "pap");
    cr_assert_neq(i, 0);
}

Test(output, put_nbr, .init = cr_redirect_stdout)
{
    my_put_nbr(4125);
    cr_assert_stdout_eq_str("4125");
}

Test(output, putchar, .init = cr_redirect_stdout)
{
    my_putchar('c');
    cr_assert_stdout_eq_str("c");
}

Test(output, putstr, .init = cr_redirect_stdout)
{
    my_putstr("je vais a l'ecole avec ma mere");
    cr_assert_stdout_eq_str("je vais a l'ecole avec ma mere");
}

Test(my_strdup, copy)
{
    char *line = my_strdup("corriger");
    cr_assert_str_eq(line, "corriger");
}

Test(my_strdup, copy_error)
{
    char *line = my_strdup("corriger");
    cr_assert_str_neq(line, "corriger ma feuille");
}

Test(my_strlen, string_size)
{
    int size = my_strlen("maman");
    cr_assert_eq(size, 5);
}

Test(my_strlen, string_size_error)
{
    int size = my_strlen("ma-man");
    cr_assert_neq(size, 5);
}

Test(cheker, delete_space_or_tab)
{
    char str[] = " stanley";
    char *line = checker(str);
    cr_assert_str_eq("stanley", line);
}

Test(cheker, delete_space_or_tab_error)
{
    char str[] = " stanley";
    char *line = checker(str);
    cr_assert_str_neq("stanley ohhh", line);
}




