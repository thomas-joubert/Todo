#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"
#include "linked_tasks.h"

int main(int argc, char *argv[])
{
    struct tasks_list *head = calloc(sizeof(struct tasks_list), 1);
    if (!head)
    {
        fprintf(stderr, "Calloc failed\n");
        exit(4);
    }
    
    if (argc == 1)
    {
        //list_tasks(head)
        puts("fine");
    }
    else
    {
        printf("%d\n", argc);
        printf("%s\n", argv[0]);
        puts("Not fine");
    }

    return 0;
}
