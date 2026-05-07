/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** backtick expansion and glob expansion on argv
*/

#include "my.h"

int is_backtick(char const *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] == '`')
            return 1;
        i++;
    }
    return 0;
}

static char *read_output(int fd)
{
    char *buf = malloc(4096);
    int len = 0;
    int n = 1;

    if (!buf)
        return NULL;
    while (n > 0) {
        n = read(fd, buf + len, 4095 - len);
        if (n > 0)
            len += n;
    }
    if (len > 0 && buf[len - 1] == '\n')
        len--;
    buf[len] = '\0';
    return buf;
}

static char *get_cmd(char *str, int *skip)
{
    int i = 0;
    int j = 0;
    char *cmd = NULL;

    while (str[i] != '`')
        i++;
    i++;
    while (str[i + j] && str[i + j] != '`')
        j++;
    *skip = i + j + 1;
    cmd = malloc(j + 1);
    if (!cmd)
        return NULL;
    while (j > 0) {
        cmd[j - 1] = str[i + j - 1];
        j--;
    }
    cmd[*skip - i - 1] = '\0';
    return cmd;
}

static char *run_cmd(char *cmd)
{
    int fds[2];
    pid_t pid;
    char *out = NULL;

    if (pipe(fds) == -1)
        return NULL;
    pid = fork();
    if (pid == 0) {
        close(fds[0]);
        dup2(fds[1], 1);
        close(fds[1]);
        execl("/bin/sh", "sh", "-c", cmd, NULL);
        exit(1);
    }
    close(fds[1]);
    out = read_output(fds[0]);
    close(fds[0]);
    waitpid(pid, NULL, 0);
    return out;
}

char *expand_backtick(char *str)
{
    int skip = 0;
    char *cmd = get_cmd(str, &skip);
    char *out = NULL;

    if (!cmd)
        return str;
    out = run_cmd(cmd);
    free(cmd);
    if (!out)
        return str;
    return out;
}

static int count_expanded(char **buffer)
{
    char **expanded = NULL;
    int total = 0;
    int i = 0;
    int j = 0;

    while (buffer[i]) {
        expanded = expand_glob(buffer[i]);
        if (!expanded) {
            total++;
            i++;
            continue;
        }
        j = 0;
        while (expanded[j])
            j++;
        total += j;
        i++;
    }
    return total;
}

static void fill_new_buf(char **new_buf, char **expanded, int *k)
{
    int j = 0;

    while (expanded[j]) {
        new_buf[*k] = expanded[j];
        (*k)++;
        j++;
    }
}

static char **build_new_buffer(char **buffer, char **new_buffer, int total)
{
    char **expanded = NULL;
    int k = 0;
    int i = 0;

    while (buffer[i]) {
        expanded = expand_glob(buffer[i]);
        if (expanded) {
            fill_new_buf(new_buffer, expanded, &k);
            i++;
            continue;
        }
        new_buffer[k] = buffer[i];
        k++;
        i++;
    }
    new_buffer[k] = NULL;
    return new_buffer;
}

char **apply_glob_expansion(char **buffer)
{
    char **new_buffer = NULL;
    int total = count_expanded(buffer);

    new_buffer = malloc(sizeof(char *) * (total + 1));
    if (!new_buffer)
        return buffer;
    return build_new_buffer(buffer, new_buffer, total);
}
