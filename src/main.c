#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

#include "task/task.h"
#include "linked_tasks.h"
#include "utils.h"
#include "writing.h"

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        struct tasks_list *head = calloc(sizeof(struct tasks_list), 1);
        list_tasks(head);
        print_tasks(head);
    }


    if (!head)
        err(-3, "Calloc failed\n");

    struct single_option *opt = NULL;
    int writing_result = 0;

    FILE *file = fopen("/home/thomas/.todo-list/tasks.csv", "w+");
    if (!file)
        err(-2, "Error during file opening");

    opt = option_parser(argc, argv);

    switch (opt->opt_type)
    {
        case HELP:
            free(opt);
            free(head);
            return 1;

        case ADD:
            writing_result = csv_writer(opt, file);
            if (writing_result == -1)
                fprintf(stderr, "Creation failed\n");
            break;

        case DELETE:
            printf("FIXME : delete a task\n");
            break;
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
