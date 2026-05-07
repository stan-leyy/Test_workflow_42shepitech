/*
** EPITECH PROJECT, 2025
** principale_fonction
** File description:
** main
*/

#include "my.h"

char *my_own_getenv_by_name(char **env, char *name)
{
    int i = 0;
    int len = my_strlen(name);

    while (env[i] != NULL) {
        if (my_strncmp(env[i], name, len) == 0 && env[i][len] == '=')
            return env[i] + len + 1;
        i++;
    }
    return NULL;
}

int read_quote(char *src, char *dest, int *j, char **env)
{
    char var_name[256];
    int k = 0;
    char *val = NULL;

    while (src[k] != '\0' && src[k] != '"') {
        var_name[k] = src[k];
        k++;
    }
    var_name[k] = '\0';
    val = my_own_getenv_by_name(env, var_name);
    if (val) {
        while (*val) {
            dest[*j] = *val;
            (*j)++;
            val++;
        }
    }
    return k;
}

int handle_dollar(char *src, char *dest, int *j, char **env)
{
    if (src[0] == '\\' && src[1] == '$') {
        dest[*j] = '$';
        (*j)++;
        return 2;
    }
    if (src[0] == '$' && src[1] != '\0')
        return 1 + read_quote(&src[1], dest, j, env);
    dest[*j] = src[0];
    (*j)++;
    return 1;
}

int copy_string_double_quote(char *src, char *dest, int *j, char **env)
{
    int i = 1;
    char quote = src[0];

    while (src[i] != '\0' && src[i] != quote) {
        i += handle_dollar(&src[i], dest, j, env);
    }
    if (src[i] == quote)
        i++;
    return i;
}

char *handle_inhibitor_double_quote(char *line, char **env)
{
    int i = 0;
    int j= 0;
    char *buffer = malloc(sizeof(char) * strlen(line) + 1);

    while (line[i] != '\0') {
        if (line[i] == '\"')
            i += copy_string_double_quote(&line[i], buffer, &j, env);
        else {
            buffer[j] = line[i];
            i++;
            j++;
        }
    }
    buffer[j] = '\0';
    return buffer;
}
