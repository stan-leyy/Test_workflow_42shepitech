/*
** EPITECH PROJECT, 2026
** jobs_utils.c
** File description:
** jobs control utilities
*/

#include "my.h"

int find_free_job_slot(principal_function_t *a)
{
    int i = 0;

    while (i < 64) {
        if ((a->jobs[i].state == DONE) || (a->jobs[i].pid == 0))
            return i;
        i++;
    }
    return -1;
}

int find_job_by_id(principal_function_t *a, int id)
{
    int i = 0;

    while (i < a->job_count) {
        if (a->jobs[i].id == id)
            return i;
        i++;
    }
    return -1;
}

void add_job(principal_function_t *a, pid_t pid, pid_t pgid,
    char *cmd)
{
    int slot = find_free_job_slot(a);

    if (slot == -1)
        return;
    a->jobs[slot].id = a->job_count + 1;
    a->jobs[slot].pid = pid;
    a->jobs[slot].pgid = pgid;
    a->jobs[slot].state = RUNNING;
    a->jobs[slot].cmd = my_strdup(cmd);
    a->job_count++;
    mini_printf("[%d] %d\n", a->jobs[slot].id, pid);
}
