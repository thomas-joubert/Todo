#ifndef DEF_UTILS
#define DEF_UTILS

#include <stdio.h>

void help(void);
struct single_option * option_parser(int argc, char *argv[]);

enum type
{
    ADD = 0,
    HELP,
    DELETE
};

struct single_option
{
    enum type opt_type;
    char *arg;
};

#endif
