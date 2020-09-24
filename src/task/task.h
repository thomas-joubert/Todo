#ifndef TASK_H
#define TASK_H

#include <time.h>

#include "linked_tasks.h"

struct tasks_list;

struct task
{
    int id;
    // Max 70 character
    char *name;
    // Max 500 character
    char *description;
};

void list_tasks(struct tasks_list *head);
void print_tasks(struct tasks_list *head);

#endif // end of task.h
