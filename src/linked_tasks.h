#ifndef LINKED_TASK_H
#define LINKED_TASK_H

#include "task.h"

struct tasks_list
{
    struct task *next;
    struct task *prev;
};

void push_back(struct tasks_list *head, char *name, char *description);
void pop_back(struct tasks_list *head);
int get_size(struct tasks_list *head);

#endif // end of linked_task.h
