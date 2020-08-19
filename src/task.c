#include <stdio.h>

#include "task.h"
#include "linked_task.h"

void list_tasks(struct tasks_list *head)
{
    int start = 0;

    FILE *tasks = fopen("~/home/todo-list/tasks.csv", "r");
    if (tasks == NULL)
    {
        fprintf(stderr, "Error during file opening\n");
        exit(4)
    }

    char *line = calloc(sizeof(char), 570);
    if (!line)
    {
        fprintf(stderr, "Calloc failed\n");
        exit(4);
    }

    // Read the whole file line by line
    while (getline(&line, 570, tasks) != -1)
    {
        // FIXME : Check the number of char when taking the input
        char name[51];
        char description[501];

        if (!start)
        {
            start++;
            continue;
        }

        name = strtok(line, ';');
        description = strtok(NULL, ';');
    }
}
