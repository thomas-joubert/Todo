#ifndef DEF_UTILS
#define DEF_UTILS

#include <stdio.h>

void help(void);
void option_parser(int argc, char *argv[]);

enum options
{
    HELP = 0,
    ADD,
    DELETE
};

struct option
{
    enum options type;
    char *arg;
};

#endif
