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

Test(my_strcmp, check_compare_return_erreur)
{
    int i = my_strcmp("papa", "pap");
    cr_assert_eq(i, 1);
}

Test(my_strncmp, check_compare_in_function_index)
{
    int n = my_strncmp("abc", "abc", 3);
    cr_assert_eq(n, 0);
}

Test(my_strncmp, check_compare_in_function_index_error)
{
    int n = my_strncmp("abc", "anc", 2);
    cr_assert_neq(n, 0);
}

Test(my_strncmp, check_compare_in_function_error)
{
    int n = my_strncmp("abc", "abc", 2);
    cr_assert_eq(n, 0);
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

Test(cheker, check_null_strtok, .init = cr_redirect_stderr)
{
    char str[] = "stanley";
    char *line = checker(str);
    cr_assert_str_neq("NULL", line);
}

Test(stock, parse_in_fonction_semicolon)
{
    char str[] = "Stanley;Kurtis";
    char **line = parse_in_fonction_semicolon(str);
    cr_assert_str_eq("Stanley", line[0]);
    cr_assert_str_eq("Kurtis", line[1]);
}

Test(stock, parse_in_fonction_semicolon_error)
{
    char str[] = "Stanley;Kurtis";
    char **line = parse_in_fonction_semicolon(str);
    cr_assert_str_eq("Stanley", line[0]);
    cr_assert_str_neq("kurtis", line[1]);
}

Test(strcat, my_strcat)
{
    char line[10] = "";
    my_strcat(line, "papa");
    cr_assert_str_eq(line, "papa");
}

Test(strcat, my_strcat_error)
{
    char line[10] = "";
    my_strcat(line, "papa");
    cr_assert_str_neq(line, "pap");
}

Test(such_first_inhibitor, check_index)
{
    char line[20] = "echo 'Bryan'";
    int i = such_slach(line);
    cr_assert_eq(i, 0);
}

Test(dear_and, check_index_and)
{
    char line[20] = "stanley&&maman";
    int i = dear_and(line);
    cr_assert_eq(i, 1);
}

Test(dear_and, check_index_and_absent)
{
    char line[20] = "stanley maman";
    int i = dear_and(line);
    cr_assert_eq(i, 0);
}

Test(parse_and, check_element_double_array)
{
    char *line = "ls && ls -l && cat Makefile";
    char **buffer = parse_and(line);
    cr_assert_str_eq(buffer[0], "ls");
    cr_assert_str_eq(buffer[1], "ls -l");
    cr_assert_str_eq(buffer[2], "cat Makefile");
}

Test(parse_and, check_element_double_array_error)
{
    char *line = "ls && ls -l && cat Makefile";
    char **buffer = parse_and(line);
    cr_assert_str_neq(buffer[2], "ls");
    cr_assert_str_neq(buffer[0], "ls -l");
    cr_assert_str_neq(buffer[1], "cat Makefile");
}

Test(such_slach, check_slach_string)
{
    char *line = "touch\\ file";
    int i = such_slach(line);
    cr_assert_eq(i, 1);
}

Test(such_slach, check_slach_without_string)
{
    char *line = "touch file";
    int i = such_slach(line);
    cr_assert_eq(i, 0);
}

Test(such_slach, check_slach_error_string)
{
    char *line = "touch\\ file";
    int i = such_slach(line);
    cr_assert_neq(i, 0);
}

Test(such_slach, check_slach_without_error_string)
{
    char *line = "touch file";
    int i = such_slach(line);
    cr_assert_neq(i, 1);
}

Test(such_inhibitor_simple_quote, check_inhibitor_quote)
{
    char *line = "echo '$HOME'";
    int i = such_inhibitor_simple_quote(line);
    cr_assert_eq(i, 1);
}

Test(such_inhibitor_simple_quote, check_inhibitor_quote_error)
{
    char *line = "echo *$HOME*";
    int i = such_inhibitor_simple_quote(line);
    cr_assert_neq(i, 1);
}

Test(such_inhibitor_simple_quote, check_inhibitor_quote_witchout_quote)
{
    char *line = "echo *$HOME*";
    int i = such_inhibitor_simple_quote(line);
    cr_assert_eq(i, 0);
}

Test(such_inhibitor_simple_quote, check_inhibitor_quote_witchout_quote_and_error)
{
    char *line = "echo '$HOME'";
    int i = such_inhibitor_simple_quote(line);
    cr_assert_neq(i, 0);
}

Test(such_inhibitor_double_quote, chech_inhibitor_double)
{
    char line[] = "echo \"azerty\"";
    int i = such_inhibitor_double_quote(line);
    cr_assert_eq(i, 1);
}

Test(such_inhibitor_double_quote, chech_inhibitor_double_error)
{
    char line[] = "echo \"azerty\"";
    int i = such_inhibitor_double_quote(line);
    cr_assert_neq(i, 5);
}

Test(such_inhibitor_double_quote, chech_inhibitor_double_witchout_quote)
{
    char line[] = "echo *azerty*";
    int i = such_inhibitor_double_quote(line);
    cr_assert_eq(i, 0);
}

Test(such_inhibitor_double_quote, chech_inhibitor_double_witchout_quote_index_error)
{
    char line[] = "echo *azerty*";
    int i = such_inhibitor_double_quote(line);
    cr_assert_eq(i, 0);
}

Test(such_inhibitor_double_quote, chech_inhibitor_double_witchout_quote_error)
{
    char line[] = "echo *azerty*";
    int i = such_inhibitor_double_quote(line);
    cr_assert_neq(i, 5);
}

Test(get_after_or, after_or)
{
    char *line = "ls || ls -l";
    char *buffer = get_after_or(line);
   cr_assert_str_eq(buffer, " ls -l");
}

Test(get_after_or, after_or_error_case)
{
    char *line = "ls || ls -l";
    char *buffer = get_after_or(line);
    cr_assert_str_neq(buffer, "ls -l");
}

Test(get_before_or, before_or)
{
    char *line = "cat Makefile || ls -a";
    char *buffer = get_before_or(line);
    cr_assert_str_eq(buffer, "cat Makefile");
}

Test(get_before_or, before_or_error)
{
    char *line = "cat Makefile || ls -a";
    char *buffer = get_before_or(line);
    cr_assert_str_neq(buffer, "catMakefile");
}

