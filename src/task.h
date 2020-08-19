#ifndef TASK_H
#define TASK_H

#include <time.h>

struct task
{
    // Max 70 character
    char *name;
    // Max 500 character
    char *description;

    struct tm deadline;
};

void list_tasks();

#endif // end of task.h
