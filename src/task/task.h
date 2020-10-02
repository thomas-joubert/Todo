#ifndef TASK_H
#define TASK_H

#include <time.h>

#include "../linked_tasks.h"
#include "../utils.h"

struct tasks_list;

void list_tasks(struct tasks_list *head);
void print_tasks(struct tasks_list *head);

#endif // end of task.h
