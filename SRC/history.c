/*
** EPITECH PROJECT, 2026
** 42sh
** File description:
** history management
*/

#include "my.h"

static history_t *create_node(char *line, int index)
{
    history_t *node = malloc(sizeof(history_t));

    if (!node)
        return (NULL);
    node->command = strdup(line);
    node->index = index;
    node->next = NULL;
    return (node);
}

void add_to_history(history_t **history, char *line)
{
    static int idx = 1;
    history_t *tmp = *history;
    history_t *new_node;

    if (!line || line[0] == '\0' || line[0] == '\n')
        return;
    new_node = create_node(line, idx);
    idx++;
    if (!new_node)
        return;
    if (*history == NULL) {
        *history = new_node;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new_node;
}

int builtin_history(history_t *history, char **args)
{
    history_t *tmp = history;

    (void)args;
    while (tmp != NULL) {
        printf("%d\t%s", tmp->index, tmp->command);
        if (tmp->command[strlen(tmp->command) - 1] != '\n')
            printf("\n");
        tmp = tmp->next;
    }
    return (0);
}

void free_history(history_t *history)
{
    history_t *tmp;

    while (history != NULL) {
        tmp = history;
        history = history->next;
        free(tmp->command);
        free(tmp);
    }
}
