#include "linked_tasks.h"

void push_back(struct tasks_list *head, char *name, char *description)
{
   if (!head || !name || !description) 
       return;
}

void pop_back(struct tasks_list *head)
{
    if (!head)
        return;
}

int get_size(struct tasks_list *head)
{
    if (!head)
        return 0;

    return 1;
}
