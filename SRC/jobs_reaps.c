/*
** EPITECH PROJECT, 2026
** jobs_reaps.c
** File description:
** check and reap finished jobs
*/

#include "my.h"

static void reap_one_job(principal_function_t *a, int i)
{
    int status = 0;
    pid_t result = 0;

    result = waitpid(a->jobs[i].pid, &status, WNOHANG);
    if (result <= 0)
        return;
    if (WIFEXITED(status) || WIFSIGNALED(status)) {
        printf("[%d]    Done \t\t\t\t%s\n",
            a->jobs[i].id, a->jobs[i].cmd);
        a->jobs[i].state = DONE;
    }
}

void reap_finished_jobs(principal_function_t *a)
{
    int i = 0;

    while (i < a->job_count) {
        if (a->jobs[i].state == RUNNING)
            reap_one_job(a, i);
        i++;
    }
}
