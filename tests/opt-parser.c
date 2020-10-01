#include <criterion/criterion.h>

#include "../src/utils.h"

Test(option, false_option)
{
    int argc = 2;
    char *argv[2] = {"todo", "-g"};

    struct single_option *opt = option_parser(argc, argv);

    cr_assert(opt->arg == NULL,
            "Expected opt->arg to be NULL, opt->arg == %s\n", opt->arg);
    cr_assert(opt->opt_type == HELP,
            "Expected opt->opt_type to be of type HELP\n");
}

Test(option, help)
{
    int argc = 2;
    char *argv[2] = {"todo", "-h"};

    struct single_option *opt = option_parser(argc, argv);

    cr_assert(opt->arg == NULL,
            "Expected opt->arg to be NULL, opt->arg == %s\n", opt->arg);
    cr_assert(opt->opt_type == HELP,
            "Expected opt->opt_type to be of type HELP\n");
}

Test(option, add)
{
    int argc = 3;
    char *argv[3] = {"todo", "-a", "Hello"};

    struct single_option *opt = option_parser(argc, argv);

    cr_assert(strcmp(opt->arg, "Hello") == 0,
            "Expected opt->arg to be \"Hello\", opt->arg == %s\n", opt->arg);
    cr_assert(opt->opt_type == ADD,
            "Expected opt->opt_type to be of type ADD\n");
}

Test(option, delete)
{
    int argc = 3;
    char *argv[3] = {"todo", "-d", "Hello"};

    struct single_option *opt = option_parser(argc, argv);

    cr_assert(strcmp(opt->arg, "Hello") == 0,
            "Expected opt->arg to be \"Hello\", opt->arg == %s\n", opt->arg);
    cr_assert(opt->opt_type == DELETE,
            "Expected opt->opt_type to be of type DELETE\n");
}

Test(option, add_no_arg)
{
    int argc = 2;
    char *argv[2] = {"todo", "-a"};

    struct single_option *opt = option_parser(argc, argv);

    cr_assert(opt->arg == NULL,
            "Expected opt->arg to be NULL, opt->arg == %s\n", opt->arg);
    cr_assert(opt->opt_type == HELP,
            "Expected opt->opt_type to be of type HELP\n");
}

Test(option, delete_no_arg)
{
    int argc = 2;
    char *argv[2] = {"todo", "-d"};

    struct single_option *opt = option_parser(argc, argv);

    cr_assert(opt->arg == NULL,
            "Expected opt->arg to be NULL, opt->arg == %s\n", opt->arg);
    cr_assert(opt->opt_type == HELP,
            "Expected opt->opt_type to be of type HELP\n");
}

Test(option, help_with_opt)
{
    int argc = 3;
    char *argv[3] = {"todo", "-h", "Hello"};

    struct single_option *opt = option_parser(argc, argv);

    cr_assert(opt->arg == NULL,
            "Expected opt->arg to be NULL, opt->arg == %s\n", opt->arg);
    cr_assert(opt->opt_type == HELP,
            "Expected opt->opt_type to be of type HELP\n");
}
