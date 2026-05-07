/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** Pattern matching for glob wildcards: *, ?, [...]
*/

#include "my.h"

static int match_range(char const *pat, char c)
{
    return c >= pat[0] && c <= pat[2];
}

static int check_bracket(char const *pat, char c)
{
    int neg = (*pat == '!');
    int found = 0;

    if (neg)
        pat++;
    while (*pat && *pat != ']') {
        if (pat[1] == '-' && pat[2] != ']') {
            found = found || match_range(pat, c);
            pat += 3;
        } else {
            found = found || (*pat == c);
            pat++;
        }
    }
    return neg ? !found : found;
}

static int skip_bracket(char const *pat)
{
    int i = 1;

    if (pat[i] == '!')
        i++;
    while (pat[i] && pat[i] != ']')
        i++;
    return (pat[i] == ']') ? i : -1;
}

int match_pattern(char const *pat, char const *name)
{
    int end = skip_bracket(pat);

    if (*pat == '\0')
        return *name == '\0';
    if (*pat == '*')
        return match_pattern(pat + 1, name)
            || (*name && match_pattern(pat, name + 1));
    if (*pat == '?' && *name)
        return match_pattern(pat + 1, name + 1);
    if (*pat == '[' && end > 0 && *name)
        return check_bracket(pat + 1, *name)
            && match_pattern(pat + end + 1, name + 1);
    if (*pat == *name)
        return match_pattern(pat + 1, name + 1);
    return 0;
}

int is_glob_pattern(char const *str)
{
    while (*str) {
        if (*str == '*' || *str == '?' || *str == '[')
            return 1;
        str++;
    }
    return 0;
}
