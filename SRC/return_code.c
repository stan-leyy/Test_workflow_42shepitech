/*
** EPITECH PROJECT, 2025
** expand_special_vars.c
** File description:
** expansion des variables speciales comme $?
*/

#include "my.h"

void detected_signe(char *line, display_code_of_return_t *a)
{
    if (line[a->i] == '$' && line[a->i + 1] == '?') {
        a->k = 0;
        while (a->code_str[a->k] != '\0') {
            a->buffer[a->j] = a->code_str[a->k];
            a->j++;
            a->k++;
        }
        a->i += 2;
    } else {
        a->buffer[a->j] = line[a->i];
        a->i++;
        a->j++;
    }
}

char *display_code_of_return(char *line, int code)
{
    display_code_of_return_t a = {0, 0, 0, {0}, malloc(sizeof(char) *
            (my_strlen(line) + 12))};

    change_int_in_string(code, a.code_str);
    while (line[a.i] != '\0') {
        detected_signe(line, &a);
    }
    a.buffer[a.j] = '\0';
    return a.buffer;
}
