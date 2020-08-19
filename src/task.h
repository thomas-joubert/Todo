#ifndef TASK_H
#define TASK_H

#include <time.h>

struct task
{
    char *name;
    char *description;

    struct tm deadline;
}

void list_tasks();

#endif // end of task.h
