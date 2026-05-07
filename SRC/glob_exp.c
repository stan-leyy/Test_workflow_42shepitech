/*
** EPITECH PROJECT, 2026
** project
** File description:
** description
*/

#include "my.h"

static int is_hidden(char const *name, char const *pat)
{
    return name[0] == '.' && pat[0] != '.';
}

static int count_matches(DIR *dir, char const *pat)
{
    struct dirent *entry = readdir(dir);
    int nb = 0;

    while (entry != NULL) {
        if (!is_hidden(entry->d_name, pat) && match_pattern(pat, entry->d_name))
            nb++;
        entry = readdir(dir);
    }
    rewinddir(dir);
    return nb;
}

static char **collect_matches(DIR *dir, char const *pat, int nb)
{
    struct dirent *entry = readdir(dir);
    char **list = malloc(sizeof(char *) * (nb + 1));
    int i = 0;

    if (!list)
        return NULL;
    while (entry != NULL && i < nb) {
        if (!is_hidden(entry->d_name, pat) &&
            match_pattern(pat, entry->d_name)) {
            list[i] = strdup(entry->d_name);
            i++;
        }
        entry = readdir(dir);
    }
    list[i] = NULL;
    return list;
}

char **expand_glob(char *pat)
{
    DIR *dir = opendir(".");
    char **list = NULL;
    int nb = 0;

    if (!dir || !is_glob_pattern(pat)) {
        if (dir)
            closedir(dir);
        return NULL;
    }
    nb = count_matches(dir, pat);
    if (nb > 0)
        list = collect_matches(dir, pat, nb);
    closedir(dir);
    return list;
}
