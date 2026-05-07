/*
** EPITECH PROJECT, 2026
** 42sh
** File description:
** alias management
*/

#include "my.h"

alias_t *find_alias(alias_t *list, char *name)
{
    alias_t *tmp = list;

    while (tmp != NULL) {
        if (my_strcmp(tmp->name, name) == 0)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

void set_alias(alias_t **list, char *name, char *value)
{
    alias_t *existing = find_alias(*list, name);
    alias_t *new = NULL;

    if (existing) {
        free(existing->value);
        existing->value = my_strdup(value);
    } else {
        new = malloc(sizeof(alias_t));
        if (!new)
            return;
        new->name = my_strdup(name);
        new->value = my_strdup(value);
        new->next = *list;
        *list = new;
    }
}

static char *get_first_word(char *str)
{
    int i = 0;
    char *res = NULL;

    while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
        i++;
    res = malloc(sizeof(char) * (i + 1));
    if (!res)
        return (NULL);
    for (int j = 0; j < i; j++)
        res[j] = str[j];
    res[i] = '\0';
    return (res);
}

static char *loop_aliases(alias_t *list, char *curr)
{
    alias_t *found;
    int safety = 0;

    while (safety < 15) {
        found = find_alias(list, curr);
        if (!found)
            break;
        free(curr);
        curr = my_strdup(found->value);
        safety++;
    }
    return (curr);
}

char *process_aliases(alias_t *list, char *raw_line)
{
    char *first = get_first_word(raw_line);
    char *rest = raw_line + my_strlen(first);
    char *curr = loop_aliases(list, first);
    char *new_line;

    new_line = malloc(my_strlen(curr) + my_strlen(rest) + 1);
    if (!new_line)
        return (my_strdup(raw_line));
    my_strcpy(new_line, curr);
    my_strcat(new_line, rest);
    free(curr);
    return (new_line);
}
