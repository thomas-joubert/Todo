#include <err.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

#include "utils.h"

void help(void)
{
    puts("USAGE : ./todo <options>");
    puts("\tno options : show the task list");
    puts("\t-a / --add <task> : create a new task");
    puts("\t-d / --delete <task or number> : delete a task");
    puts("\t-h / --help : show this message");
}

struct single_option *option_parser(int argc, char *argv[])
{
    struct single_option *opt = calloc(1, sizeof(struct single_option));
    if (!opt)
        err(EXIT_FAILURE, "Malloc failed");

    int option = getopt(argc, argv, "a:d:h");

    if (option == -1)
    {
        opt->opt_type = HELP;
        help();
    }
    else
    {
        switch(option)
        {
            case 'a':
                opt->opt_type = ADD;
                opt->arg = strdup(optarg);
                break;
            case 'h':
                help();
                opt->opt_type = HELP;
                break;
            case 'd':
                opt->opt_type = DELETE;
                opt->arg = strdup(optarg);
                break;
            default :
                opt->opt_type = HELP;
                help();
        }
    }

    return opt;
}
