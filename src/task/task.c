#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"

void list_tasks(struct tasks_list *head)
{
    int start = 0;

    if (!head)
        return;

    FILE *tasks = fopen("/home/thomas/.todo-list/tasks.csv", "r");
    if (tasks == NULL)
    {
        fprintf(stderr, "Error during file opening\n");
        exit(4);
    }

    char *line = calloc(sizeof(char), 570);
    if (!line)
    {
        fprintf(stderr, "Calloc failed\n");
        exit(4);
    }

    size_t size_max = 570;

    // Read the whole file line by line
    while (getline(&line, &size_max, tasks) != -1)
    {
        if (!start)
            start++;
        else
        {
            int id = atoi(strtok(line, ";"));
            char *name = strtok(NULL, ";");
            char *description = strtok(NULL, ";");

            printf("%d\n%s\n%s\n", id, name, description);
        }
    }
}

void print_tasks(struct tasks_list *head)
{
    if (!head)
        return;
}
