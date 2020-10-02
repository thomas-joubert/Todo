#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

#include "task/task.h"
#include "linked_tasks.h"
#include "utils.h"

int main(int argc, char *argv[])
{
    struct tasks_list *head = calloc(sizeof(struct tasks_list), 1);

    if (!head)
        err(-3, "Calloc failed\n");

    struct single_option *opt = NULL;

    FILE *file = fopen("/home/thomas/.todo-list/tasks.csv", "w+");
    if (!file)
        err(-2, "Error during file opening");

    if (argc == 1)
    {
        list_tasks(head);
        print_tasks(head);
    }
    else
    {
        opt = option_parser(argc, argv);
        if (opt->opt_type == HELP)
        {
            free(opt);
            free(head);
            return 1;
        }
    }

    // If the binary is used without options, no need to free
    if (opt)
    {
        free(opt->arg);
        free(opt);
    }

    free(head);

    return 0;
}
