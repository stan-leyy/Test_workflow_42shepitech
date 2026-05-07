/*
** EPITECH PROJECT, 2026
** 42sh
** File description:
** alias execution builtin
*/

#include "my.h"

static char *concat_alias_value(char **args)
{
    int len = 0;
    char *res;

    for (int i = 2; args[i]; i++)
        len += my_strlen(args[i]) + 1;
    res = malloc(sizeof(char) * (len + 1));
    if (!res)
        return (NULL);
    res[0] = '\0';
    for (int i = 2; args[i]; i++) {
        my_strcat(res, args[i]);
        if (args[i + 1])
            my_strcat(res, " ");
    }
    return (res);
}

int exec_alias_builtin(alias_t **list, char **args)
{
    char *value;

    if (args[1] == NULL) {
        for (alias_t *it = *list; it; it = it->next)
            mini_printf("%s\t%s\n", it->name, it->value);
        return (0);
    }
    if (args[1] && args[2]) {
        value = concat_alias_value(args);
        set_alias(list, args[1], value);
        free(value);
        return (0);
    }
    return (1);
}
