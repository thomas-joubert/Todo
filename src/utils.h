#ifndef DEF_UTILS
#define DEF_UTILS

#include <stdio.h>

void help(void)
{
    puts("USAGE : ./todo <options>\n
            no options : show the task list\n
            -a / --add <task> : create a new task\n
            -d / --delete <task or number> : delete a task\n
            -h / --help : show this message");
}

#endif
