#include <criterion/criterion.h>

#include "../src/utils.h"

void help_dummy(void)
{
    return;
}

Test(option, false_option)
{
    int argc = 2;
    char *argv[2] = {"todo", "-g"};

    struct single_option *opt = option_parser(argc, argv);

    cr_assert(opt->arg == NULL, "Expected opt->arg to be NULL, opt->arg == %s\n", opt->arg);
    cr_assert(opt->opt_type == HELP,
            "Expected opt->opt_type to be of type HELP\n");
}
