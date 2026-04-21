/*
** EPITECH PROJECT, 2025
** principale_fonction
** File description:
** main
*/

#include "my.h"

int copy_string(char *src, char *dest)
{
    int i = 0;
    int j = 0;
    
    while (src[i] != '0' && src[i] != '/') {
        dest[j] = src[i];
        i++;
        j++;
    }
    if (src[i] == '/')
        i++;
    return i;
}

char *handle_inhibitor(char *line)
{
    int i = 0;
    int j= 0;
    char *buffer = malloc(sizeof(char) * strlen(line) + 1);

    while(line[i] != '\0') {
        if (line[i] == '/')
            i = copy_string(line, buffer);
        else {
            buffer[i] = line[i];
            i++;
            j++;
        }
    }
    buffer[i] = '\0';
    return buffer;
}